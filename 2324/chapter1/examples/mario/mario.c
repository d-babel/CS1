// Mario by Drew Babel

// NOTES:
//   put into functions
//      undelcared vars

#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height;

    //input and check if between 1-8 inclusive
    do
    {
        height = get_int("Height:");
    }
    while (height < 1 || height > 8);
    //print pyramid
    for (int i = 1; i < height; i++){

    // spaces
      for (int j = height; j < height -i; j++)
      {
          printf(" ");
      }

    //hashtags for l
      for (int j = 0; j < i; j++)
      {
          printf("#");
      }
     printf("\n");
    }

}
