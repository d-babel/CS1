// Caesar by Drew Babel

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_COUNT 26

bool is_numerical(string key);
void encrypt(string plaintext, int key);

int main(int argc, string argv[])
{
    // Check if the user provided the correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check for proper key values
    if (!is_numerical(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    // Convert the key to an integer
    int key = atoi(argv[1]);

    // Get the plaintext from the user
    string plaintext = get_string("plaintext:  ");

    // Perform Caesar cipher encryption
    encrypt(plaintext, key);

    // Print the ciphertext
    printf("ciphertext: %s\n", plaintext);

    return 0;
}


bool is_numerical(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}


// Function to perform Caesar cipher encryption on all letters.
// Each letter should be offset by key, wrapping around from
// Z to A and from z to a.
// Example:
// caesar_encrypt("ABC xyz!", 2) changes the string to "CDE zab!"
void encrypt(string plaintext, int key)
{
    //iterate over string plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        //check if current letter = real letter (uppercase & lowercase)
        if (isalpha(plaintext[i]))
        {
            //determine base ascii value ('A' for uppercase, 'a' for lowercase)
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            //subtract the base for A-Z or a-z
            //add key to shift char
            //use % to wrap around alphabet
            //then add base back on correct ascii range
            plaintext[i] = (plaintext[i] - base + key) % ALPHABET_COUNT + base;
        }
    }

}
