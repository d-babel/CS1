#include <cs50.h>
#include <stdio.h>

int main(void) {
    // Request the initial population size
    int start;
    do {
        start = get_int("Enter the starting population: ");
    } while (start < 9);

    // Request the target population size
    int end;
    do {
        end = get_int("Enter the ending population: ");
    } while (end < start);

    int years = 0;

    // Calculate the number of years needed to reach the target population
    while (start < end) {
        int births = start / 3;
        int deaths = start / 4;
        start = start + births - deaths;
        years++;
    }

    // Output the number of years needed
    printf("Years: %i\n", years);
}
