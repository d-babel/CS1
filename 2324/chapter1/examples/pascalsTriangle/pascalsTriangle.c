// Regular Pascal's Triangle

#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    // check if the input is a positive integer
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // loop to iterate through each row
    for (int i = 0; i < n; i++) {
        int c = 1;

        // print leading spaces to create a pyramid pattern
        for (int j = 0; j < n - i; j++)
            printf("  ");

        // calculate and print the values for each row
        for (int j = 0; j <= i; j++) {
            // calculate and print the binomial coefficient
            printf("%4d  ", c);
            c = c * (i - j) / (j + 1);
        }

        // move to the next line for the next row
        printf("\n");
    }
}
