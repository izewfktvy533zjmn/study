package main

import "fmt"


func main() {
    fmt.Println("2100年は、閏年ですか")

    var year = 2100
    var leap = year%400 == 0 || (year%4 == 0 && year%100 != 0)

    if leap {
        fmt.Println("はい。閏年(leap year)です")
    } else {
        fmt.Println("いいえ、平年(common year)です")
    }

}
