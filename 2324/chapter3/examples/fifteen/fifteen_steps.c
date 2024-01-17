/* Step Analysis Exercise
Rules for step tracking
These count as 1 step:
count++
if (x > y)
int x;
int x = 0;

These count as 2 steps:
if (x > y || y > z)
if (tile_row > 0 && board[tile_row - 1][tile_col] == 0)
if (count == d * d)

We don't count these as steps:
for (int i = 0; i < d; i++)
some_function_call() - (because you will be counting steps within the function itself)

*/
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

// Step counter
int steps = 0;

// Saved locations of the blank tile
// int blank_row;
// int blank_col;

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
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
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
    printf("Steps: %i\n", steps);
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
    usleep(2000000);
}

// Initializes the game's board with tiles numbered 1 through d*d - 1
// (i.e., fills 2D array with values but does not actually print them)
void init(void)
{
    steps = 0;
    // fills array counting down to 0
    steps++;
    int counter = d * d - 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // If d is even and counter is 2 make it 1
            steps += 2;
            if (d % 2 == 0 && counter == 2)
            {
                board[i][j] = counter - 1;
                steps++;
            }
            // If d is even and counter is 1 make it 2
            else if (d % 2 == 0 && counter == 1)
            {
                steps += 2; // Conditionally in the case of an else
                board[i][j] = counter + 1;
                steps++;
            }
            else
            {
                board[i][j] = counter;
                steps++;
            }
            counter = counter - 1;
            steps++;
        }
    }
}
/*------Uncomment to see a more efficient solution for init()-------------------------------------------
void init(void)
{
    steps = 0;
    // fills array counting down to 0
    steps++;
    int counter = d * d - 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // count down by subtracting 1 from counter each time
            board[i][j] = counter;
            counter = counter - 1;
            steps += 2;
        }
    }
    // if d is even, switch spots of 1 and 2
    steps++;
    if (d % 2 == 0)
    {
        board[d - 1][d - 2] = 2;
        board[d - 1][d - 3] = 1;
        steps += 2;
    }
}
-------------------------------------------------------------------*/
// Prints the board in its current state
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // if not equal to 0, print array
            if (board[i][j] != 0)
            {
                printf("%2i ", board[i][j]);
            }
            // prints underscore in place of 0 for blank space. identifies coordinates of blank space
            else
            {
                printf(" _ ");
                // blank_row = i;
                // blank_col = j;
            }
        }
        printf("\n");
    }
}

// If tile borders empty space, moves tile and returns true, else returns false
bool move(int tile)
{
    // TODO
    int tile_row;
    int tile_col;
    int blank_row;
    int blank_col;
    // reject numbers that are out of range!
    if (tile < 1 || tile > d*d)
    {
        return false;
    }

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // find tile to move
            if (board[i][j] == tile)
            {
                tile_row = i;
                tile_col = j;
            }
            if (board[i][j] == 0)
            {
                blank_row = i;
                blank_col = j;
            }
        }
    }

    if (tile_row == blank_row && (tile_col - blank_col == 1 || tile_col - blank_col == -1) )
    {
        board[blank_row][blank_col] = tile;
        board[tile_row][tile_col] = 0;
        return true;
    }
    //if same col, and no more than 1 row apart
    //swap tile and o-return true
    if (tile_col == blank_col && (tile_row - blank_row == 1 || tile_row - blank_row == -1) )
    {
        board[blank_row][blank_col] = tile;
        board[tile_row][tile_col] = 0;
        return true;
    }
    // if neither horizontal or vertically aligned, return false
    return false;
}

// Returns true if game is won (i.e., board is in winning configuration), else false
bool won(void)
{
    // TODO
    int count = 1;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // goes through and checks that the boxes are filled counting up from 1
            if (board[i][j] != count)
            {
                return false;
            }
            else
            {
                count = count + 1;
                // stops counting up at the last digit because last digit will equal 0 not d*d
                if (count == (d * d))
                {
                    count = 0;
                }
            }
        }
    }
    return true;
}

