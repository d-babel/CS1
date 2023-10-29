#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for diamond size using the get_int function from the CS50 library
    int size = get_int("size? ");

    // For odd-sized diamonds
    if (size % 2 != 0)
    {
        // Print top half of the diamond
        for (int i = 1; i <= (size + 1) / 2; i++)
        {
            for (int j = 0; j < size - i; j++)
            {
                printf(" ");
            }
            for (int j = 0; j < 2 * i - 1; j++)
            {
                if (j % 2 == 0)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }

        // Print bottom half of the diamond
        for (int i = (size - 1) / 2; i >= 1; i--)
        {
            for (int j = 0; j < size - i; j++)
            {
                printf(" ");
            }
            for (int j = 0; j < 2 * i - 1; j++)
            {
                if (j % 2 == 0)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }

    // For even-sized diamonds
    else
    {
        // Print top half of the diamond
        for (int i = 1; i <= size / 2; i++)
        {
            for (int j = 0; j < size - i; j++)
            {
                printf(" ");
            }
            for (int j = 0; j < 2 * i - 1; j++)
            {
                if (j % 2 == 0)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }

        // Print bottom half of the diamond (including double middle for even sizes)
        for (int i = size / 2; i >= 1; i--)
        {
            for (int j = 0; j < size - i; j++)
            {
                printf(" ");
            }
            for (int j = 0; j < 2 * i - 1; j++)
            {
                if (j % 2 == 0)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}
