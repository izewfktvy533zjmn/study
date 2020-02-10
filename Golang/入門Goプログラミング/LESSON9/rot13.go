package main

import (
	"fmt"
	"os"
	)



func main() {
	if len(os.Args) == 2 {
		str := os.Args[1]
		
		for i:= 0; i < len(str); i++ {
			if str[i] >= 'a' && str[i] <= 'z' {
				char := str[i] + 13

				if char > 'z' {
					char -= 26
				}

				fmt.Printf("%c", char)
			}
		}

		fmt.Println()
	}
}
