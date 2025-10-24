// Lab1 Population

#include <cs50.h>
#include <stdio.h>

int main(void)

{
    // Prompt user for starting years
    int start;
    do
    {
        start = get_int("Start Size: ");
    }
    while (start < 9);

    //Prompt user for ending years
    int end;
    do
    {
        end = get_int("End Size: ");
    }
    while (end < start);

    //Tracking number of years
    int years = 0;

    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }

    printf("Years: %i\n", years);

}