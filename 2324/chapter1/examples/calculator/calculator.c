// Calculator by Drew Babel

#include <cs50.h>
#include <stdio.h>


//math opperators --> USE ARGC & ARGV --> Usage: ./calc [num1] [operator] [num2]
int checkOperator(int argc, string argv[]);
int addition(int argc, string argv[]);
int subtraction(int num1, int num2);
int multiplication(int num1, int num2);
int division(int num1, int num2);

int main(void)
{
    //ask user for selected operator


    //ask user for two numbers
    int num1 = get_int("Enter a number:");
    int num2 = get_int("Enter another number:");

    // compute the sum
    int sum = addition(num1, num2);

    // print the sum
    printf("The sum is %i\n", sum);

}


int addition(int argc, string argv[])
{
    int output = argv[1] + argv[2];
    return output;
}

int subtraction(num1, num2)
{
    return num1 - num2;
}

int multiplication(num1, num2)
{
    return num1 * num2;
}

int division(num1, num2)
{
    return num1 / num2;
}
