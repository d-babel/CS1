ls// Implements Game of Fifteen (generalized to d x d) --> by Drew Babel

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants
#define DIM_MIN 3
#define DIM_MAX 9
#define COLOR "\033[32m"

// Board
int board[DIM_MAX][DIM_MAX];

// Dimensions
int d;

// Saved locations of the blank tile
int blank_row;
int blank_col;

// Prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swap(int *a, int *b);
void print_grid_row(int d);
void print_tile(int tile);

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // Ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n", DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // Open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // Greet user with instructions
    greet();

    // Initialize the board
    init();

    // Accept moves until game is won
    while (true)
    {
        // Clear the screen
        clear();

        // Draw the current state of the board
        draw();

        // Log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // Check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // Prompt for move
        int tile = get_int("Tile to move: ");

        // Quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // Log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // Move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // Sleep thread for animation's sake
        usleep(50000);
    }

    // Close log
    fclose(file);

    // Success
    return 0;
}

// Clears screen using ANSI escape sequences
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

// Greets player
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(20000);
}

// steps
int steps = 0;

// Initializes the game's board with tiles numbered 1 through d*d - 1
// (i.e., fills 2D array with values but does not actually print them)
void init(void)
{
    // set tile count (-1 for one less than total spaces on board)
    int tile = d * d - 1;
    steps++;

    // decrease for each space
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++, tile--)
        {
            board[i][j] = tile;
        }
    }

    // change dimensions IF EVEN
    if (d % 2 == 0)
    {
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
    }

    // set blank square on bottom right (will be used to track blank square)
    blank_row = d - 1;
    blank_col = d - 1;
}

// Prints the board in its current state
void draw(void)
{
    // loop each row and column, then print tile/blank
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                printf(" _ ");
            }
            else
            {
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n");
    }

    // new line
}

// If tile borders empty space, moves tile and returns true, else returns false
bool move(int tile)
{
    // loop thru board
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // find tile pos
            if (board[i][j] == tile)
            {
                // abs --> calc absolute value
                if ((abs(blank_row - i) == 1 && blank_col == j) || (abs(blank_col - j) == 1 && blank_row == i))
                {
                    // swap blank and tile
                    board[blank_row][blank_col] = tile;
                    board[i][j] = 0;
                    blank_row = i;
                    blank_col = j;
                    // return t/f to error out non-working moves
                    return true;
                }
            }
        }
    }
    return false;
}

// Returns true if game is won (i.e., board is in winning configuration), else false
bool won(void)
{
    int tile = 1;
    // check order
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // remember, you can not access parts outside the array
            // skip check for last tile (blank tile)
            // [NOTE] POSSIBLY A WAY TO MAKE MORE EFFICIENT WITHOUT CHECKING EVERY LOOP
            if (i == d - 1 && j == d - 1)
            {
                return true;
            }
            // check if not correct order
            if (board[i][j] != tile)
            {
                return false;
            }
            tile++;
        }
    }

    // return win

    return false;
}

// TESTING WON FUNCTION:
// ./fifteen 3 < 3x3.txt
// ./fifteen 4 < 4x4.txt
