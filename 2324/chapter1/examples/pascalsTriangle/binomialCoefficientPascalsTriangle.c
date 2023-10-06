// (Binomial Coefficient) Pascals Triangle by Drew Babel

#include <stdio.h>

// calculate the factorial of a number
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++) fact *= i; // multiply by all integers from 2 to n
    return fact;
}

// calculate binomial coefficient C(n, k)
unsigned long long binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k)); // formula for binomial coefficient
}

// print row of Pascal's triangle with formatting
void printPascalsRow(int row, int numRows) {
    for (int i = 0; i < numRows - row; i++) printf("  "); // leading spaces
    for (int i = 0; i <= row; i++) printf("%4llu  ", binomialCoefficient(row, i)); // coefficients
    printf("\n");
}

int main() {
    int numRows;

    // ask user for num of rows for Pascal's triangle
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
