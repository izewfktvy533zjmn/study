package main

import "fmt"


func main() {
    fmt.Println("入り口の近くに「未成年立入禁止」という立て札がある")

    var age = 41
    var minor = age < 18

    fmt.Printf("%v歳の僕は、未成年か？ %v\n", age, minor)
}
