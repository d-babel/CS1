#include <cs50.dev>
#include <stdio.h>

// Function to convert dog years to human years
double dogToHumanYears(double dogAge) {
    return dogAge * 7;
}

int main() {
    // Ask the user for their dog's age as a double
    double dogAge;
    printf("Please enter your dog's age in dog years: ");
    scanf("%lf", &dogAge);

    // Calculate the dog's age in human years
    double humanAge = dogToHumanYears(dogAge);

    // Format the result to remove trailing zeros
    char formattedAge[20];
    snprintf(formattedAge, sizeof(formattedAge), "%.2lf", humanAge);

    // Print the result
    printf("Your dog is approximately %s years old in human years.\n", formattedAge);

    return 0;
}
