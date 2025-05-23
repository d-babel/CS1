/**
 * Sudoku
 *
 * More Spicy version for CS1 @ Menlo School
 * Based on the CS50 Problem Set
 * Starter code written by Zach Blick
 * With help from Douglas Kiang
 * Rest of code written by Drew Babel
 * on Monday, Aug. 14 2023
 */

#include "sudoku.h"
#include <ctype.h>
#include <ncurses.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Macro for processing control characters
#define CTRL(x) ((x) & ~0140)

// Size of each int (in bytes) in *.bin files
#define INTSIZE 4

// valid moves
#define VALID_MOVE 0
#define BAD_ROW 1
#define BAD_COL 2
#define BAD_BOX 3

// global flag for if game won
bool gameWon = false;

// struct to keep track of last move
struct
{
    int row;
    int col;
    int prevVal;
} lm;

// Wrapper for our game's globals
struct
{
    // The current level
    char *level;

    // The game's board
    int board[9][9];

    // The board's number
    int number;

    // The board's top-left coordinates
    int top, left;

    // The cursor's current location between (0,0) and (8,8)
    int y, x;

    // distinguish between editable v/ non-editable
    bool initialBoardEditable[9][9];

} g;

// Prototypes
void draw_grid(void);
void draw_borders(void);
void draw_logo(void);
void draw_numbers(void);
void draw_won_nums(void);
void hide_banner(void);
bool load_board(void);
void handle_signal(int signum);
void log_move(int ch);
void redraw_all(void);
bool restart_game(void);
void show_banner(char *b);
void show_cursor(void);
void shutdown(void);
bool startup(void);
int checkMove(int row, int col, int num);
bool checkRow(int row, int num);
bool checkCol(int col, int num);
bool checkBox(int row, int col, int num);
bool isValidUnit(int unit[9]);
bool isGameWon(void);
void undo_move(void);

