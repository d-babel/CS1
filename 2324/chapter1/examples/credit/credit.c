#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define LENGTH_AMEX 15
#define LENGTH_VISA1 13
#define LENGTH_VISA2 16
#define LENGTH_MC 16
#define PREFIX_AM 34
#define PREFIX_MC1 51
#define PREFIX_MC2 55
#define PREFIX_VISA 4
#define INVALID 0

bool check_validity(long n, int length);
bool begins_with(long n, int length, int prefix);

int main(void)
{
    long card_number = get_long("Number: ");
    int length = round(log10(card_number) + 1);
    bool valid = check_validity(card_number, length);

    if (valid && length == LENGTH_AMEX && begins_with(card_number, length, PREFIX_AM)) printf("AMEX\n");
    else if (valid && (length == LENGTH_VISA1 || length == LENGTH_VISA2) && begins_with(card_number, length, PREFIX_VISA)) printf("VISA\n");
    else if (valid && length == LENGTH_MC && begins_with(card_number, length, PREFIX_MC1) && begins_with(card_number, length, PREFIX_MC2)) printf("MASTERCARD\n");
    else printf("INVALID\n");
}

bool check_validity(long n, int length)
{
    int sum = INVALID;
    for (int i = 0; i < length; i++, n /= 10)
        sum += i % 2 == INVALID ? n % 10 : 2 * (n % 10) / 10 + 2 * (n % 10) % 10;

    return sum % 10 == INVALID;
}

bool begins_with(long n, int len, int prefix)
{
    return n / pow(10, len - (round(log10(prefix) + 1))) == prefix;
}