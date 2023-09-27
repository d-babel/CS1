#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LETTER_SCORES[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate_score(char* word) {
    int score = 0;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        char letter = word[i];
        if (isalpha(letter)) {
            int index = toupper(letter) - 'A';
            score += LETTER_SCORES[index];
        }
    }

    return score;
}

int main() {
    char* word1 = (char*)malloc(100 * sizeof(char));
    char* word2 = (char*)malloc(100 * sizeof(char));

    printf("Enter word 1: ");
    scanf("%s", word1);
    printf("Enter word 2: ");
    scanf("%s", word2);

    int score1 = calculate_score(word1);
    int score2 = calculate_score(word2);

    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    free(word1);
    free(word2);

    return 0;
}
