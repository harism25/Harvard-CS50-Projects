// Problemset 1: Cash

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    // Prompt user for positive input of change
    do
    {
        change = get_float("Change owed: ");
    }
    while (change <= 0);

    // Convert $ into Cs
    int cents = round(change * 100);
    //
    int coins = 0;
    int quarter = 0;
    int dime = 0;
    int nickel = 0;
    int penny = 0;

    // Can I give 0.25?
    while (cents >= 25)
    {
        coins ++;
        quarter ++;
        cents -= 25;
    }

    // Can I give 0.10?
    while (cents >= 10)
    {
        coins ++;
        dime ++;
        cents -= 10;
    }

    // Can I use 0.05?
    while (cents >= 5)
    {
        coins ++;
        nickel ++;
        cents -= 5;
    }

    // Can I give 0.01?
    while (cents >= 1)
    {
        coins ++;
        penny ++;
        cents -= 1;
    }

    printf("%i \n", coins);
   
}