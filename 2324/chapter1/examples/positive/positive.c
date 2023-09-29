#include <cs50.h>
#include <stdio.h>

int main(void) {
    int pos;

    pos = get_int("Enter a positive number: ");

    while (pos < 0) {
        printf("Please enter a positive number: ");
        pos = get_int();
    }

    printf("The positive number is %i\n", pos);
}
