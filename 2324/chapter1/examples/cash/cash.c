// Cash by Drew Babel

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    const int COIN_VALUES[] = {25, 10, 5, 1};
    const int NUM_COINS = sizeof(COIN_VALUES) / sizeof(int); // Number of coin denominations

    float change_owed; // Initialize a variable to store the amount of change owed

    do
    {
        change_owed = get_float("Change owed: "); // Prompt the user for the amount of change owed
    }
    while (change_owed < 0); // Repeat until a non-negative value is entered

    int cents = round(change_owed * 100); // Convert the dollar amount to cents and round it to the nearest cent
    int total_coins = 0; // Initialize a variable to count the total number of coins needed for change

    for (int i = 0; i < NUM_COINS; i++) // Loop through each coin denomination
    {
        while (cents >= COIN_VALUES[i]) // While the remaining change is greater than or equal to the current coin denomination
        {
            cents -= COIN_VALUES[i]; // Subtract the coin value from the remaining change
            total_coins++; // Increment the total coin count
        }
    }

    printf("%d\n", total_coins); // Print the total number of coins needed for change
}
