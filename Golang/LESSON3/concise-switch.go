package main

import "fmt"


func main() {
    fmt.Println("洞窟の入り口だ、東へ進む道もある")
    var command = "go inside"


    switch command {
        case "go east":
            fmt.Println("君はさらに山を登る")
        case "enter cave", "go inside":
            fmt.Println("君は薄暗い洞窟の中にいる")
        case "read sign":
            fmt.Println("「未成年立入禁止」と書いてある")
        default:
            fmt.Println("なんだかよくわからない")
    }

}
