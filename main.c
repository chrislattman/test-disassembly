#define _GNU_SOURCE
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

int part1(void) {
    Circle circle;
    int c;

    printf("Enter a radius: ");
    scanf("%lf", &circle.radius);
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
    circle.x = (int) circle.radius;
    circle.y = 1;

    if (circle.x < 0) {
        printf("Your circle has a x-coordinate less than 0\n");
    } else if (circle.x == 0) {
        printf("Your circle has a x-coordinate equal to 0\n");
    } else {
        printf("Your circle has a x-coordinate greater than 0\n");
    }

    printf("Area = %lf, Circumference = %lf, Diameter = %lf\n", area(circle), circumference(circle), diameter(circle));

    change_radius(&circle, 4);
    printf("New diameter = %f\n", diameter(circle));

    fourargfunc(5, 3, 2, &circle);
    return circle.x;
}

void part2(void) {
    char *line = NULL;
    size_t len;
    const char number[] = "307";

    printf("Enter a string: ");
    getline(&line, &len, stdin);
    line[strlen(line) - 1] = '\0';
    printf("String length of '%s' = %zu\n", line, strlen(line));
    printf("Value of '%s' = %d\n", number, atoi(number));

    printf("%s\n", strcmp(line, number) != 0 ? "true" : "false");
    free(line);
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

void part5(void) {
    int x = 5;
    int counter = 0;
    while (1) {
        counter += 1;
        x = (x * 5) % 7;
        if (x == 1) {
            break;
        }
    }
    printf("The order of 5 mod 7 is %d\n", counter);
}

void part6(int arg) {
    switch (arg % 2)
    {
    case 0:
        printf("arg is even\n");
        break;
    case 1:
        printf("arg is odd\n");
        break;
    default:
        printf("this should never be called (numbers are even or odd)\n");
        break;
    }
}

int main(void) {
    int stack_buf[10];
    int* heap_buf = malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        stack_buf[i] = (i * 15) % 29;
        heap_buf[i] = (i + 12) % 31;
    }
    for (int i = 0; i < 10; i++) {
        printf("stack_buf[%d] = %d, heap_buf[%d] = %d\n", i, stack_buf[i], i, heap_buf[i]);
    }
    free(heap_buf);

    int res = part1();
    part2();
    part3();
    part4();
    part5();
    part6(res);

    return 0;
}
