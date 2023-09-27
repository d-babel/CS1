#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// Point values for each letter (A to Z)
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function to calculate the score of a word
int compute_score(string word)
{
    int score = 0;

    for (int i = 0, n = strlen(word); i < n; i++) {
        char c = toupper(word[i]);

        // Calculate score
        score += isalpha(c) ? POINTS[c - 'A'] : 0;
    }

    return score;
}

int main(void)
{
    // Get input from players
    string w1 = get_string("Player 1: "), w2 = get_string("Player 2: ");

    // Calculate scores for each player
    int s1 = compute_score(w1), s2 = compute_score(w2);

    // Determine the winner or tie
    printf(s1 > s2 ? "Player 1 wins!\n" : s2 > s1 ? "Player 2 wins!\n" : strcmp(w1, w2) == 0 ? "Tie!\n" : "Tie!\n");

    return 0;
}
