// ISBN by Drew Babel

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long isbn = get_long("ISBN: ");

    int sum = 0;
    int position = 10;

    // loop through digits of ISBN
    while (isbn > 0)
    {
        // rightmost digit
        int digit = isbn % 10;
        sum += digit * position;
        // move to  next position
        position--;

        // remove rightmost digit from ISBN
        isbn /= 10;
    }

    // check sum divisible by 11 without remainder
    if (sum % 11 == 0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}
