// Mario by Drew Babel

// NOTES:
//   put into functions

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // input
    int height = get_int("Height:");

    // spaces
    for (int i = height; i < 0; i--)
    {
        printf(" ");
    }
    for (int i = 1; i <= height; i++)
    {
        printf("#");
    }
    printf("\n");
}