int main(int argc, char *argv[])
{
    // invalid starting state
    lm.row = -1;
    lm.col = -1;
    lm.prevVal = -1;

    // Ensure that number of arguments is as expected
    if (argc != 2 && argc != 3)
    {
        fprintf(stderr, "Usage: sudoku n00b|l33t [#]\n");
        return 1;
    }

    // Ensure that level is valid
    if (strcmp(argv[1], "debug") == 0)
    {
        g.level = "debug";
    }
    else if (strcmp(argv[1], "n00b") == 0)
    {
        g.level = "n00b";
    }
    else if (strcmp(argv[1], "l33t") == 0)
    {
        g.level = "l33t";
    }
    else
    {
        fprintf(stderr, "Usage: sudoku n00b|l33t [#]\n");
        return 2;
    }

    // n00b and l33t levels have 1024 boards; debug level has 9
    int max = (strcmp(g.level, "debug") == 0) ? 9 : 1024;

    // Ensure that #, if provided, is in [1, max]
    if (argc == 3)
    {
        // Ensure n is integral
        char c;
        if (sscanf(argv[2], " %d %c", &g.number, &c) != 1)
        {
            fprintf(stderr, "Usage: sudoku n00b|l33t [#]\n");
            return 3;
        }

        // Ensure n is in [1, max]
        if (g.number < 1 || g.number > max)
        {
            fprintf(stderr, "That board # does not exist!\n");
            return 4;
        }

        // Seed PRNG with # so that we get same sequence of boards
        srand(g.number);
    }
    else
    {
        // Seed PRNG with current time so that we get any sequence of boards
        srand(time(NULL));

        // Choose a random n in [1, max]
        g.number = rand() % max + 1;
    }

    // Start up ncurses
    if (!startup())
    {
        fprintf(stderr, "Error starting up ncurses!\n");
        return 5;
    }

    // Register handler for SIGWINCH (SIGnal WINdow CHanged)
    signal(SIGWINCH, (void (*)(int)) handle_signal);

    // Start the first game
    if (!restart_game())
    {
        shutdown();
        fprintf(stderr, "Could not load board from disk!\n");
        return 6;
    }
    redraw_all();

    // Let the user play
    int ch;
    do
    {
        // Refresh the screen
        refresh();

        // Get user's input
        ch = getch();

        // Capitalize input to simplify cases
        ch = toupper(ch);

        // Process user's input
        switch (ch)
        {
            // Start a new game
            case 'N':
                hide_banner();
                gameWon = false;
                g.number = rand() % max + 1;
                if (!restart_game())
                {
                    shutdown();
                    fprintf(stderr, "Could not load board from disk!\n");
                    return 6;
                }
                break;

            // Restart current game
            case 'R':
                hide_banner();
                gameWon = false;
                if (!restart_game())
                {
                    shutdown();
                    fprintf(stderr, "Could not load board from disk!\n");
                    return 6;
                }
                break;

            // Let user manually redraw screen with ctrl-L
            case CTRL('l'):
                redraw_all();
                break;

            // movement cases w wrap
            case KEY_UP:
                g.y = (g.y == 0) ? 8 : g.y - 1;
                break;
            case KEY_DOWN:
                g.y = (g.y == 8) ? 0 : g.y + 1;
                break;
            case KEY_RIGHT:
                g.x = (g.x == 8) ? 0 : g.x + 1;
                break;
            case KEY_LEFT:
                g.x = (g.x == 0) ? 8 : g.x - 1;
                break;

                // replace num
            case '1' ... '9':
                if (!gameWon)
                {
                    hide_banner();
                    int num = ch - '0';

                    if (g.initialBoardEditable[g.y][g.x])
                    {
                        // save num BEFORE modified
                        lm.prevVal = g.board[g.y][g.x];
                        // modify num
                        g.board[g.y][g.x] = num;

                        // update placement of undo func.
                        lm.row = g.y;
                        lm.col = g.x;

                        // check cases
                        int moveResult = checkMove(g.y, g.x, num);
                        switch (moveResult)
                        {
                            case BAD_ROW:
                                show_banner("bad row");
                                break;
                            case BAD_COL:
                                show_banner("bad col");
                                break;
                            case BAD_BOX:
                                show_banner("bad box");
                                break;
                        }
                    }

                    draw_numbers();
                }
                else
                {
                    draw_won_nums();
                }

                break;

            // deletion
            case '0':
            case '-':
            case KEY_BACKSPACE:
            case KEY_DC:
                if (!gameWon)
                {
                    // reset to blank
                    g.board[g.y][g.x] = 0;
                    draw_numbers();
                }
                break;

            // undo last move
            case 'U':
            case CTRL('Z'):
                undo_move();
        }

        if (!gameWon && isGameWon())
        {
            gameWon = true;
            draw_won_nums();
            show_banner("congrats! u won");
        }

        // post processing, redraw board cursor
        show_cursor();

        // Log input (and board's state) if any was received this iteration
        if (ch != ERR)
        {
            log_move(ch);
        }
    }
    while (ch != 'Q');

    // Shut down ncurses
    shutdown();

    // Tidy up the screen (using ANSI escape sequences)
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);

    // That's all folks
    printf("\nkthxbai!\n\n");
    return 0;
}

int checkMove(int row, int col, int num)
{
    // check row
    for (int i = 0; i < 9; i++)
    {
        if (g.board[row][i] == num && i != col)
            return BAD_ROW;
    }
    // check col
    for (int i = 0; i < 9; i++)
    {
        if (g.board[i][col] == num && i != row)
            return BAD_COL;
    }
    // check 3x3 box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (g.board[i + startRow][j + startCol] == num && (i+j) == (row+col))
                return BAD_BOX;
        }
    }
    // no conflict
    return VALID_MOVE;
}

