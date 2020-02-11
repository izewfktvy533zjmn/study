#!/usr/bin/env ruby

module Brainfsck
    class Parser
        def eval
            puts "["
        end
    end
end


module Whitespace
    class Parser
        def eval
            puts " "
        end
    end
end
            

puts Brainfsck::Parser
#Brainfsck::Parser.eval
puts Whitespace::Parser
#Whitespace::Parser.eval
