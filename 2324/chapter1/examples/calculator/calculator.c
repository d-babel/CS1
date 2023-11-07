// Calc by Drew Babel

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


//mod opperator --> Usage: ./calc [num1] [operator] [num2]
//index:                      0      1        2       3

double mod(double num1, double num2);


int main(void)
{
    //check
    if (argc != 4)
    {
        printf("Usage: ./calc [num1] [operator] [num2]");
    }

    double num1 atof(argv[1]);
    double num2 atof(argv[3]);
    char operator argv[2][0]; //assign the first character of the third  command line argument (index: 2) as the operator --> needed as you cant firectly assign string to char


    if(argv[3] = '*') //multiplication
    {
       printf(argv[2]+argv[3]);
    }
    else if(argv[3] = '/') //division
    {

    }
    else if(argv[3] = '+') //addition
    {

    }
    else if(argv[3] = '-') //subtraction
    {

    }
    else // modulus
    mod();

    }
}

int mod(num1, num2)
{
    //ex:
    // q = (int) (10.7 / 3.28);
    // q = (int) 3.262195;
    // q = 3
    // mod = 10.7 - (3.28 * 3);
    // mod = 10.7 - 9.84
    // mod = 0.86

}
