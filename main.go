package main

import (
	"fmt"
	"math"
	"strconv"
)

type circle struct {
	x, y int
	radius float64
}

func (circ circle) area() float64 {
	return math.Pi * math.Pow(circ.radius, 2)
}

func (circ circle) circumference() float64 {
	return 2 * math.Pi * circ.radius
}

func (circ circle) diameter() float64 {
	return 2 * circ.radius
}

func (circ *circle) changeRadius(newRadius float64) {
	circ.radius = newRadius
}

func Part1() {
	var circ circle

	fmt.Print("Enter radius: ")
	fmt.Scanf("%f", &circ.radius)
	circ.x = 0
	circ.y = 1

	fmt.Printf("Area = %v, Circumference = %v, Diameter = %v\n", circ.area(), circ.circumference(), circ.diameter())

	circ.changeRadius(4)
	fmt.Printf("New diameter = %v\n", circ.diameter())
}

func Part2() {
	str := "Hello world!"
	number := "307"

	fmt.Printf("String length of '%v' = %v\n", str, len(str))
	val, _ := strconv.Atoi(number)
	fmt.Printf("Value of '%v' = %v\n", number, val)

	fmt.Println(str != number)
}

func main() {
	var stackBuf [10]int
	heapBuf := make([]int, 10)
	for i := 0; i < 10; i++ {
		stackBuf[i] = (i * 15) % 29
		heapBuf[i] = (i + 12) % 31
	}

	Part1()
	Part2()
}
