#include <cs50.h>
#include <stdio.h>

int main(void) {
    int pos;
    do {
        pos = get_int("Enter a positive number: ");
    }

    while (pos < 1);
        printf("The positive number is %i\n", pos);
}