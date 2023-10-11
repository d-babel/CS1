#include <ctype.h>
#include <stdio.h>

int main()
{
    char input[100];
    int sum = 0;
    int validInput = 0;

    while (!validInput)
    {
        printf("Enter a number: ");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            // check if fgets encountered an error (e.g., end of file or read error).
            // if so handle the error as needed
        }

        validInput = 1; // assume valid input until proven otherwise.
        sum = 0;        // initialize the sum to zero.

        for (int i = 0; input[i] != '\0'; i++)
        {
            if (isdigit(input[i]))
            {
                // if the current character is a digit, convert it to an integer, add it
                sum += input[i] - '0';
            }
            else if (input[i] != '\n')
            {
                // if current character is not digit and not  newline character, input invalid
                validInput = 0;
            }
        }
    }

    printf("Sum of the individual digits: %d\n", sum);
}
