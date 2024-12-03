use std::{
    f64::consts::PI,
    fs::File,
    io::{self, prelude::*, BufReader, Write},
    process::Command,
    time::{SystemTime, UNIX_EPOCH},
};

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

fn fourargfunc(arg1: i32, arg2: i32, arg3: i32, arg4: &mut Circle) {
    let result = arg1 + arg2 + arg3 + arg4.x + arg4.y;
    println!("Result = {}", result);
}

fn part1() {
    print!("Enter radius: ");
    io::stdout().flush().unwrap();
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();
    let mut circle = Circle {
        x: 0,
        y: 1,
        radius: buffer.trim().parse::<f64>().unwrap(),
    };

    if circle.x < 0 {
        println!("Your circle has a x-coordinate less than 0");
    } else if circle.x == 0 {
        println!("Your circle has a x-coordinate equal to 0");
    } else {
        println!("Your circle has a x-coordinate greater than 0");
    }

    println!(
        "Area = {}, Circumference = {}, Diameter = {}",
        circle.area(),
        circle.circumference(),
        circle.diameter()
    );

    circle.change_radius(4.0);
    println!("New diameter = {}", circle.diameter());

    fourargfunc(5, 3, 2, &mut circle);
}

fn part2() {
    let s = "Hello world!";
    let number = "307";

    println!("String length of '{}' = {}", s, s.len());
    println!("Value of '{}' = {}", number, number.parse::<i32>().unwrap());

    println!("{}", s != number);
}

fn part3() {
    let status = Command::new("date").status().unwrap().code().unwrap();
    println!("Result of date command = {}", status);

    let current_time = SystemTime::now()
        .duration_since(UNIX_EPOCH)
        .unwrap()
        .as_secs();
    println!("Number of seconds since Jan 1, 1970 = {}", current_time);
}

fn part4() {
    let fp = File::open("sample.txt").unwrap();
    let mut reader = BufReader::new(fp);
    let mut line = String::new();
    reader.read_line(&mut line).unwrap();
    print!("{}", line);
}

fn part5() {
    let mut x = 5;
    loop {
        x = (x * 5) % 7;
        if x == 1 {
            break;
        }
    }
}

fn part6(arg: i32) {
    match arg % 2 {
        0 => println!("arg is even"),
        1 => println!("arg is odd"),
        _ => println!("this should never be called (numbers are even or odd)")
    }
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
    part3();
    part4();
    part5();
    part6(13);
}
