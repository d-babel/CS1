#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int days_in_month, day;                            // Days and current day
    long long pennies_on_first_day, total_pennies = 0; // First-day pennies and total pennies

    do
    {
        days_in_month = get_int("Days: "); // Month days (28-31)
    }
    while (days_in_month < 28 || days_in_month > 31);

    do
    {
        pennies_on_first_day = get_long_long("Pennies: "); // Starting pennies (positive)
    }
    while (pennies_on_first_day <= 0);

    for (day = 0; day < days_in_month; day++) // Loop through days
    {
        total_pennies += pennies_on_first_day << day; // Double pennies each day
    }

    double total_dollars = total_pennies / 100.0; // Convert pennies to dollars
    printf("$%.2f\n", total_dollars);             // Print total amount

}
