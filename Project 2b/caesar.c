// Problemset 2: Caesar

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void cipher(string text, int key);


int main(int argc, string argv[])
{
    // Key validation
    if (argc!=2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i <= n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Key conversion to integer
    int k = atoi(argv[1]);

    printf("Key: %i\n", k);

    // Prompt for text input
    string plain_text = get_string("Plain Text: ");

    // Function for cipher
    printf("ciphertext: ");
    cipher(plain_text, k);

}


void cipher(string txt, int key)

{
    int length = strlen(txt);
    string cipher_text;

    for (int j = 0; j < length; j++)
    {
        //Alphabetical text checking
        if (isalpha(txt[j]) != 0)
        {
            //Uppercase checking
            if (isupper(txt[j]) != 0)
            {
                //ASCII conversion
                printf("%c", ((txt[j] - 'A' + key) % 26) + 'A');
            }

            else
            {
                printf("%c", ((txt[j] - 'a' + key) % 26) + 'a');
            }
        }

        // Keeping non-alphabetical chars
        else
        {
            printf("%c", txt[j]);
        }
    }
    printf("\n");

}