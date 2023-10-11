#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    int sum = 0;
    char input[100]; // Use an array to store the user's input

    while (true) {
        printf("Enter a number: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle input error
            printf("Error reading input.\n");
            return 1;
        }

        int i = 0;
        bool valid = true; // Assume the input is valid until proven otherwise

        while (input[i] != '\0' && input[i] != '\n') {
            if (input[i] == '-' && i == 0) {
                // Negative sign is allowed only at the beginning
                i++;
            } else if (isdigit(input[i])) {
                sum += input[i] - '0';
                i++;
            } else {
                // If any character is not a digit, it's an invalid input
                valid = false;
                break;
            }
        }

        if (valid) {
            printf("The sum of the individual digits is: %d\n", sum);
            break; // Exit the loop if input is valid
        } else {
            printf("Invalid input. Please enter a valid number.\n");
            sum = 0; // Reset the sum for the next input attempt
        }
    }

    return 0;
}
