#include <cs50.h>
#include <stdio.h>


// Function to convert dog years to human years
int dogToHumanYears(int dogAge) {
    return dogAge * 7;
}

int main() {
    printf("Please enter your dog's age in dog years: ");
    int dogAge;
    scanf("%d", &dogAge);

    int humanAge = dogToHumanYears(dogAge);

    printf("Your dog is approximately %d years old in human years.\n", humanAge);

    return 0;
}


/*

int main()

    // Ask the user for their dog's age
    int dogAge;
    printf("Please enter your dog's age in dog years: ");
    scanf("%d", &dogAge);

    // Figure out how old the dog is in human years
    int humanAge = dogAge * 7;

    // Print the result
    printf("Your dog is approximately %d years old in human years.\n", humanAge);

    return 0;
}


*/