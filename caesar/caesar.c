#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    int length1 = strlen(argv[1]);
    for (int i = 0; i < length1; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    int length2 = strlen(plaintext);

    // Rotate the character if it's a letter
    for (int n = 0; n < length2; n++)
    {
        if (isupper(plaintext[n]))
        {
            plaintext[n] = (char) (((plaintext[n] - 65) + key) % 26 + 65);
        }
        else if (islower(plaintext[n]))
        {
            plaintext[n] = (char) (((plaintext[n] - 97) + key) % 26 + 97);
        }
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}
