#include <cs50.dev>
#include <stdio.h>

int main() {
    int userAge;
    printf("Please enter your age: ");
    scanf("%d", &userAge);

    // Assuming 1 human year is equivalent to 7 dog years
    float dogYears = userAge * 7.0;

    printf("You are %.2f years old in dog years.\n", dogYears);

    return 0;
}
