// Diamonds by Drew Babel


//NOTES: STILL HAS 1 STAR OFF ON BOTH TOP AND BOTTOM PROBLEM
#include <cs50.h>
#include <stdio.h>

void drawDiamonds(int n){
    int spaces = n / 2; //initial spacing pattern according to length
    int direction = -1; // -1 for decreasing, 1 for increasing

    // spaces start at (1/2)(size)-1, then get -1 every time until spaces = 0, then adds every time until back to (1/2)(size)-1

    for(int i = 1; i <= (n % 2 == 0 ? 2 * n : 2 * n - 1); i++) // if even, n*2, otherwise (when its odd), *2 -1
    {
        for(int j = 0; j < n; j++)
        // {
        //     if(j < spaces || j >= n - spaces + 1)
        //     {
        //         printf(" ");
        //     } else {
        //         printf("*");
        //     }
        if (n % 2 == 1 || (n % 2 == 0 && (direction == 1 || spaces != 0)))
        {
            if(j < spaces || j >= n - spaces + 1)
            {
                printf(" ");
            } else {
                printf("*");
            } else {
                if(j < spaces || j > n - spaces - 1)
                {
                    printf(" ");
                } else {
                    printf("*");
                }
            }
        }

        }
        printf("\n");

        if(spaces == 0 && direction == -1){
        direction = 1;
        if (n % 2 == 0)
        {
            i--;
        }
        }
        spaces += direction;

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
