#! /usr/bin/env ruby

tests = [
    { "file" => "string.c", "result" => "3" }
];

tests.each {|test|
    pipe   = IO.popen("clang -I../include -o test/test test/#{test['file']}");
    output = pipe.read.chomp
    pipe.close

    if (!output.empty?)
        puts "test/#{test['file']} failed to compile:\n"
        puts "#{output}\n"
    end

    pipe   = IO.popen("test/test");
    output = pipe.read.chomp
    pipe.close

    if $? != 0 || output != test['result']
        puts "test/#{test['file']} failed:"
        puts "Expected output: #{test['result']}"
        puts "Received output: #{output}\n\n"
    else
        puts "test/#{test['file']} passed."
    end
}

File.delete("test/test")
