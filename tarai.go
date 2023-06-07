package main

import (
	"fmt"
	"math"
	"runtime"
	"time"
)

func tarai(x, y, z int) int {
	if x <= y {
		return y
	} else {
		return tarai(tarai(x-1, y, z),
			tarai(y-1, z, x),
			tarai(z-1, x, y))
	}
}

func main() {
	nIter := 10
	times := make([]float64, nIter)

	for i := 0; i < nIter; i++ {
		startTime := time.Now()
		tarai(13, 5, 0)
		elapsedTime := time.Since(startTime).Seconds()
		times[i] = elapsedTime
	}

	averageTime := 0.0
	stdTime := 0.0
	for _, t := range times {
		averageTime += t
	}
	averageTime /= float64(nIter)

	for _, t := range times {
		stdTime += math.Pow(t-averageTime, 2)
	}
	stdTime /= float64(nIter)
	stdTime = math.Sqrt(stdTime)

	fmt.Println("Go version:", go_version())
	fmt.Printf("Average elapsed_time: %f sec\n", averageTime)
	fmt.Printf("Standard deviation: %f sec\n", stdTime)
}

func go_version() (version string) {
	return runtime.Version()
}
