// Converts degrees C to degrees F by collecting info at command line

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> //needed for atof in line 13

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("usage: ./farhenheit <celcius>\n");
        return 1;
    }
    // Get celsius from user
    float celsius = atof(argv[1]); // atof parses the string arugment and returns its value as a float

    // Convert to fahrenheit; no float errors b/c celsius is a float
    float fahrenheit = (celsius * 9) / 5 + 32;
    printf("F: %.1f\n", fahrenheit);
}
