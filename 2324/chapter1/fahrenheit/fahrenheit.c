#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float celsius = get_float("C: ");

    float fahrenheit = (celsius * 9 / 5) + 32;
    
    printf("F: %.1f\n", fahrenheit);

}
