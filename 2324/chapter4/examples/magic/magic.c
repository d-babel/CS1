// Magic By Drew Babel

/* Magic Squares
*  A magic square is a grid whose numbers add up to the same value
*  across all rows, columns, and diagonals. Below are a number of
*  4x4 grids. Some are magic squares, and some are not. Write a
*  function that returns true iff the sum of all four numbers in
*  an array matches a constant. Then, write a function that checks
*  each row, column, and diagonal of an uncommented grid and returns
*  true iff the grid is a magic square.
*  Skills: Create a 1d array, Traverse a 1d and 2d array, Call functions with parameters
*/
#include <stdio.h>
#include <stdbool.h>
#define MAGIC_SUM 34

bool is_magic();
bool is_valid(int arr[]);

// This board is NOT magic.
// int board[4][4] = {{ 6, 13,  4, 11},
//                    { 3, 16, 11,  4},
//                    { 7, 12,  9,  6},
//                    {11, 13,  3,  7}};

// This board is magic!
int board[4][4] = {{ 7, 12,  1, 14},
                   { 2, 13,  8, 11},
                   {16,  3, 10,  5},
                   { 9,  6, 15,  4}};

// This board is not magic.
// int board[4][4] = {{14,  3,  7, 11},
//                    {11,  7, 12,  9},
//                    {7, 13,  4, 15},
//                    {11,  3, 16,  7}};


// This board is magic!
// int board[4][4] = {{16,  3,  2, 13},
//                    {5, 10, 11,  8},
//                    {9,  6,  7, 12},
//                    {4, 15, 14,  1}};

int main(void)
{
    if (is_magic())
    {
        printf("Is magic\n");
    }
    else
    {
        printf("No magic here\n");
    }
}

// Returns true iff all rows, columns, and diagonals are valid.
bool is_magic()
{
    //storage
    int arr[4];

    // rows
    for (int i = 0; i < 4; i++){
        //run thru is_valid
        if (!is_valid(board[i])){
            return false;
        }
    }

    // cols
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            //copy over
            arr[j] = board[j][i];
        }
        //run thru is_valid
        if (!is_valid(arr)){
            return false;
        }
    }

    //diagonals
    for (int i = 0; i < 4; i++){
        arr[i] = board[i][i];
    }
    return true;

    //corners
    for (int i = 0; i < 4; )
}

// Returns true iff the sum of all four numbers in arr matches sum.
bool is_valid(int arr[])
{
    // Create an int variable called sum
    int sum = 0;
    // Iterate over arr
    for(int i = 0; i < 4; i++){
        // For each element in arr add it to sum
        sum += arr[i];
    }

    // If sum == MAGIC_SUM return true
    return sum == MAGIC_SUM;
    return false;
}
