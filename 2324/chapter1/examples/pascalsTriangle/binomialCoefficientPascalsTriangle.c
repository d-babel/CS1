// Binomial Coefficient Pascal's Trangle by Drew Babel

#include <stdio.h>

// calc the factorial of a number
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// calc binomial coefficient C(n, k)
unsigned long long binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// print a row of Pascal's triangle
void printPascalsRow(int row, int numRows) {
    for (int i = 0; i < numRows - row; i++) {
        printf("  "); // spaces for formatting
    }
    for (int i = 0; i <= row; i++) {
        printf("%4llu  ", binomialCoefficient(row, i)); // print coefficients
    }
    printf("\n");
}

int main() {
    int numRows;

    // ask user for num of rows
    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &numRows);

    if (numRows <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // print Pascal's triangle
    for (int i = 0; i < numRows; i++) {
        printPascalsRow(i, numRows);
    }
}
