// Problemset 1: Mario (less)

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    // Prompt the user for positive integer: n=Height
    do
    {
        n = get_int("Height: ");
    }
    while (n > 8 || n < 1);
    
    // where i=rows, j=spaces, k=hashtags
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int k = 1; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}