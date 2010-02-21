require 'rake'
require 'rake/clean'

NAME    = 'm'
RELEASE = '0.0.1'

CC = 'clang'
AR = 'ar'

CFLAGS = '-Wall -Wextra -Winline -Wno-long-long -I./include'

if ENV['DEBUG']
    CFLAGS << " -g3 -DDEBUG=#{ENV['DEBUG']}"
end

if !ARGV.include?('test')
    CFLAGS << ' -nostdlib -nodefaultlibs -fno-builtin -finline-functions'
else
    CFLAGS << ' -nostdlib -fno-builtin'
end

CLEAN.include('sources/**/*.o', 'include/features.h')
CLOBBER.include('*.so', '*.a')

SOURCES = FileList.new

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

        if !ENV['SPECIFIC']
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

        archs.reverse.each {|arch|
            arch = File.basename(arch)
            fallbacks = FileList["sources/arch/#{ENV['ARCH']}/#{arch}/**/**.c"]

            SOURCES.each {|file|
                fallbacks.exclude(file.sub(/^.*?\/arch\/.*?\/.*?\//,  ''))
            }

            SOURCES.include(fallbacks)
        }
    end
end

if ENV['32bit']
    CFLAGS << ' -m32'
elsif ENV['64bit']
    CFLAGS << ' -m64'
end

if ENV['OPTIMIZED'] != 'false'
    CFLAGS << ' -Os'
end

fallbacks = FileList['sources/common/**/*.c']

if ENV['SPECIFIC']
    regexp = /^.*?\/(#{ENV['PLATFORM']}|arch\/.*?\/.*?)\//
else
    regexp = /^.*?\/(#{ENV['PLATFORM']}|#{ENV['ARCH']})\//
end

SOURCES.each {|file|
    fallbacks.exclude(file.sub(regexp, ''))
}

SOURCES.include(fallbacks)

SOURCES.resolve.existing!

OBJECTS = SOURCES.ext('o')

task :default => ["lib#{NAME}.so", "lib#{NAME}.a"]

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
