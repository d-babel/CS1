// Mario by Drew Babel

// NOTES:
//   put into functions
//      undelcared vars

#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height;

    // input and check if between 1-8 inclusive
    do
    {
        height = get_int("Height:");
    }
    while (height < 1 || height > 8);
    // print pyramid
    for (int i = 1; i <= height; i++)
    {
        // spaces
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // hashtags
        for (int j = 0; j < 2 * i + 2; j++)
        {
            // spaces between pyramids
            if (j == i)
            {
                printf("  ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
