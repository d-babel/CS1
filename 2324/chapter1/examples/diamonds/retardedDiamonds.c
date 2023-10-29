#include <cs50.h>
#include <stdio.h>

void drawDiamonds(int n) {
    int spaces = (n % 2 == 0) ? n / 2 : 0; // Adjusting initialization
    int direction = -1; // -1 for decreasing, 1 for increasing

    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < spaces || j >= n - spaces - 1) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");

        // Adjusting the flip condition
        if ((n % 2 == 0 && spaces == 0) || ((n % 2 != 0 && spaces == 1) && direction == -1)) {
            direction = 1;
        }

        spaces += direction;
    }
}

int main(void) {
    int n;

    do {
        n = get_int("Size? (1-20)");
    } while (n < 1 || n > 20);

    drawDiamonds(n);
}
