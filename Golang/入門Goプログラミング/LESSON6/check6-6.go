package main


import "fmt"


func main() {
	var piggyBank float64

	for i := 0; i < 11; i++ {
		piggyBank += 0.10
	}

	fmt.Println(piggyBank)
}
