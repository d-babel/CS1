#include <stdio.h>

int main()
{
    printf("Enter a number: ");
    int sum = 0;
    char c;

    while ((c = getchar()) != '\n')
    { // check for empty input
        if (c >= '0' && c <= '9')
        {
            // if the character is a digit, convert to integer, add to sum
            sum += c - '0';
        }
    }

    printf("The sum of the individual digits is: %d\n", sum);
}