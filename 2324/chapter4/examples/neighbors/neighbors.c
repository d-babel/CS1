// TO TEST, USE THIS check50 COMMAND:
// check50 dkiang/checks/master/neighbors

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#define DIM 5

int grid[DIM][DIM] = {{1, 2, 3, 4, 5},
                      {2, 3, 4, 5, 6},
                      {3, 4, 5, 6, 7},
                      {4, 5, 6, 7, 8},
                      {5, 6, 7, 8, 9}};

int add_neighbors(int r, int c);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./neighbors [row] [col]\n");
        return 1;
    }

    int row = atoi(argv[1]);
    int col = atoi(argv[2]);

    if (row < 0 || col < 0 || row >= DIM || col >= DIM)
    {
        printf("row and col must be nonnegative integers less than %i.\n", DIM);
        return 2;
    }
    int sum = add_neighbors(row, col);
    printf("The sum of all the neighbors to row %i and column %i is %i.\n", row, col, sum);
}


/* add_neighbors will add together all adjacent values in grid
   to the given location, INCLUDING the location.
   For example: add_neighbors(0, 0) returns 8.
                add_neighbors(2, 2) returns 45.
                add_neighbors(2, 4) returns 39.
   */
int add_neighbors(int r, int c)
{
    int sum = 0;

    //loop over adjacent row/col
    for(int i = r - 1; i <= r; i++){
        for(int j = c - 1; j <= r; j++){
            //check if within boundaries
        if (i >= 0 && i < DIM && j >= 0 && j < DIM){
            sum += grid[i][j];
            }
        }
    }
    return sum;
}