// Draw's the game's board
void draw_grid(void)
{
    // Get window's dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    // Determine where top-left corner of board belongs
    g.top = maxy / 2 - 7;
    g.left = maxx / 2 - 30;

    // Enable color if possible
    if (has_colors())
    {
        attron(COLOR_PAIR(PAIR_GRID));
    }

    // Print grid
    for (int i = 0; i < 3; ++i)
    {
        mvaddstr(g.top + 0 + 4 * i, g.left, "+-------+-------+-------+");
        mvaddstr(g.top + 1 + 4 * i, g.left, "|       |       |       |");
        mvaddstr(g.top + 2 + 4 * i, g.left, "|       |       |       |");
        mvaddstr(g.top + 3 + 4 * i, g.left, "|       |       |       |");
    }
    mvaddstr(g.top + 4 * 3, g.left, "+-------+-------+-------+");

    // Remind user of level and #
    char reminder[maxx + 1];
    sprintf(reminder, "   playing %s #%d", g.level, g.number);
    mvaddstr(g.top + 14, g.left + 25 - strlen(reminder), reminder);

    // Disable color if possible
    if (has_colors())
    {
        attroff(COLOR_PAIR(PAIR_GRID));
    }
}

// Draws game's borders.
void draw_borders(void)
{
    // turn off existing colors
    attroff(COLOR_PAIR(PAIR_BANNER));
    attroff(COLOR_PAIR(PAIR_USER_NUM));
    attroff(COLOR_PAIR(PAIR_DIGITS));

    // Get window's dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    // Enable color if possible (else b&w highlighting)
    if (has_colors())
    {
        attron(A_PROTECT);
        attron(COLOR_PAIR(PAIR_BORDER));
    }
    else
    {
        attron(A_REVERSE);
    }

    // Draw borders
    for (int i = 0; i < maxx; i++)
    {
        mvaddch(0, i, ' ');
        mvaddch(maxy - 1, i, ' ');
    }

    // Draw header
    char header[maxx + 1];
    sprintf(header, "%s by %s", TITLE, AUTHOR);
    mvaddstr(0, (maxx - strlen(header)) / 2, header);

    // Draw footer
    mvaddstr(maxy - 1, 1, "[N]ew Game   [R]estart Game");
    mvaddstr(maxy - 1, maxx - 13, "[Q]uit Game");

    // Disable color if possible (else b&w highlighting)
    if (has_colors())
    {
        attroff(COLOR_PAIR(PAIR_BORDER));
    }
    else
    {
        attroff(A_REVERSE);
    }
}

// Draws game's logo (Must be called after draw_grid has been called at least once)
void draw_logo(void)
{
    // Determine top-left coordinates of logo
    int top = g.top + 2;
    int left = g.left + 30;

    // Enable color if possible
    if (has_colors())
    {
        attron(COLOR_PAIR(PAIR_LOGO));
    }

    // Draw logo
    mvaddstr(top + 0, left, "               _       _          ");
    mvaddstr(top + 1, left, "              | |     | |         ");
    mvaddstr(top + 2, left, " ___ _   _  __| | ___ | | ___   _ ");
    mvaddstr(top + 3, left, "/ __| | | |/ _` |/ _ \\| |/ / | | |");
    mvaddstr(top + 4, left, "\\__ \\ |_| | (_| | (_) |   <| |_| |");
    mvaddstr(top + 5, left, "|___/\\__,_|\\__,_|\\___/|_|\\_\\\\__,_|");

    // Sign logo
    char signature[3 + strlen(AUTHOR) + 1];
    sprintf(signature, "by %s", AUTHOR);
    mvaddstr(top + 7, left + 35 - strlen(signature) - 1, signature);

    // Disable color if possible
    if (has_colors())
    {
        attroff(COLOR_PAIR(PAIR_LOGO));
    }
}

// Draw's game's numbers (Must be called after draw_grid has been called at least once)

