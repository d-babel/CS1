//cdSnowflake by Drew Babel

// Snowflake Demo
#include <stdio.h>
#define DIM 10

void init(void);
void draw(void);
// TODO #1
// Declare a 2D char array like this:
// data-type board[size][size]
char board[DIM][DIM];

int main(void)
{
    init();
    draw();
}

// Fills the array
void init(void)
{
    // TODO #2
    // fill 2d array with *s
    // Optionally, change certain locations to ' '
    for (int i = 0; i < DIM; i++)
    {
        // Another nested loop goes here
        for (int j = 0; j < DIM; j++){
            board[i][j] = '*';
        }
        printf("\n");
    }
}

void draw(void)
{
    // TODO #3
    // Nested loop
    // Write the code that prints the board.
    for (int i = 0; i < DIM; i++)
    {
        // Another nested loop goes here
        for (int j = 0; j < DIM; j++){
            board[i][j] = '*';
        }
        printf("\n");
    }
}

