// Mario by Drew Babel

// NOTES:
//   put into functions

#include <cs50.h>
#include <stdio.h>
#define MIN_HEIGHT 1
#define MAX_HEIGHT 8

// int main(void)
// {

//     int height;

//     // input and check if between 1-8 inclusive
//     do
//     {
//         height = get_int("Height:");
//     }
//     while (height < MIN_HEIGHT || height > MAX_HEIGHT);
//     // print pyramid
//     for (int i = 1; i <= height; i++)
//     {
//         // spaces
//         for (int j = 0; j < height - i; j++)
//         {
//             printf(" ");
//         }

//         // hashtags
//         for (int j = 0; j < 2 * i + 1; j++)
//         {
//             // spaces between pyramids
//             if (j == i)
//             {
//                 printf("  ");
//             }
//             else
//             {
//                 printf("#");
//             }
//         }
//         printf("\n");
//     }
// }

// //spaces
// void print_spaces(int count)
// {
//     for (int j = 0; j < count; j++)
//     {
//         printf(" ");
//     }
// }

// //hashtags
// void print_hashtags(int count, int middle_space)
// {
//     for (int j = 0; j < count; j++)
//     {
//         if (j == middle_space)
//         {
//             printf("  ");
//         }
//         else
//         {
//             printf("#");
//         }
//     }
// }

// int main(void)
// {
//     int height;

//     //input
//     do
//     {
//         height = get_int("Height:");
//         }
//         while (height < MIN_HEIGHT || height > MAX_HEIGHT);
//             for (int i = 1; i <= height; i++)
//             {
//                 //output using functions instead
//                 print_spaces(height - i);
//                 print_hashtags(2 * i + 1, i);
//                 printf("\n");
//             }
// }