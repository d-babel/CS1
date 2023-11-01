// Diamonds by Drew Babel

#include <cs50.h>
#include <stdio.h>

//#include <unistd.h>
// int usleep(__useconds_t useconds);

void drawDiamonds(int n);

int main(void)
{
    int n; // var for drawDiamonds

    do
    {
        n = get_int("Size: "); // input
    }
    while (n < 1 || n > 20);
    drawDiamonds(n);
}

void drawDiamonds(int n)
{

    // odd
    if (n % 2 != 0)
    {
        // top half
        for (int i = 1; i <= (n + 1) / 2; i++)
        {
            for (int j = 0; j <= (n - 1) / 2 - i; j++)
            {
                printf(" ");
            }
            for (int j = 0; j < 2 * i - 1; j++)
            {
                if (j % 2 == 0)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // bottom half
        for (int i = (n - 1) / 2; i >= 1; i--)
        {
            for (int j = 0; j < (n - 1) / 2 - i + 1; j++)
            {
                printf(" ");
            }
            for (int j = 0; j < 2 * i - 1; j++)
            {
                if (j % 2 == 0)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = 1; i <= (n / 2); i++)
        {
            for (int j = 0; j < n / 2 - i; j++)
            {
                printf(" ");
            }
            for (int j = 0; j < 2 * i - 1; j++)
            {
                if (j % 2 == 0)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // bottom half
        for (int i = (n / 2); i >= 1; i--)
        {
            for (int j = 0; j < n / 2 - i; j++)
            {
                printf(" ");
            }
            for (int j = 0; j < 2 * i - 1; j++)
            {
                if (j % 2 == 0)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}
