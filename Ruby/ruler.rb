#!/usr/bin/env ruby

class Ruler
    def length=(val)
        @length = val
    end

    def length
        @length
    end
end


ruler = Ruler.new
ruler.length = 3
puts ruler.length
