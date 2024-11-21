use std::{f64::consts::PI, io::{self, Write}};

struct Circle {
    x: i32,
    y: i32,
    radius: f64,
}

impl Circle {
    fn area(&self) -> f64 {
        return PI * self.radius.powf(2.0);
    }

    fn circumference(&self) -> f64 {
        return 2.0 * PI * self.radius;
    }

    fn diameter(&self) -> f64 {
        return 2.0 * self.radius;
    }

    fn change_radius(&mut self, new_radius: f64) {
        self.radius = new_radius;
    }
}

fn part1() {
    print!("Enter radius: ");
    io::stdout().flush().unwrap();
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();
    let mut circle = Circle{ x: 0, y: 1, radius: buffer.trim().parse::<f64>().unwrap() };

    println!("Area = {}, Circumference = {}, Diameter = {}", circle.area(), circle.circumference(), circle.diameter());

    circle.change_radius(4.0);
    println!("New diameter = {}", circle.diameter());
}

fn part2() {
    let s = "Hello world!";
    let number = "307";

    println!("String length of '{}' = {}", s, s.len());
    println!("Value of '{}' = {}", number, number.parse::<i32>().unwrap());

    println!("{}", s != number);
}

fn main() {
    let mut stack_buf = [0; 10];
    let mut heap_buf = vec![0; 10];
    for i in 0..10 {
        stack_buf[i] = (i * 15) % 29;
        heap_buf[i] = (i + 12) % 31;
    }

    part1();
    part2();
}
