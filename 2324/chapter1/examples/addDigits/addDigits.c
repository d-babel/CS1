// addDigits by Drew Babel

#include <stdio.h>

int main() {
    printf("Enter a number: ");
    int sum = 0;
    char c;

    while ((c = getchar()) != '\n') {  // Check until an empty input

        if (c >= '0' && c <= '9') {
            // if the character is a digit, convert to an integer, add to sum
            sum += c - '0';
        }
    }

    printf("The sum of the individual digits is: %d\n", sum);  
}
