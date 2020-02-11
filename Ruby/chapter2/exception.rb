#!/usr/bin/env ruby

begin
    1/0
rescue ZeroDivisionError
    puts "zero division error occored"
end

