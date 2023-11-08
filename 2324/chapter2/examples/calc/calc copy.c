// Calc by Drew Babel

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

float mod(float num1, float num2);

int main(int argc, string argv[]) {
    if (argc != 4) {
        printf("Usage: ./calc [num1] [operator] [num2]\n");
        return 1;
    }

    float num1 = atof(argv[1]);
    float num2 = atof(argv[3]);
    char operator = argv[2][0];

    switch (operator) {
        case 'x':
            printf("%f\n", num2 * num1);
            break;
        case '/':
            if (num2 == 0) {
                printf("Cannot divide by zero\n");
            } else {
                printf("%f\n", num1 / num2);
            }
            break;
        case '+':
            printf("%f\n", num1 + num2);
            break;
        case '-':
            printf("%f\n", num1 - num2);
            break;
        case '%':
            printf("%f\n", mod(num1, num2));
            break;
        default:
            printf("Invalid operator '%c'.\n", operator);
            return 1;
    }
    return 0;
}

float mod(float num1, float num2) {
    if (num2 == 0){
        return -1;
    }
    int quotient = (int)(num1 / num2);
    return num1 - (num2 * quotient);
}
