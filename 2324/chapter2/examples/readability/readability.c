// Readability by Drew Babel

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//#define formula? --> ask in office hours
// define constants for Coleman-Liau index formula
#define COEFFICIENT_LETTERS_PER_100_WORDS 0.0588
#define COEFFICIENT_SENTENCES_PER_100_WORDS 0.296
#define COEFFICIENT_BASE_OFFSET 15.8

// function prototypes
    // count letters
    // count words
    // count sentences


int main(void)
{
    string text = get_string("Text: ");
}

// user inputs a excerpt from a book
// DATATYPE text = get_DATATYPE("Text: ");

// L = SOLVE FOR L
// S = SOLVE FOR S
//index = 0.0588 * L - 0.296 * S - 15.8

// L is the average number of letters per 100 words in the text
// S is the average number of sentences per 100 words in text

// MUST USE FLOAT/DOUBLE TO GET RID OF ANY DATATYPE CUTOFFS

// print grade (which is rounded index)
// if rounded index > 16, print "Grade 16+"
// if rounded index < 1 print "Before Grade 1"



// ex:
// $ ./readability
// Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
// Grade 3
