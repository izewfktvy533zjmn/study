package main

import "fmt"
import "reflect"


func main() {
	var num1 int32
	var num2 float64
	var num3 float32

	fmt.Println(reflect.TypeOf(num1))
	fmt.Println(reflect.TypeOf(num2))
	fmt.Println(reflect.TypeOf(num3))
}
