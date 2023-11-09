// Cash by Drew Babel

#include <cs50.h>
#include <math.h>
#include <stdio.h>

//DEFINE MAGIC NUMBERS FOR READABILITY
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int main(void)
{
    const int COINS[] = {QUARTER, DIME, NICKEL, PENNY};

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
            coins++;
        }
    }

    // print total coins used
    printf("%d\n", coins);
}
