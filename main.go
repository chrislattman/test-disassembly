package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"os/exec"
	"strconv"
	"time"
)

type circle struct {
	x, y   int
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

func FourArgFunc(arg1 int, arg2 int, arg3 int, arg4 *circle) {
	result := arg1 + arg2 + arg3 + arg4.x + arg4.y
	fmt.Println("Result =", result)
}

func Part1() {
	var circ circle

	fmt.Print("Enter radius: ")
	fmt.Scanf("%f", &circ.radius)
	circ.x = 0
	circ.y = 1

	if circ.x < 0 {
        fmt.Println("Your circle has a x-coordinate less than 0")
    } else if circ.radius == 0 {
        fmt.Println("Your circle has a x-coordinate equal to 0")
    } else {
        fmt.Println("Your circle has a x-coordinate greater than 0")
    }

	fmt.Printf("Area = %v, Circumference = %v, Diameter = %v\n", circ.area(), circ.circumference(), circ.diameter())

	circ.changeRadius(4)
	fmt.Printf("New diameter = %v\n", circ.diameter())

	FourArgFunc(5, 3, 2, &circ)
}

func Part2() {
	str := "Hello world!"
	number := "307"

	fmt.Printf("String length of '%v' = %v\n", str, len(str))
	val, _ := strconv.Atoi(number)
	fmt.Printf("Value of '%v' = %v\n", number, val)

	fmt.Println(str != number)
}

func Part3() {
	err := exec.Command("date").Run()
	if err == nil {
		fmt.Println("Result of date command = 0")
	} else {
		if exitErr, ok := err.(*exec.ExitError); ok {
			fmt.Println("Result of date command =", exitErr.ExitCode())
		}
	}

	currentTime := time.Now().Unix()
	fmt.Println("Number of seconds since Jan 1, 1970 =", currentTime)
}

func Part4() {
	fp, _ := os.Open("sample.txt")
	reader := bufio.NewReader(fp)
	line, _ := reader.ReadString('\n')
	fp.Close()
	fmt.Print(line)
}

func Part5() {
	x := 5
    for true {
        x = (x * 5) % 7
        if (x == 1) {
            break
        }
    }
}

func Part6(arg int) {
	switch arg % 2 {
	case 0:
		fmt.Println("arg is even")
	case 1:
		fmt.Println("arg is odd")
	default:
		fmt.Println("this should never be called (numbers are even or odd)")
	}
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
	Part3()
	Part4()
	Part5()
	Part6(13)
}
