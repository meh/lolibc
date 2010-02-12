require 'rake'
require 'rake/clean'

NAME    = 'lolibc'
RELEASE = '0.0.1'

CC = 'clang'
AR = 'ar'

CFLAGS = '-fPIC -Wall -Wextra -Winline -Wno-long-long -nostartfiles -nostdlib -nodefaultlibs -fno-builtin -I./include'

CLEAN.include('sources/**/*.o', 'include/features.h')
CLOBBER.include('*.so.*', '*.a')

C_SOURCES   = FileList['sources/*.c']
ASM_SOURCES = FileList['sources/*.S']

case ENV['ARCH']
    when 'x86'
        C_SOURCES.include('sources/arch/x86/**.c')
        ASM_SOURCES.include('sources/arch/x86/**.S')
    else
        C_SOURCES.include('sources/arch/none/**.c')
        ASM_SOURCES.include('sources/arch/none/**.S')
end

C_OBJECTS   = C_SOURCES.ext('o')
ASM_OBJECTS = ASM_SOURCES.ext('S.o')

OBJECTS = FileList.new
OBJECTS.include(C_OBJECTS)
OBJECTS.include(ASM_OBJECTS)

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
    sh "#{CC} #{CFLAGS} -shared -Wl,-soname,lib#{NAME}.so.#{RELEASE} -o lib#{NAME}.so.#{RELEASE} #{OBJECTS}"
end

file "lib#{NAME}.a" => :compile do
    sh "#{AR} rcs lib#{NAME}.a #{OBJECTS}"
end
