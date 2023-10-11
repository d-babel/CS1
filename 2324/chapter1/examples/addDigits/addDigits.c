#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    int sum = 0;
    char input[100]; // use an array to store users input to 100 digits

    while (true) {
        printf("Enter a number: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // handle input error
            printf("Error reading input.\n");
            return 1;
        }

        int i = 0;
        bool valid = true; // Assume the input is valid until proven otherwise

        while (input[i] != '\0' && input[i] != '\n') {
            if (!isdigit(input[i])) {
                // If any character is not a digit, it's an invalid input
                valid = false;
                break;
            }
            sum += input[i] - '0';
            i++;
        }

        if (valid) {
            printf("The sum of the individual digits is: %d\n", sum);
            break; // Exit the loop if input is valid
        } else {
            printf("Invalid input. Please enter a valid number.\n");
            sum = 0; // Reset the sum for the next input attempt
        }
    }
}
