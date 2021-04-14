package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"sync"
)

func main() {
	if len(os.Args) != 3 {
		fmt.Println("we need 2 numbers. usage: ./gcd 200 50")
		os.Exit(2)
	}
	a, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Printf("whatever %s is… I can't make it an integer: %v\n", os.Args[1], err)
		os.Exit(1)
	}
	b, err := strconv.Atoi(os.Args[2])
	if err != nil {
		fmt.Printf("whatever %s is… I can't make it an integer: %v\n", os.Args[2], err)
		os.Exit(1)
	}

	fmt.Println(gcd(a, b))
}

func gcd(a, b int) int {
	if a == 0 || b == 0 {
		return 0
	}

	adiv := make(chan []int)
	bdiv := make(chan []int)

	go getDivisors(a, adiv)
	go getDivisors(b, bdiv)

	adivs := <-adiv
	bdivs := <-bdiv

	var gcd int

	for i := 0; i < len(adivs); i++ {
		for j := 0; j < len(bdivs); j++ {
			if adivs[i] == bdivs[j] && adivs[i] > gcd {
				gcd = adivs[i]
			}
		}
	}

	return gcd
}

func getDivisors(num int, out chan []int) {
	results := make(chan int, 4096)
	joined := make(chan struct{})
	var res []int
	var wg sync.WaitGroup

	go func(r chan int) {
		for i := range r {
			res = append(res, i)
		}
		joined <- struct{}{}
	}(results)

	concurrency := int(math.Ceil(float64(num) / 512))

	for i := 0; i < concurrency; i++ {
		wg.Add(1)
		go func(n, l, u int) {
			defer wg.Done()
			getDivisorsLimit(n, l, u, results)
		}(num, i*512+1, i*512+512)
	}

	wg.Wait()
	close(results)
	<-joined

	out <- res
}

func getDivisorsLimit(num, lowerBound, upperBound int, results chan int) {
	for i := lowerBound; i <= upperBound && i <= num; i++ {
		if num%i == 0 {
			results <- i
		}
	}
}
