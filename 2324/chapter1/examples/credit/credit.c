#include <stdio.h>
#include <cs50.h>

#define AMEX_LENGTH 15
#define MASTERCARD_LENGTH 16
#define DIVISOR 10
#define MULTIPLIER 2
#define SUM_CHECK 0

int get_length(long n);
bool check_validity(int length, long n);

int main(void)
{
    long number;
    do { number = get_long("Number: "); } while (number < SUM_CHECK);

    int length = get_length(number);
    bool validity = check_validity(length, number);

    printf(validity ? ((length == AMEX_LENGTH) ? "AMEX\n" : (length == MASTERCARD_LENGTH) ? "MASTERCARD\n" : "VISA\n") : "INVALID\n");
}

int get_length(long n)
{
    int length = SUM_CHECK;
    for (; n != SUM_CHECK; n /= DIVISOR, length++);
    return length;
}

bool check_validity(int length, long n)
{
    int sum = SUM_CHECK, i = 1;
    for (; i <= length; i++, n /= DIVISOR)
    {
        int digit = n % DIVISOR;
        sum += (i % MULTIPLIER == SUM_CHECK) ? ((MULTIPLIER * digit) / DIVISOR + (MULTIPLIER * digit) % DIVISOR) : digit;
    }
    return sum % DIVISOR == SUM_CHECK;
}