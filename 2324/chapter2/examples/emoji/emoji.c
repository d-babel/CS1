//FIX: IF USER INPUTS "U+", IT JUST STOPS, DOESNT RE-REQ

// Emoji by Drew Babel

#include <cs50.h>
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

// needed alias 'emoji' for 'wchar_t' for unicode emoji representation (for readability)
typedef wchar_t emoji;

// function prototype
emoji get_emoji(string prompt);

x
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
        string input = get_string("%s", prompt);
        //check if input starts w/ "U+"
        if (strncmp(input, "U+", 2) == 0)
        {
            // check if rest of input is hexadecimal
            bool is_hex = true;
            // loop checks each char for x
            for (int i = 2; input[i] != '\0'; i++)
            {
                if (!isxdigit(input[i]))
                {
                    is_hex = false;
                    break;
                }
            }
            //convert and return if valid hexadecimal
            if(is_hex)
            {
                long code = strtol(input + 2, NULL, 16);
                return (emoji)code;
            }
        }
    }
}
