#!/usr/bin/env ruby

greeter = Proc.new {|name|
    puts "Hello, #{name}!"
}

#greeter.call 'Taichi'

by_proc = proc {|name| puts "Hello, #{name}!"}
by_lambda = lambda {|name| puts "Hello, #{name}!"}
by_literal = ->(name) { puts "Hello, #{name}!" }

puts by_proc.call 'Taichi'
puts by_lambda.call 'Taichi'
puts by_literal.call 'Taichi'
