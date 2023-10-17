#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define LENGTH_AMX 15
#define LENGTH_MC 16
#define LENGTH_VIS1 13
#define LENGTH_VIS2 16
#define PREFIX_AMX1 34
#define PREFIX_AMX2 37
#define PREFIX_MC1 51
#define PREFIX_MC2 52
#define PREFIX_MC3 53
#define PREFIX_MC4 54
#define PREFIX_MC5 55
#define PREFIX_VIS 4

bool check_validity(long n, int length);
bool begins_with(long n, int length, int prefix);

int main(void)
{
    long card_number;
    card_number = get_long("Number: ");
    int length = round(log10(card_number) + 1);
    bool valid = check_validity(card_number, length);
    if (valid && length == LENGTH_AMX && (begins_with(card_number, length, PREFIX_AMX1) || begins_with(card_number, length, PREFIX_AMX2))) printf("AMEX\n");
    else if (valid && (length == LENGTH_VIS1 || length == LENGTH_VIS2) && begins_with(card_number, length, PREFIX_VIS)) printf("VISA\n");
    else if (valid && length == LENGTH_MC && (begins_with(card_number, length, PREFIX_MC1) ||
                                               begins_with(card_number, length, PREFIX_MC2) ||
                                               begins_with(card_number, length, PREFIX_MC3) ||
                                               begins_with(card_number, length, PREFIX_MC4) ||
                                               begins_with(card_number, length, PREFIX_MC5))) printf("MASTERCARD\n");
    else printf("INVALID\n");
}

bool check_validity(long n, int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++, n /= 10)
        sum += i % 2 == 0 ? n % 10 : ((n % 10 * 2 % 10) + (n % 10 * 2 / 10));

    return sum % 10 == 0;
}

bool begins_with(long n, int len, int prefix){
    return n / pow(10, len - (round(log10(prefix) + 1))) == prefix;