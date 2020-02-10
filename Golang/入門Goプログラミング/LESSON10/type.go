package main

import (
	"fmt"
	"strconv"
	)

func main() {
	var bh float64 = 32767
	var h = int16(bh)

	fmt.Println(bh, h)
	fmt.Println("test" + strconv.Itoa(int(h)))
	val, err := strconv.Atoi("10")

	if err != nil {
		fmt.Println("error")
	}

	fmt.Println(16 + val)
}
