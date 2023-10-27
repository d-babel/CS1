// Diamonds by Drew Babel

#include <cs50.h>
#include <stdio.h>

//input
int size = get_int("Size? ");

int drawDiamonds(int n){
    int spaces = n / 2 - 1;
    int stars = 1;
    int direction = -1


    // spaces start at (1/2)(size)-1, then get -1 every time until spaces = 0, then adds every time until back to (1/2)(size)-1
    for(int i = 1; i <= (i % 2 == 0 ? 2 * n : n - 1; i--))
    {
        for(int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
    }
}



int main(void)
{

}