void draw_numbers(void)
{

    if (!gameWon)
    {
        // Enable color if possible
        if (has_colors())
        {
            attron(COLOR_PAIR(PAIR_DIGITS));
        }
        // Iterate over board's numbers
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                // Determine char
                char c = (g.board[i][j] == 0) ? '.' : g.board[i][j] + '0';
                if (g.board[i][j] == 0)
                {
                    attron(COLOR_PAIR(PAIR_PERIODS));
                }
                else if (g.initialBoardEditable[i][j])
                {
                    attron(COLOR_PAIR(PAIR_USER_NUM));
                }
                else
                {
                    attron(COLOR_PAIR(PAIR_DIGITS));
                }
                mvaddch(g.top + i + 1 + i / 3, g.left + 2 + 2 * (j + j / 3), c);
            }
        }

        // Disable color if possible
        if (has_colors())
        {
            attroff(COLOR_PAIR(PAIR_BANNER));
            attroff(COLOR_PAIR(PAIR_USER_NUM));
            attroff(COLOR_PAIR(PAIR_DIGITS));
        }
    }
}
// Designed to handles signals (e.g., SIGWINCH)

void draw_won_nums(void)
{
        // Enable color if possible
        if (has_colors())
        {
            attron(COLOR_PAIR(PAIR_WIN));
        }
        // Iterate over board's numbers
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {

                // Determine char
                char c = (g.board[i][j] == 0) ? '.' : g.board[i][j] + '0';
                attron(COLOR_PAIR(PAIR_WIN));
                mvaddch(g.top + i + 1 + i / 3, g.left + 2 + 2 * (j + j / 3), c);
            }
        }

        // Disable color if possible
        if (has_colors())
        {
            attroff(COLOR_PAIR(PAIR_WIN));
        }
    }

void handle_signal(int signum)
{
    // Handle a change in the window (i.e., a resizing)
    if (signum == SIGWINCH)
    {
        redraw_all();
    }

    // Re-register myself so this signal gets handled in future too
    signal(signum, (void (*)(int)) handle_signal);
}

// Hides banner
void hide_banner(void)
{
    // Get window's dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    // Overwrite banner with spaces
    for (int i = 0; i < maxx; i++)
    {
        mvaddch(g.top + 16, i, ' ');
    }
}

// Loads current board from disk, returning true iff successful
bool load_board(void)
{
    // Open file with boards of specified level
    char filename[strlen(g.level) + 5];
    sprintf(filename, "%s.bin", g.level);
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return false;
    }

    // Determine file's size
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);

    // Ensure file is of expected size
    if (size % (81 * INTSIZE) != 0)
    {
        fclose(fp);
        return false;
    }

    // Compute offset of specified board
    int offset = ((g.number - 1) * 81 * INTSIZE);

    // Seek to specified board
    fseek(fp, offset, SEEK_SET);

    // Read board into memory
    if (fread(g.board, 81 * INTSIZE, 1, fp) != 1)
    {
        fclose(fp);
        return false;
    }

    // set non-editable parts of board
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            g.initialBoardEditable[i][j] = (g.board[i][j] != 0) ? false : true;
        }
    }

    // w00t
    fclose(fp);
    return true;
}

// Logs input and board's state to log.txt to facilitate automated tests
void log_move(int ch)
{
    // Open log
    FILE *fp = fopen("log.txt", "a");
    if (fp == NULL)
    {
        return;
    }

    // Log input
    fprintf(fp, "%d\n", ch);

    // Log board
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            fprintf(fp, "%d", g.board[i][j]);
        }
        fprintf(fp, "\n");
    }

    // That's it
    fclose(fp);
}

void undo_move(void)
{
    // do nothing if last move invalid/game won
    if (lm.prevVal == -1 || gameWon)
    {
        return;
    }
    // restore prev val @ last move pos
    g.board[lm.row][lm.col] = lm.prevVal;

    // reset to invalid state
    lm.row = -1;
    lm.col = -1;
    lm.prevVal = -1;

    draw_numbers();
}

// (Re)draws everything on the screen
void redraw_all(void)
{
    // Reset ncurses
    endwin();
    refresh();

    // Clear screen
    clear();

    // Re-draw everything
    draw_borders();
    draw_grid();
    draw_logo();
    draw_numbers();

    // Show cursor
    show_cursor();
}

