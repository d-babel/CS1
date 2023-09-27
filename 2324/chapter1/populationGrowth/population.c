#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask for starting population size
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // Ask for ending population size
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    int years = 0;

    // Calculate number of years required for the population to reach end size
    while (start_size < end_size)
    {
        int born = start_size / 3;
        int passed_away = start_size / 4;
        start_size = start_size + born - passed_away;
        years++;
    }

    // Print number of years required
    printf("Years: %i\n", years);
}
