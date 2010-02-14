require 'rake'
require 'rake/clean'

NAME    = 'lolibc'
RELEASE = '0.0.1'

CC = 'clang'
AR = 'ar'

CFLAGS  = '-fPIC -Wall -Wextra -Winline -Wno-long-long -nostdlib -nodefaultlibs -fno-builtin -finline-functions -I./include'
LDFLAGS = '-s'

CLEAN.include('sources/**/*.o', 'include/features.h')
CLOBBER.include('*.so.*', '*.a')

SOURCES = FileList['sources/*.c']

case ENV['ARCH']
    when 'x86'
        ENV['32bit'] = 'true'
    when 'x86_64'
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

OBJECTS = SOURCES.ext('o')

task :default => ["lib#{NAME}.so.#{RELEASE}", "lib#{NAME}.a"]

rule '.o' => '.c' do |t|
    sh "#{CC} #{CFLAGS} -o #{t.name} -c #{t.source}"
end

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

task :compile => ['include/features.h'].concat(OBJECTS)

file "lib#{NAME}.so.#{RELEASE}" => :compile do
    sh "#{CC} #{LDFLAGS} #{CFLAGS} -shared -Wl,-soname,lib#{NAME}.so.#{RELEASE} -o lib#{NAME}.so.#{RELEASE} #{OBJECTS}"
end

file "lib#{NAME}.a" => :compile do
    sh "#{AR} rcs lib#{NAME}.a #{OBJECTS}"
end

task :help do
    puts %{\
Options:
    32bit:  force 32 bit on 64 bit platform
    ARCH:   x86
}
end
