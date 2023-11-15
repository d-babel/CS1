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

//input

// emoji function
    // check if input starts with "U+"
    // check if the rest of the input is hexadecimal
    // convert and return if valid hexadecimal

