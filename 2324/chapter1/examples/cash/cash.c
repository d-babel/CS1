#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Define constants for coin values
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
const int PENNY = 1;

int main(void)
{
    float change_owed;
    int coins[] = {QUARTER, DIME, NICKEL, PENNY};  // Array to store coin values
    int total_coins = 0;  // Variable to store the total number of coins

    do
    {
        change_owed = get_float("Change owed: ");  // Get user input for change owed
    }
    while (change_owed < 0);  // Ensure input is non-negative

    int cents = round(change_owed * 100);  // Convert dollars to cents and round

    // Calculate minimum number of coins required
    for (int i = cents; i > 0;)  // Iterate while there is change left
    {
        for (int j = 0; i >= coins[j]; i -= coins[j++], total_coins++);  // Calculate each coin
    }

    printf("%d\n", total_coins);  // Print minimum number of coins

    return 0;
}
