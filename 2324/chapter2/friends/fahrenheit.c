// Converts degrees C to degrees F by collecting info at command line

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get celsius from user
    float celsius = get_float("C: ");

    // Convert to fahrenheit; no float errors b/c celsius is a float
    float fahrenheit = (celsius * 9) / 5 + 32;
    printf("F: %.1f\n", fahrenheit);
}
