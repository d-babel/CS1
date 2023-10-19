#include <cs50.h>
#include <math.h>
#include <stdio.h>

#define AMEX_PREFIX_1 37
#define AMEX_PREFIX_2 34
#define VISA_PREFIX 4
#define MASTERCARD_PREFIX_1 51
#define MASTERCARD_PREFIX_2 52
#define MASTERCARD_PREFIX_3 53
#define MASTERCARD_PREFIX_4 54
#define MASTERCARD_PREFIX_5 55

int main(void)
{
    // input
    long long card_number;
    do
    {
        card_number = get_long_long("Enter card number: ");
    }
    while (card_number < 0);

    // calc num of digits
    int digit_count = 0;
    long long number = card_number;
    while (number > 0)
    {
        number = number / 10;
        digit_count++;
    }

    // calc checksum
    long long temp = card_number;
    int sum1 = 0;
    int remainder1;
    int remainder0;
    while (temp != 0)
    {
        remainder1 = 2 * ((temp % 100) / 10);
        remainder0 = remainder1 % 10 + round(remainder1 / 10);
        sum1 = sum1 + remainder0;
        temp = temp / 100;
    }

    // add sum to digits that were not multiplied by 2
    long long temp2 = card_number;
    int sum2 = 0;
    int remainder2;
    while (temp2 != 0)
    {
        remainder2 = temp2 % 10;
        sum2 = sum2 + remainder2;
        temp2 = temp2 / 100;
    }

    int checksum = sum1 + sum2;

    // check card type
    if (checksum % 10 == 0 && digit_count == 15 &&
        (floor(card_number / 10000000000000) == AMEX_PREFIX_1 || floor(card_number / 10000000000000) == AMEX_PREFIX_2))
    {
        printf("Card Type: AMEX\n");
    }
    else if (checksum % 10 == 0 && digit_count == 13 && floor(card_number / 1000000000000) == VISA_PREFIX)
    {
        printf("Card Type: VISA\n");
    }
    else if (checksum % 10 == 0 && digit_count == 16 && floor(card_number / 1000000000000000) == VISA_PREFIX)
    {
        printf("Card Type: VISA\n");
    }
    else if (checksum % 10 == 0 && digit_count == 16 &&
             (floor(card_number / 100000000000000) == MASTERCARD_PREFIX_1 ||
              floor(card_number / 100000000000000) == MASTERCARD_PREFIX_2 ||
              floor(card_number / 100000000000000) == MASTERCARD_PREFIX_3 ||
              floor(card_number / 100000000000000) == MASTERCARD_PREFIX_4 ||
              floor(card_number / 100000000000000) == MASTERCARD_PREFIX_5))
    {
        printf("Card Type: MASTERCARD\n");
    }
    else
    {
        printf("Card Type: INVALID\n");
    }
}
