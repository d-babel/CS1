#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Define prefixes for different credit card brands
#define AMEX_PREFIX_1 37
#define AMEX_PREFIX_2 34
#define VISA_PREFIX 4
#define MASTERCARD_PREFIXES_COUNT 5
#define MASTERCARD_PREFIXES {51, 52, 53, 54, 55}
#define BRAND_MAX_LEN 20
#define AMEX_LENGTH 15
#define VISA_LENGTH_1 13
#define VISA_LENGTH_2 16
#define MASTERCARD_LENGTH 16

// Function to convert a string to uppercase
void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function to calculate Luhn checksum for a given number
// This is used to ensure the generated credit card number is valid
int luhn_checksum(long long number) {
    int sum1 = 0;
    int sum2 = 0;

    int index = 0;
    while (number > 0) {
        if (index % 2 == 0) {
            sum2 += number % 10;
        } else {
            int double_digit = 2 * (number % 10);
            sum1 += double_digit / 10 + double_digit % 10;
        }
        number /= 10;
        index++;
    }
    return sum1 + sum2;
}

// Function to generate a random credit card number for the given prefix and length
long long generate_card_number(int prefix, int length) {
    long long base = prefix;
    for (int i = 0; i < length - 2; i++) {
        base = base * 10 + (rand() % 10);
    }

    int checksum = luhn_checksum(base * 10); // *10 to leave space for the last digit
    int final_digit = (10 - (checksum % 10)) % 10;

    return base * 10 + final_digit;
}

// Function to print a horizontal line separator
void print_horizontal_line(int width) {
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL)); // Seed the random number generator with current time

    char brand[BRAND_MAX_LEN];
    int valid_brand = 0; // flag to check if the entered brand is valid

    // Keep asking the user until a valid brand is entered
    while (!valid_brand) {
        printf("Which brand do you want (AMEX, VISA, MASTERCARD, MIX)? ");
        scanf("%s", brand);
        to_uppercase(brand); // Convert user input to uppercase to handle different cases

        if (strcmp(brand, "AMEX") == 0 || strcmp(brand, "VISA") == 0 ||
            strcmp(brand, "MASTERCARD") == 0 || strcmp(brand, "MIX") == 0) {
            valid_brand = 1; // set the flag to true if a valid brand is entered
        } else {
            printf("Invalid brand choice. Please try again.\n");
        }
    }

    int num_cards;
    int valid_input = 0;
    while (!valid_input) {
        printf("How many valid credit card numbers do you want? ");
        if (scanf("%d", &num_cards) == 1) {  // Check if the input is a number
            if (num_cards > 20) {  // If the number is greater than 20, ask for confirmation
                char response[10];
                int valid_response = 0;
                while (!valid_response) {
                    printf("You're about to print a lot of lines! Are you sure? (y/n/yes/no) ");
                    scanf("%s", response);
                    to_uppercase(response);
                    if (strcmp(response, "YES") == 0 || strcmp(response, "Y") == 0) {
                        valid_input = 1;
                        valid_response = 1;
                    } else if (strcmp(response, "NO") == 0 || strcmp(response, "N") == 0) {
                        printf("Please enter a number less than or equal to 20.\n");
                        valid_response = 1;
                    } else {
                        printf("Invalid response. Please answer with y, n, yes, or no.\n");
                    }
                }
            } else {
                valid_input = 1;
            }
        } else {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');  // Clear the input buffer
        }
    }

    // Calculate the width of the table columns
    int brand_column_width = 35;
    int card_number_column_width = 25;

    // Calculate the total width of the table (including borders)
    int total_width = brand_column_width + card_number_column_width + 4; // 4 for the borders (2 on each side)

    // Generate and print the requested number of credit card numbers
    print_horizontal_line(total_width);
    printf("|%-*s|%-*s|\n", brand_column_width, "Brand", card_number_column_width, "Card Number");
    print_horizontal_line(total_width);

    int max_card_length = 0;  // Initialize the maximum card number length to 0

    for (int i = 0; i < num_cards; i++) {
        long long card_number = 0;
        char chosen_brand[BRAND_MAX_LEN];
        char current_brand[BRAND_MAX_LEN];  // Create a new variable to store the current brand for this iteration
        strcpy(current_brand, brand);       // Initialize it with the user's choice

        if (strcmp(current_brand, "MIX") == 0) {
            int brand_choice = rand() % 3;  // Randomly choose between 0, 1, and 2
            switch (brand_choice) {
                case 0:
                    strcpy(current_brand, "AMEX");
                    break;
                case 1:
                    strcpy(current_brand, "VISA");
                    break;
                case 2:
                    strcpy(current_brand, "MASTERCARD");
                    break;
            }
        }

        if (strcmp(current_brand, "AMEX") == 0) {
            card_number = generate_card_number(rand() % 2 ? AMEX_PREFIX_1 : AMEX_PREFIX_2, AMEX_LENGTH);
            strcpy(chosen_brand, "AMEX");
        } else if (strcmp(current_brand, "VISA") == 0) {
            card_number = generate_card_number(VISA_PREFIX, rand() % 2 ? VISA_LENGTH_1 : VISA_LENGTH_2);
            strcpy(chosen_brand, "VISA");
        } else if (strcmp(current_brand, "MASTERCARD") == 0) {
            int prefixes[MASTERCARD_PREFIXES_COUNT] = MASTERCARD_PREFIXES;
            card_number = generate_card_number(prefixes[rand() % MASTERCARD_PREFIXES_COUNT], MASTERCARD_LENGTH);
            strcpy(chosen_brand, "MASTERCARD");
        }

        // Check the length of the card number and update max_card_length if needed
        int card_length = snprintf(NULL, 0, "%lld", card_number);
        if (card_length > max_card_length) {
            max_card_length = card_length;
        }

        printf("|%-*s|%lld%*s|\n", brand_column_width, chosen_brand, card_number,
            card_number_column_width - card_length, "");
    }

    print_horizontal_line(total_width);

    return 0;
}
