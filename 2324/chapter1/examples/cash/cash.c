// Cash by Drew Babel

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    const int COINS[] = {25, 10, 5, 1};

    // keep track of the number of coins used and the change owed in cents.
    int coins = 0, cents = round(get_float("Change owed: ") * 100);

    // Ensure that the user inputs a non-negative value for change owed.
    while (cents < 0) {
        cents = round(get_float("Change owed: ") * 100);
    }

    // Iterate through the array of coin values and calculate the number of each coin needed.
    for (int i = 0; i < 4; i++) {
        while (cents >= COINS[i]) {
            cents -= COINS[i];
            coins += 1;
        }
    }

    // Print the total number of coins used to make the change.
    printf("%d\n", coins);
}
