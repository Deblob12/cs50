/**
 * pset 1
 * credit.c
 *
 * Jeffrey Chiu
 *
 * Determines if an input is a valid credit card number
 * If valid, prints out whether it is an American Express, MasterCard, or Visa Credit Card
 *
 * Uses only methods taught in Lectures 0 and 1
 */

#include <stdio.h>
#include <cs50.h>

int numbLength(long long num);
int getSum(long long numb);
int getFirstTwo(long long numb);

int main(void)
{
    //Gets user input
    printf("Number: ");
    long long number = get_long_long();
    int length = numbLength(number);

    //Checks to see if input has valid number length
    if ((length != 13) && (length != 15) && (length != 16))
    {
        printf("INVALID\n");
        return 0;
    }

    int sum = getSum(number);

    //Checks to see if input meets sum condition
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    int first = getFirstTwo(number);

    //Checks to see if the input is an American Express card (15 numbers starting with either 34 or 37)
    if (length == 15 && (first == 34 || first == 37))
    {
        printf("AMEX\n");
        return 0;
    }

    //Checks to see if the input is a MasterCard (16 numbers starting with either 51, 52, 53, 54, or 55)
    else if (length == 16 && (first == 51 || first == 52 || first == 53 || first == 54 || first == 55))
    {
        printf("MASTERCARD\n");
        return 0;
    }

    //Checks to see if the input is a Visa Card (13 or 16 numbers starting with 4)
    else if ((length == 13 || length == 16) && (first / 10 % 10 == 4))
    {
        printf("VISA\n");
        return 0;
    }

    else
    {
        printf("INVALID\n");
        return 0;
    }
}

//method to find length of user inputted card
int numbLength(long long num)
{
    int numdig = 0;
    while (num > 0)
    {
        num /= 10;
        numdig++;
    }
    return numdig;
}

//returns the unique credit card sum total
int getSum(long long numb)
{
    int sum = 0;
    do
    {
        sum += numb % 10;
        numb /= 10;
        int temp = 2 * (numb % 10);
        sum += temp % 10;
        temp /= 10;
        sum += temp % 10;
        numb /= 10;
    }
    while (numbLength(numb) > 0);
    return sum;
}

//returns first two digits of user inputted card number
int getFirstTwo(long long numb)
{
    long long temp = numb;
    while (temp > 100)
    {
        temp /= 10;
    }
    return temp;
}

