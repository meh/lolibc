require 'rake'
require 'rake/clean'

NAME    = 'lolibc'
RELEASE = '0.0.1'

PROJECTS = ['libc', 'libm']

task :default => [:pull, :compile]

task :pull do
    begin
        `git --version`
    rescue
        raise 'git is missing.'
    end

    PROJECTS.each {|project|
        if !Kernel.system("git clone . '#{project}' &> /dev/null")
            raise "Couldn't clone the repository to pull `#{project}`."
        end

        Dir.chdir(project)

        if !Kernel.system("git checkout '#{project}' &> /dev/null")
            raise "Couldn't checkout `#{project}` branch."
        end

        puts "Pull'd `#{project}`."
    }
end

task :compile do

end

task :test do
end

task :help do
    puts %{\
}
end
