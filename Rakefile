require 'rake'
require 'rake/clean'

NAME    = 'lolibc'
RELEASE = '0.0.1'

CC = 'clang'
AR = 'ar'

CFLAGS  = '-Wall -Wextra -Winline -Wno-long-long -nostdlib -nodefaultlibs -fno-builtin -finline-functions -I./include'
LDFLAGS = '-s'

CLEAN.include('sources/**/*.o', 'include/features.h')
CLOBBER.include('*.so', '*.a')

SOURCES = FileList['sources/*.c']

case ENV['ARCH']
    when 'x86'
        CFLAGS << ' -D_ARCH_X86'
        ENV['32bit'] = 'true'
    when 'x86_64'
        CFLAGS << ' -D_ARCH_X86_64'
        ENV['64bit'] = 'true'
    else
        ENV['ARCH'] = 'none'
end

SOURCES.include("sources/arch/#{ENV['ARCH']}/**/*.c")

if ENV['ARCH'] != 'none'
    fallbacks = FileList['sources/arch/none/**/*.c']

    SOURCES.each {|file|
        fallbacks.exclude(File.basename(file))
    }

    SOURCES.include(fallbacks)
end

if ENV['32bit']
    CFLAGS << ' -m32'
elsif ENV['64bit']
    CFLAGS << ' -m64'
end

if ENV['OPTIMIZED'] != 'false'
    CFLAGS << ' -Os'
end

if !ENV['PLATFORM']
    ENV['PLATFORM'] = 'Linux'
end

case ENV['PLATFORM']
    when 'Linux'
        CFLAGS << ' -D_PLATFORM_LINUX'
end

SOURCES.include("sources/platform/#{ENV['PLATFORM']}/**/*.c");

OBJECTS = SOURCES.ext('o')

task :default => ["lib#{NAME}.so", "lib#{NAME}.a"]

file 'include/features.h' do
    file = File.new('include/features.h', 'w')

    file.write(%{\
#ifndef _LOLIBC_FEATURES_H
#define _LOLIBC_FEATURES_H

#ifdef __cplusplus
#   define  __BEGIN_NAMESPACE(name) namespace ## name {
#   define  __END_NAMESPACE }
#
#   define PUBLIC extern "C"
#else
#   define __BEGIN_NAMESPACE(name)
#   define __END_NAMESPACE
#
#   define PUBLIC extern
#endif

#endif
})

    file.close
end

rule '.o' => '.c' do |t|
    sh "#{CC} -fPIC #{CFLAGS} -o #{t.name} -c #{t.source}"
end

task :compile => ['include/features.h'].concat(OBJECTS)

file "lib#{NAME}.so" => :compile do
    sh "#{CC} #{LDFLAGS} #{CFLAGS} -shared -Wl,-soname,lib#{NAME}.so -o lib#{NAME}.so #{OBJECTS}"
end

file "lib#{NAME}.a" => :compile do
    sh "#{AR} rcs lib#{NAME}.a #{OBJECTS}"
end

task :test do
    tests = FileList['test/**/*.c']

    tests.each {|test|
        pipe   = IO.popen("#{CC} #{CFLAGS} -L./ -llolibc -o test/test #{test} 2>&1");
        output = pipe.read.chomp
        pipe.close

        if (!output.empty?)
            puts "#{test} failed to compile:\n"
            puts "#{output}\n"
            next
        end

        result = File.read(test).match(/Expected result: <<\n(.*?)\n>>/ims)[1]

        pipe   = IO.popen('test/test');
        output = pipe.read.chomp
        pipe.close

        if $? != 0 || output != result
            puts "test/#{test} failed:"
            puts "Expected output: #{result}"
            puts "Received output: #{output}\n\n"
        else
            puts "test/#{test} passed."
        end
    }

    File.delete('test/test')
end

task :help do
    puts %{\
Options:
    32bit:  force 32 bit on 64 bit platform
    ARCH:   x86
}
end
