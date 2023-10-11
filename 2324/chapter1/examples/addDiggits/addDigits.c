#include <stdio.h>

int main() {
    printf("Enter a number: ");
    int sum = 0;
    char c;

    while ((c = getchar()) != '\n') {  //check if input is \n
        //the ASCII of '0' is 48, and '9' is 57.
        //so, if the character is in the range from '0' to '9', it means that the user entered a number.
        if (c >= '0' && c <= '9') {
            // Here we convert the character to a numerical value.
            // '0' (48 in ASCII) is subtracted so that the numerical value of '0'... '9' is 0...9.
            // Then the value is added to the sum.
            sum += c - '0';
        }
    }

    printf("The sum of the individual digits is: %d\n", sum); // prints the sum of the digits entered.

}