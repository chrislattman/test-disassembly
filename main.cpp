#include <chrono>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Circle {
private:
    double radius;

public:
    int x, y;

    Circle(double radius) {
        this->radius = radius;
    }

    double area() {
        return M_PI * pow(radius, 2);
    }

    double circumference() {
        return 2 * M_PI * radius;
    }

    double diameter() {
        return 2 * radius;
    }

    void change_radius(double new_radius) {
        radius = new_radius;
    }
};

void fourargfunc(int arg1, int arg2, int arg3, Circle* arg4) {
    int result = arg1 + arg2 + arg3 + arg4->x + arg4->y;
    cout << "Result = " << result << endl;
}

void part1(void) {
    double radius;

    cout << "Enter radius: ";
    cin >> radius;
    Circle circle(radius);
    circle.x = 0;
    circle.y = 1;

    cout << "Area = " << circle.area() << ", Circumference = " << circle.circumference() << ", Diameter = " << circle.diameter() << endl;

    circle.change_radius(4);
    cout << "New diameter = " << circle.diameter() << endl;

    fourargfunc(5, 3, 2, &circle);
}

void part2(void) {
    string str = "Hello world!";
    string number = "307";

    cout << "String length of '" << str << "' = " << str.length() << endl;
    cout << "Value of '" << number << "' = " << stoi(number) << endl;

    cout << boolalpha << (str != number) << endl;
}

void part3(void) {
    int status = system("date");
    cout << noboolalpha << "Result of date command = " << status << endl;

    auto now = chrono::system_clock::now();
    time_t current_time = chrono::system_clock::to_time_t(now);
    cout << "Number of seconds since Jan 1, 1970 = " << current_time << endl;
}

void part4(void) {
    ifstream infile("sample.txt");
    string line;

    if (infile.is_open()) {
        getline(infile, line);
        infile.close();
    }
    cout << line << endl;
}

int main(void) {
    int stack_buf[10];
    int* heap_buf = new int[10];
    for (int i = 0; i < 10; i++) {
        stack_buf[i] = (i * 15) % 29;
        heap_buf[i] = (i + 12) % 31;
    }
    delete[] heap_buf;

    part1();
    part2();
    part3();
    part4();

    return 0;
}
