#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Circle {
    int x, y;
    double radius;
} Circle;

static double area(Circle circle) {
    return M_PI * pow(circle.radius, 2);
}

static double circumference(Circle circle) {
    return 2 * M_PI * circle.radius;
}

static double diameter(Circle circle) {
    return 2 * circle.radius;
}

static void change_radius(Circle* circle, double new_radius) {
    circle->radius = new_radius;
}

void fourargfunc(int arg1, int arg2, int arg3, Circle* arg4) {
    int result = arg1 + arg2 + arg3 + arg4->x + arg4->y;
    printf("Result = %d\n", result);
}

void part1(void) {
    Circle circle;

    printf("Enter radius: ");
    scanf("%lf", &circle.radius);
    circle.x = 0;
    circle.y = 1;

    printf("Area = %lf, Circumference = %lf, Diameter = %lf\n", area(circle), circumference(circle), diameter(circle));

    change_radius(&circle, 4);
    printf("New diameter = %f\n", diameter(circle));

    fourargfunc(5, 3, 2, &circle);
}

void part2(void) {
    const char* str = "Hello world!";
    const char number[] = "307";

    printf("String length of '%s' = %zu\n", str, strlen(str));
    printf("Value of '%s' = %d\n", number, atoi(number));

    printf("%s\n", strcmp(str, number) != 0 ? "true" : "false");
}

void part3(void) {
    int status = system("date");
    printf("Result of date command = %d\n", status);

    time_t current_time = time(NULL);
    printf("Number of seconds since Jan 1, 1970 = %ld\n", current_time);
}

void part4(void) {
    char line[32] = {0};

    FILE *fp = fopen("sample.txt", "r");
    fread(line, sizeof(char), 19, fp);
    fclose(fp);
    printf("%s\n", line);
}

int main(void) {
    int stack_buf[10];
    int* heap_buf = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        stack_buf[i] = (i * 15) % 29;
        heap_buf[i] = (i + 12) % 31;
    }
    free(heap_buf);

    part1();
    part2();
    part3();
    part4();

    return 0;
}
