// Compile-time options for the game of Sudoku.

// Game's author
#define AUTHOR "Drew Babel"

// Game's title
#define TITLE "Sudoku"

// Banner's colors
#define FG_BANNER COLOR_WHITE
#define BG_BANNER COLOR_BLACK

// Grid's colors
#define FG_GRID COLOR_WHITE
#define BG_GRID COLOR_BLACK

// Border's colors
#define FG_BORDER COLOR_WHITE
#define BG_BORDER COLOR_BLACK

// Logo's colors
#define FG_LOGO COLOR_WHITE
#define BG_LOGO COLOR_BLACK

// Digits's colors
#define FG_ORIGINAL_NUM COLOR_YELLOW
#define FG_DIGITS COLOR_RED
#define BG_DIGITS COLOR_RED

// Nicknames for pairs of colors
enum { PAIR_BANNER = 1, PAIR_GRID, PAIR_BORDER, PAIR_LOGO, PAIR_DIGITS };
