#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    const int COINS[] = {25, 10, 5, 1};
    int coins = 0, cents = round(get_float("Change owed: ") * 100);

    while (cents < 0) {
        cents = round(get_float("Change owed: ") * 100);
    }

    for (int i = 0; i < 4; i++) {
        while (cents >= COINS[i]) {
            cents -= COINS[i];
            coins += 1;
        }
    }

    printf("%d\n", coins);
}