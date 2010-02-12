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
        SOURCES.include('sources/arch/x86/**.c')
        ENV['32bit'] = 'true'
    else
        SOURCES.include('sources/arch/none/**.c')
end

if ENV['32bit']
    CFLAGS << ' -m32'
end

OBJECTS = SOURCES.ext('o')

task :default => ["lib#{NAME}.so.#{RELEASE}", "lib#{NAME}.a"]

rule '.o' => '.c' do |t|
    sh "#{CC} #{CFLAGS} -o #{t.name} -c #{t.source}"
end

task :features do
    file = File.new('include/features.h', 'w')

    file.write(%{\
#ifndef _LOLIBC_FEATURES_H
#define _LOLIBC_FEATURES_H

#ifdef _cplusplus
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

task :compile => [:features].concat(OBJECTS)

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
