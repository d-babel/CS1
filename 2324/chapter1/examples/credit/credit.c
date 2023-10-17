#include <stdio.h>
#include <cs50.h>

#define AMEX_START 34
#define AMEX_ALT_START 37
#define MASTERCARD_START_MIN 51
#define MASTERCARD_START_MAX 55
#define VISA_START 4

int main(void)
{
    long card = get_long("Number: "), t = card, s = 0, d, c = 0, f = card;

    while (f >= 100)
        f /= 10;

    while (t)
        d = t % 10, s += (c++ % 2) ? d / 5 + d * 2 % 10 : d;
        t /= 10;

    printf((s % 10 == 0) && (c == 15 && (f == AMEX_START || f == AMEX_ALT_START) || (c == 16 && f >= MASTERCARD_START_MIN && f <= MASTERCARD_START_MAX) || (c == 13 || c == 16) && f / 10 == VISA_START) ? "VALID\n" : "INVALID\n");
}