// (Re)starts current game, returning true iff succesful
bool restart_game(void)
{
    // Reload current game
    if (!load_board())
    {
        return false;
    }

    // Redraw board
    draw_grid();
    draw_numbers();

    // Get window's dimensions
    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    // Move cursor to board's center
    g.y = g.x = 4;
    show_cursor();

    // Remove log, if any
    remove("log.txt");


    // restart game
    gameWon = false;

    // w00t
    return true;
}

// Shows cursor at (g.y, g.x)
void show_cursor(void)
{
    // Restore cursor's location
    move(g.top + g.y + 1 + g.y / 3, g.left + 2 + 2 * (g.x + g.x / 3));
}

// Shows a banner (Must be called after show_grid has been called at least once)

void show_banner(char *b)
{
    // Enable color if possible
    if (has_colors())
    {
        attron(COLOR_PAIR(PAIR_BANNER));
    }

    // Determine where top-left corner of board belongs
    mvaddstr(g.top + 16, g.left + 64 - strlen(b), b);

    // Disable color if possible
    if (has_colors())
    {
        attroff(COLOR_PAIR(PAIR_BANNER));
    }
}

bool isValidUnit(int unit[9])
{
    // index 0 unused
    bool seen[10] = {false};
    for (int i = 0; i < 9; i++)
    {
        int number = unit[i];
        // check if within sudoku param.
        if (number == 0 || seen[number])
            return false;
        seen[number] = true;
    }
    return true;
}

bool isGameWon(void)
{
    int row[9], col[9], box[9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            row[j] = g.board[i][j];
            col[j] = g.board[i][j];
        }

        // check row & col
        if (!isValidUnit(row) || !isValidUnit(col))
            return false;

        // check boxes
        int boxRow = (i / 3) * 3;
        int boxCol = (i % 3) * 3;
        for (int j = 0; j < 9; j++)
        {
            box[j] = g.board[boxRow + j / 3][boxCol + j % 3];
        }
        if (!isValidUnit(box))
            return false;
    }
    // no conflict
    return true;
}
// Shuts down ncurses
void shutdown(void)
{
    endwin();
}

// Starts up ncurses and returns true iff successful
bool startup(void)
{
    // Initialize ncurses
    if (initscr() == NULL)
    {
        return false;
    }

    // Prepare for color if possible
    if (has_colors())
    {
        // Enable color
        if (start_color() == ERR || attron(A_PROTECT) == ERR)
        {
            endwin();
            return false;
        }

        // Initialize pairs of colors
        if (init_pair(PAIR_BANNER, FG_BANNER, BG_BANNER) == ERR ||
            init_pair(PAIR_GRID, FG_GRID, BG_GRID) == ERR ||
            init_pair(PAIR_BORDER, FG_BORDER, BG_BORDER) == ERR ||
            init_pair(PAIR_LOGO, FG_LOGO, BG_LOGO) == ERR ||
            init_pair(PAIR_DIGITS, FG_DIGITS, BG_DIGITS) == ERR ||
            init_pair(PAIR_USER_NUM, FG_USER_NUM, BG_USER_NUM) == ERR ||
            init_pair(PAIR_PERIODS, FG_PERIOD, BG_PERIOD) == ERR ||
            init_pair(PAIR_WIN, FG_WIN, BG_WIN) == ERR)
        {
            endwin();
            return false;
        }
    }

    // Don't echo keyboard input
    if (noecho() == ERR)
    {
        endwin();
        return false;
    }

    // Disable line buffering and certain signals
    if (raw() == ERR)
    {
        endwin();
        return false;
    }

    // Enable arrow keys
    if (keypad(stdscr, true) == ERR)
    {
        endwin();
        return false;
    }

    // Wait 1000 ms at a time for input
    timeout(1000);

    // w00t
    return true;
}
