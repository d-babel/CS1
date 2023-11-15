// #include <locale.h>
// #include <stdio.h>
// #include <wchar.h>

// int main(void)
// {
//     setlocale(LC_ALL, "");
//     wchar_t pumpkin = 0x1F383;
//     printf("%lc\n", pumpkin);
// }

// Emoji by Drew Babel

#include <cs50.h>
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

// needed alias 'emoji' for 'wchar_t' for unicode emoji representation

int main(void)
{
    setlocale(LC_ALL, "");
    emoji emojiChar = get_emoji("Code point: ");
    printf("%lc\n", emojiChar);
}

emoji get_emoji(string prompt)
{
    //loop until break
    while(true)
    {
        //check if input starts w/ "U+"
        if (strncmp(input"U+", 2) == 0)
        {
            // check if rest of input is hexadecimal
        }
    }
}

//input

// emoji function
    // check if the rest of the input is hexadecimal
    // convert and return if valid hexadecimal

