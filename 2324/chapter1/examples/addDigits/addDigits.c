#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    int sum = 0;
    int validInput = 0;

    while (!validInput) {
        printf("Enter a number: ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
        }

        validInput = 1;
        sum = 0;

        for (int i = 0; input[i] != '\0'; i++) {
            if (isdigit(input[i])) {
                sum += input[i] - '0';
            } else if (input[i] != '\n') {
                validInput = 0;
            }
        }
    }

    printf("Sum of the individual digits: %d\n", sum);
}
