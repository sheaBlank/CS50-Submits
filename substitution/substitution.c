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
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Make sure there will be 26 characters in argv[1]
    int length1 = strlen(argv[1]);
    if (length1 != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Make sure each character in argv[1] is a letter.
    // Convert argv[1] from a `string` to an `int`
    int key[26];
    for (int i = 0; i < length1; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        else
        {
            for (int j = 0; j < i; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }
        }

        if (isupper(argv[1][i]))
        {
            key[i] = argv[1][i] - (65 + i);
        }
        else if (islower(argv[1][i]))
        {
            key[i] = argv[1][i] - (97 + i);
        }
    }
    // printf("%i",key[1]);

    // Prompt users for plaintext
    string plaintext = get_string("plaintext: ");
    int length2 = strlen(plaintext);

    for (int n = 0; n < length2; n++)
    {
        if (isupper(plaintext[n]))
        {
            plaintext[n] = ((plaintext[n] - 65) + key[plaintext[n] - 65]) % 26 + 65;
        }
        else if (islower(plaintext[n]))
        {
            plaintext[n] = ((plaintext[n] - 97) + key[plaintext[n] - 97]) % 26 + 97;
        }
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}
