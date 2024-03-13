// Pointers by Drew Babel

#include <stdio.h>

int main(void)
{
    void swap(int *x, int *y);

    // int num = 5;
    // int *pnum = &num     ;
    // printf("\nThe value of num is %i.\n", num);
    // printf("The value of num is %p.\n\n", pnum);

    int x = 3;
    int y = 4;
    printf("The value of x is %i and the value of y is %i\n", x, y);
    printf("Swapping...\n");
    swap(&x, &y);
    printf("The new value of x is %i and the new value of y is %i\n", x, y);
}


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
