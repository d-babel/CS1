// Greets a user by their name

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Collect a string from the user, then print their name
    string name = get_string("Your name: ");
    printf("Hello, %s!\n", name);
}
