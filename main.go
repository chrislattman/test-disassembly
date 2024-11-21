package main

import (
	"fmt"
	"math"
	"strconv"
)

type Circle struct {
	x, y int
	radius float64
}

func (circle Circle) area() float64 {
	return math.Pi * math.Pow(circle.radius, 2)
}

func (circle Circle) circumference() float64 {
	return 2 * math.Pi * circle.radius
}

func (circle Circle) diameter() float64 {
	return 2 * circle.radius
}

func (circle *Circle) changeRadius(newRadius float64) {
	circle.radius = newRadius
}

func part1() {
	var circle Circle

	fmt.Print("Enter radius: ")
	fmt.Scanf("%f", &circle.radius)
	circle.x = 0
	circle.y = 1

	fmt.Printf("Area = %v, Circumference = %v, Diameter = %v\n", circle.area(), circle.circumference(), circle.diameter())

	circle.changeRadius(4)
	fmt.Printf("New diameter = %v\n", circle.diameter())
}

func part2() {
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

	part1()
	part2()
}
