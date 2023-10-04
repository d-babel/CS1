// Cash by Drew Babel

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    const int COIN_VALUES[] = {25, 10, 5, 1};
    const int NUM_COINS = sizeof(COIN_VALUES) / sizeof(int); // Count of avaliable coin denominations

    float change_owed;

    change_owed = get_float("Change owed: ");

    while (change_owed < 0);

    int cents = round(change_owed * 100);
    int total_coins = 0;

    for (int i = 0; i < NUM_COINS; i++)
    {
        while (cents >= COIN_VALUES[i])
        {
            cents -= COIN_VALUES[i];
            total_coins++;
        }
    }

    printf("%d\n", total_coins);
}
