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

// Steps
int steps = 0;

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

// Initialize the game board
void init(void)
{
    steps = 0; // Reset steps
    int tile = d * d - 1;
    steps++;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++, tile--)
        {
            board[i][j] = tile;
            steps++;
        }
    }

    steps++;
    if (d % 2 == 0)
    {
        swap(&board[d - 1][d - 3], &board[d - 1][d - 2]);
    }

    blank_row = d - 1;
    blank_col = d - 1;
    steps += 2;
    printf("Steps in initialize: %i\n", steps);
}

// Draw the board
void draw(void)
{
    steps = 0; // Reset steps
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            steps++;
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

    printf("Steps in draw: %i\n", steps);
}

// Move a tile
bool move(int tile)
{
    steps = 0; // Reset steps
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            steps++;
            if (board[i][j] == tile)
            {
                steps += 4;
                if ((abs(blank_row - i) == 1 && blank_col == j) || (abs(blank_col - j) == 1 && blank_row == i))
                {
                    swap(&board[blank_row][blank_col], &board[i][j]);
                    blank_row = i;
                    blank_col = j;
                    steps += 4;
                    printf("Steps in move: %i\n", steps);
                    return true;
                }
            }
        }
    }
    printf("Steps in move: %i\n", steps);
    return false;
}

// Check if the player has won
bool won(void)
{
    steps = 0; // Reset steps
    int tile = 1;
    steps++;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            steps++;
            if (i == d - 1 && j == d - 1)
            {
                if (board[i][j] == 0)
                {
                    printf("Steps in won: %i\n", steps);
                    return true;
                }
                else
                {
                    printf("Steps in won: %i\n", steps);
                    return false;
                }
            }

            steps++;
            if (board[i][j] != tile)
            {
                printf("Steps in won: %i\n", steps);
                return false;
            }
            tile++;
            steps++;
        }
    }

    printf("Steps in won: %i\n", steps);
    return false;
}

// Swap two integers
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
