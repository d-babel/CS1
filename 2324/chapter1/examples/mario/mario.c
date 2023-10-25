// Mario by Drew Babel

// NOTES:
//   put into functions

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // input
    int height = get_int("Height:");


    for (int i = 1; i <= height; i++){
    // spaces
      for (int j = height; j < height -i; j++)
      {
          printf(" ");
      }
      for (int j = 0; i < i; j++)
      {
          printf("#");
      }
     printf("\n");
    }

}
