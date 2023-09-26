#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user to input C
    float celsius = get_float("C: ");

    // Convert C to F
    float fahrenheit = ((celsius * 9) / 5) + 32;

    // Print F with 1 decimal
    printf("F: %.1f\n", fahrenheit);

    return 0;
}
