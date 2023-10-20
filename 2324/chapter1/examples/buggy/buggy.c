// My Buggy Code by Mr. Kiang
// Copy and paste this code into your IDE
// Place a breakpoint by clicking to the left of Line 13
// Use debug50 buggy to debug it.
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    long long cc = get_long("Enter a long number: ");
    int sum = 0;
    while (cc > 0)
    {
        cc = cc / 10;
        sum += cc % 10;
    }
    printf("The sum is %i\n",sum);
}
