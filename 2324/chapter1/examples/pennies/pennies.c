#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int daysOfMonth, day;                       // num of days in month and current day
    long long initialPennies, totalPennies = 0; // pennies on the first day and total pennies

    do
    {
        daysOfMonth = get_int("Enter number of days: "); // month days (28-31)
    }
    while (daysOfMonth < 28 || daysOfMonth > 31);

    do
    {
        initialPennies = get_long_long("Enter initial pennies: "); // starting pennies (positive)
    }
    while (initialPennies <= 0);

    for (day = 0; day < daysOfMonth; day++) // loop through days
    {
        totalPennies += initialPennies << day; // double pennies each day
    }

    double totalDollars = totalPennies / 100.0;    // convert pennies to dollars
    printf("Total amount: $%.2f\n", totalDollars); // print total amount
}