// Calc by Drew Babel

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// mod opperator --> Usage: ./calc [num1] [operator] [num2]
// index:                      0      1        2       3

float mod(float num1, float num2);

int main(int argc, string argv[])
{
    // check
    if (argc != 4)
    {
        printf("Usage: ./calc [num1] [operator] [num2]");
        return 1;
    }

    double num1 = atof(argv[1]);
    double num2 = atof(argv[3]);
    char operator= argv[2][0]; // assign the first character of the third  command line argument (index: 2) as the operator -->
                               // needed as you cant firectly assign string to char

    // if(argv[3] = '*') //multiplication
    // {
    //    printf(argv[2]+argv[3]);
    // }
    // else if(argv[3] = '/') //division
    // {

    // }
    // else if(argv[3] = '+') //addition
    // {

    // }
    // else if(argv[3] = '-') //subtraction
    // {

    // }
    // else // modulus
    // mod();

    // }

    switch (operator) // better version of if else statments above
    {
        case 'x': // multiplication
            printf("%f\n", num1 * num2);
            break;
        case '/': // division
            if (num2 == 0)
            {
                printf("Cannot divide by zero\n"); // divide by zero check
            }
            else
            {
                printf("%f\n", num1 / num2);
            }
            break;
        case '+': // addition
            printf("%f\n", num1 + num2);
            break;
        case '-': // subtraction
            printf("%f\n", num1 - num2);
            break;
        case '%': // modulus
            // modulus operator in C only works with integers, this function handles it as a float
            printf("%f\n", mod(num1, num2));
            break;
        default: // invalid input for operator
            printf("Invalid operator '%c' ./n", operator);
            return 1;
    }
}

float mod(float num1, float num2)
{
    if (num2 == 0)
    {
        printf("Error: Division by zero in modulus operator not possible");
        return 0;
    }
    else
    {
        // compute modulus for floating point numbers
        int quotient = (int) (num1 / num2);
        double mod = num1 - (num2 * quotient);
        return mod;
    }
}
