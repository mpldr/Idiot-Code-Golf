package main

import (
	// we want *real* random
	"crypto/rand"
	"fmt"
	"os"
	"unicode"
)

func main() {
	jobList := make(chan [2]chan rune, 4096)

	// spin up an appropriate amount of workers for this task
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)
	go worker(jobList)

	outchans := make(chan chan rune, 4096)
	done := make(chan struct{}, 1)

	go func(o chan chan rune) {
		for r := range o {
			fmt.Printf("%c", <-r)
		}
		done <- struct{}{}
	}(outchans)

	for _, str := range os.Args[1:] {
		for _, c := range str {
			in := make(chan rune, 1)
			out := make(chan rune, 1)
			outchans <- out
			jobList <- [2]chan rune{in, out}
			in <- c
			close(in)
		}
		out := make(chan rune, 1)
		outchans <- out
		out <- ' '
		close(out)
	}
	close(outchans)

	<-done
}

func worker(jobList chan [2]chan rune) {
	b := make([]byte, 1)
	for job := range jobList {
		c := <-job[0]
		_, err := rand.Read(b)
		if err != nil {
			job[1] <- c
			close(job[1])
			continue
		}
		if b[0]%2 == 0 {
			// switch case
			if unicode.ToUpper(c) == c {
				job[1] <- unicode.ToLower(c)
			} else {
				job[1] <- unicode.ToUpper(c)
			}
			close(job[1])
			continue
		}
		job[1] <- c
		close(job[1])
	}
}
