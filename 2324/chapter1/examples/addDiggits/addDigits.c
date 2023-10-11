#include <stdio.h>

int main() {
    printf("Enter a number: ");
    int sum = 0;  
    char c;  // Declare a variable to store the input character

    // Read characters until Enter (newline) is pressed
    while ((c = getchar()) != '\n') {  // Check for empty input

        if (c >= '0' && c <= '9') {
            // If the character is a digit, convert to an integer, add to sum
            sum += c - '0';
        }
    }

    printf("The sum of the individual digits is: %d\n", sum);  // Print the sum
}
