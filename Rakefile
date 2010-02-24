require 'rake'
require 'rake/clean'

NAME    = 'lolibc'
RELEASE = '0.0.1'

PROJECTS = ['libc', 'libm']

CLOBBER.include(PROJECTS)

task :default => :compile

task :pull do
    if !Kernel.system('git --version &> /dev/null')
        raise 'git is missing.'
    end

    PROJECTS.each {|project|
        if File.exists?(project)
            next
        end

        Kernel.system("git branch -D '#{project}' &> /dev/null")

        if !Kernel.system("git checkout --track -b '#{project}' origin/'#{project}' &> /dev/null")
            raise "Could not checkout `#{project}`"
        end
    }

    Kernel.system('git checkout master &> /dev/null')

    PROJECTS.each {|project|
        if File.exists?(project)
            next
        end

        if !Kernel.system("git clone -b '#{project}' . '#{project}' &> /dev/null")
            raise "Couldn't clone `#{project}`."
        end

        puts "Cloned `#{project}`"
    }
end

task :compile => :pull do

end

task :test do
end

task :help do
    puts %{\
}
end
