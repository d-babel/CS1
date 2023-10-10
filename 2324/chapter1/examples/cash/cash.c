// Cash by Drew Babel

#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    const int COINS[] = {25, 10, 5, 1};

    int coins = 0, cents = round(get_float("Change owed: ") * 100); // keep track of number of coins used and change owed in cents.

    while (cents < 0)
    { // check for non-negative value for change owed
        cents = round(get_float("Change owed: ") * 100);
    }

    // iterate through coin value array and calc num of each coin needed
    for (int i = 0; i < 4; i++)
    {
        while (cents >= COINS[i])
        {
            cents -= COINS[i];
            coins ++;
        }
    }

    // print total coins used
    printf("%d\n", coins);
}check50 cs50/problems/2019/ap/cash

