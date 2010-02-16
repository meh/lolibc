require 'rake'
require 'rake/clean'

NAME    = 'lolibc'
RELEASE = '0.0.1'

CC = 'clang'
AR = 'ar'

CFLAGS = '-Wall -Wextra -Winline -Wno-long-long -I./include'

if !ARGV.include?('test')
    CFLAGS << ' -nostdlib -nodefaultlibs -fno-builtin -finline-functions'
else
    CFLAGS << ' -nostdlib -fno-builtin'
end

CLEAN.include('sources/**/*.o', 'include/features.h')
CLOBBER.include('*.so', '*.a')

if !ARGV.include?('clean') && !ARGV.include?('clobber')
    def preprocess (file, strip=[])
        content = File.read(file)

        content.gsub!(/^@.*? .*?$/) {|string|
            command = string.match(/^@(.*?) (.*?)$/)

            case command[1]
                when 'require'
                    path = "#{File.dirname(file)}/#{eval command[2].match(/(".*?")/)[1]}"

                    if !File.exists?(path)
                        raise "@required \"#{path}\": file not found."
                    end

                    result = preprocess(path, [/\/\*.*?\*\/(\s*\n)*/ms, /(\s*\n)*$/ms])
            end

            result
        }

        strip.each {|re|
            content.gsub!(re, '')
        }

        return content
    end

    FileList['include/*.h.in'].each {|header|
        file = File.new(header.sub(/\.in$/, ''), 'w')
        file.write(preprocess(header))
        file.close
    }
else
    FileList['include/*.h.in'].each {|header|
        CLEAN.include(header.sub(/\.in$/, ''))
    }
end

SOURCES = FileList['sources/*.c']

if ENV['ARCH']
    specific = ENV['ARCH'].match(/^(.*?)\/(.*?)$/)

    if specific
        ENV['ARCH']     = specific[1]
        ENV['SPECIFIC'] = specific[2]
    end
end

case ENV['ARCH']
    when 'x86'
        CFLAGS << ' -D_ARCH_X86'
        ENV['32bit'] = 'true'

        if !defined? ENV['SPECIFIC']
            ENV['SPECIFIC'] = 'i386'
        end

        CFLAGS << " -D_ARCH_SPECIFIC_#{ENV['SPECIFIC']}"

    when 'x86_64'
        CFLAGS << ' -D_ARCH_X86_64'
        ENV['64bit']    = 'true'

        ENV['SPECIFIC'] = '.'
end

if ENV['ARCH']
    SOURCES.include("sources/arch/#{ENV['ARCH']}/#{ENV['SPECIFIC']}/**/*.c")

    if ENV['ARCH'] == 'x86'
        drop = false
        archs = FileList["sources/arch/#{ENV['ARCH']}/*"]

        if archs.grep(/#{ENV['SPECIFIC']}/).empty?
            archs.include("sources/arch/#{ENV['ARCH']}/#{ENV['SPECIFIC']}")
        end
    
        archs = archs.sort.select {|arch|
            if drop
                false
            else
                if File.basename(arch) == ENV['SPECIFIC']
                    drop = true
                    false
                end

                true
            end
        }

        archs.reverse.each {|file|
            fallbacks = FileList["sources/arch/#{ENV['ARCH']}/#{File.basename(file)}/**/**.c"]

            SOURCES.each {|file|
                fallbacks.exclude(File.basename(file))
            }

            SOURCES.include(fallbacks)
        }
    end

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

if !defined? ENV['PLATFORM']
    ENV['PLATFORM'] = 'Linux'
end

case ENV['PLATFORM']
    when 'Linux'
        CFLAGS << ' -D_PLATFORM_LINUX'
end

if !ENV['KERNEL']
    SOURCES.include("sources/platform/#{ENV['PLATFORM']}/**/*.c");
end

fallbacks = FileList['sources/common/**/*.c']

SOURCES.each {|file|
    fallbacks.exclude(File.basename(file))
}

SOURCES.include(fallbacks)

SOURCES.resolve.existing!

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
#   define PRIVATE 
#else
#   define __BEGIN_NAMESPACE(name)
#   define __END_NAMESPACE
#
#   define PUBLIC extern
#   define PRIVATE
#endif

#define alias(name, aliasname, ...) PUBLIC typeof (name) aliasname __attribute__ ((alias (#name), ## __VA_ARGS__))

#endif
})

    file.close
end

rule '.o' => '.c' do |t|
    sh "#{CC} -fPIC #{CFLAGS} -o #{t.name} -c #{t.source}"
end

task :compile => ['include/features.h'].concat(OBJECTS)

file "lib#{NAME}.so" => :compile do
    sh "#{CC} #{CFLAGS} -dynamiclib -shared -Wl,-soname,lib#{NAME}.so -o lib#{NAME}.so #{OBJECTS}"
end

file "lib#{NAME}.a" => :compile do
    sh "rm -f lib#{NAME}.a"
    sh "#{AR} rcs lib#{NAME}.a #{OBJECTS}"
end

task :test do
    tests = FileList['test/**/*.c']

    tests.each {|test|
        pipe   = IO.popen("#{CC} #{CFLAGS} -o test/test #{test} -L. -static -llolibc 2>&1");
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
            if $?.signaled?
                code = $?.inspect.match(/signaled\((.*?)=/)[1]
            else
                code = $?.to_i
            end

            puts "#{test} failed (#{code}) ({} = expected; [] = received):"
            puts "{#{result}} [#{output}]\n\n"
        else
            puts "#{test} passed."
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
