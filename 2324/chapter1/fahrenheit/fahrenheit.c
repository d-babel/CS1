#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for input in Celsius
    float celsius = get_float("C: ");

    // Convert Celsius to Fahrenheit using the formula
    float fahrenheit = ((celsius * 9) / 5) + 32;

    // Display the result with one decimal place
    printf("F: %.1f\n", fahrenheit);

    return 0;
}
