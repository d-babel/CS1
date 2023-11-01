// Calculates how many pennies a user would get if their change doubles each day using command line information

#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Defined constants
#define MAX_DAYS 31
#define MIN_DAYS 28

int main(void)
{
    // Get a number of days in [28, 31]
    int days;
    do
    {
        days = get_int("Days in month: ");
    }
    while (days < MIN_DAYS || days > MAX_DAYS);

    // Get a number of pennies in [0, inf)
    int pennies;
    do
    {
        pennies = get_int("Pennies on first day: ");
    }
    while (pennies <= 0);

    // Relatively few pennies required to get out of bounds of int
    long long total = pennies;

    // Add double the amount of pennies of the previous day each day
    for (int i = 1; i < days; i++)
    {
        total += pennies * pow(2, i);
    }

    // Output the total as dollars and cents only
    printf("$%.2f\n", ((double) total) / 100);
}
