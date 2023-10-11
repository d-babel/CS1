#include <stdio.h>

int main() {
    printf("Enter a number: ");
    int sum = 0;
    char c;

    while ((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            sum += c - '0';
        }
    }

    printf("The sum of the individual digits is: %d\n", sum);

}
