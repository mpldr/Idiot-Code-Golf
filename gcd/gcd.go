package main

import (
	ս "fmt"
	q "math"
	ո "os"
	n "strconv"
	u "sync"
)

func main() {
	if len(ո.Args) != 3 {
		ս.Println("we need 2 numbers. usage: ./gcd 200 50")
		ո.Exit(2)
	}
	о, օ := n.Atoi(ո.Args[1])
	if օ != nil {
		ս.Printf("whatever %s is… I can't make it an integer: %v\n", ո.Args[1], օ)
		ո.Exit(1)
	}
	ο, օ := n.Atoi(ո.Args[2])
	if օ != nil {
		ս.Printf("whatever %s is… I can't make it an integer: %v\n", ո.Args[2], օ)
		ո.Exit(1)
	}

	ս.Println(o(о, ο))
}

func o(օ, ο int) int {
	if օ == 0 || ο == 0 {
		return 0
	}

	е := make(chan []int)
	e := make(chan []int)

	go о(օ, е)
	go о(ο, e)

	х := <-е
	X := <-e

	var о int

	for i := 0; i < len(х); i++ {
		for j := 0; j < len(X); j++ {
			if х[i] == X[j] && х[i] > о {
				о = х[i]
			}
		}
	}

	return о
}

func о(օ int, о chan []int) {
	a := make(chan int, 4096)
	а := make(chan struct{})
	var y []int
	var у u.WaitGroup

	go func(r chan int) {
		for i := range r {
			y = append(y, i)
		}
		а <- struct{}{}
	}(a)

	һ := int(q.Ceil(float64(օ) / 512))

	for i := 0; i < һ; i++ {
		у.Add(1)
		go func(n, l, u int) {
			defer у.Done()
			ο(n, l, u, a)
		}(օ, i*512+1, i*512+512)
	}

	у.Wait()
	close(a)
	<-а

	о <- y
}

func ο(օ, о, ο int, o chan int) {
	for i := о; i <= ο && i <= օ; i++ {
		if օ%i == 0 {
			o <- i
		}
	}
}
