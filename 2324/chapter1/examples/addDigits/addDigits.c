#include <stdio.h>

int main() {
    printf("Enter a number: ");
    int sum = 0;
    char c;

    int isValidInput = 1; // Flag to check if the input is valid

    while ((c = getchar()) != '\n') {  // Check until an empty input
        if (c == '-') {
            // handle negative sign
            if (sum != 0) {
                // if there are already digits in the sum, the input is invalid
                isValidInput = 0;
                break;
            }
        }
        else if (c >= '0' && c <= '9') {
            // if the character is a digit, convert to an integer, add to sum
            sum += c - '0';
        }
        else {
            // if character is not digit or negative sign, the input is invalid
            isValidInput = 0;
            break;
        }
    }

    if (isValidInput) {
        printf("The sum of the individual digits is: %d\n", sum);
    } else {
        printf("Invalid input. Please enter a valid number.\n");
    }

    return 0;
}
