package main

import (
	"fmt"
	"strconv"
)

func main() {
	baseNum := 0
	fmt.Scanf("%d", &baseNum)
	baseNumStr := strconv.Itoa(baseNum)
	reverseNumStr := ""
	for _, c := range baseNumStr {
		reverseNumStr = string(c) + reverseNumStr
	}
	reverseNum, _ := strconv.Atoi(reverseNumStr)
	fmt.Printf("%d", baseNum+reverseNum)
}
