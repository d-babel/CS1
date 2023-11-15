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
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    //user input excerpt
    string text = get_string("Text: ");

    //count letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // L is the average number of letters per 100 words
    float L = (float)letters / (float)words * 100;

    // S is the average number of sentences per 100 words
    float S = (float)sentences / (float)words * 100;

    // calculate readability index using Coleman-Liau formula
    float index = COEFFICIENT_LETTERS_PER_100_WORDS * L - COEFFICIENT_SENTENCES_PER_100_WORDS * S - COEFFICIENT_BASE_OFFSET;

    // round index to nearest whole num and find grade
    int grade = round(index);
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("grade %i\n", grade);
    }

}

//function to count letters in text
int count_letters(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// function to count words in text
int count_words(string text)
{
    int count = 1; // start with 1 for the last word
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ');
        {
            count++;
        }
    }
    return count;
}

//function to count sentences in text
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
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
