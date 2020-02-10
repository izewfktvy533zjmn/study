package main


import (
	"fmt"
	"reflect"
)

func main() {
	year := 2018

	fmt.Printf("%T\n", year)
	fmt.Println(reflect.TypeOf(year))
}
