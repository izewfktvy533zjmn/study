package main

import (
	"fmt"
	"os"
	)



func main() {
	if len(os.Args) == 2 {
		str := os.Args[1]

		for i:= 0; i < len(str); i++ {
			var char byte = 'a' + (str[i] + 3) % 'a'
			fmt.Printf("%c", char)
		}

		fmt.Println()

	}
}
