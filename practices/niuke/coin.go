package main

import (
	"fmt"
)

func main() {
	n := 0
	fmt.Scanf("%d", &n)
	q(n)
	fmt.Printf("%s", s)
}

var s = ""

func q(n int) {
	// 2x+1 2x+2
	// a 2a+1 4a+3
	// a 2a+2
	if n == 0 {
		return
	}
	if n%2 == 0 {
		s = "2" + s
		q((n - 2) / 2)
	} else {
		s = "1" + s
		q((n - 1) / 2)
	}
}
