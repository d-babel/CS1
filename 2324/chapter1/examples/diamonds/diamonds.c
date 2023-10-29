// Diamonds by Drew Babel

#include <cs50.h>
#include <stdio.h>

void drawDiamonds(int n){

    // odd
    for (size % 2 != 0)
    {
        //top half
        for (int i = 1; i <= (size +1) / 2; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                printf(" "):
            }
            for (int j = 0; j < 2 * i - 1; j++)
            {
                if (j % 2 == 0) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        //bottom half
        for (int i = (size -1) / 2; i >= 1; i--)
        {
            for (int j = 0; j < 2 * i - 1; j++)
            {
                printf(" ");
            }
            for (int j = 0; j < 2 * i - 1; j++)
            {
                if (j % 2 == 0){
                    printf("*");
                } else {
                    printf(" ");
                }
                print("\n");
            }
            printf("\n");
        }

    }
    else
    {
        for (int i = 1; i <= (size / 2) ; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                printf(" "):
            }
            for (int j = 0; j < 2 * i - 1; j++)
            {
                if (j % 2 == 0) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        //bottom half
        for (int i = (size / 2); i >= 1; i--)
        {
            for (int j = 0; j < size - i; j++)
            {
                printf(" ");
            }
            for (int j = 0; j < 2 * i - 1; j++)
            {
                if (j % 2 == 0){
                    printf("*");
                } else {
                    printf(" ");
                }

            }
            print("\n");
    }
}

int main(void)
{
    int n; // var for drawDiamonds

    do {
        n = get_int("Size? (1-20)"); //input
    }
    while (n < 1 || n > 20);
        drawDiamonds(n);
}
