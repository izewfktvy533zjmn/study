package main

import (
	"fmt"
	"math/big"
)


func main() {
	lightSpeed := big.NewInt(299792)
	secondsPerday := big.NewInt(86400)
	distance := new(big.Int)
	distance.SetString("24000000000000000000", 10)
	fmt.Println("アンドロメダ銀河までの距離は", distance, "km")

	seconds := new(big.Int)
	seconds.Div(distance, lightSpeed)

	days := new(big.Int)
	days.Div(seconds, secondsPerday)

	fmt.Println("光の速度で", days, "日かかる")

}
