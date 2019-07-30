package main 

import (
    "fmt"
    "strings"
    )

func main() {
    fmt.Println("君は薄暗い道具つの中にいる")
    var command = "walk outside"
    var exit = strings.Contains(command, "outside")
    fmt.Println("同靴を出る", exit)
}
