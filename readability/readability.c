#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float compute_index(string text);

int main(void)
{
    // Get text
    string text = get_string("Text:");

    // Calculate grade
    float index = compute_index(text);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else
    {
        printf("Grade 16+\n");
    }
}

// Calculate grade：
    // CIL index = 0.0588 * L - 0.296 * S - 15.8
    // L is the average number of letters per 100 words in the text; L = 100 * (letter / word)
    // S = the average number of sentences per 100 words in the text; S = 100 / (word / sentence)
float compute_index(string text)
{
    // Calculate the text's length
    int length = strlen(text);

    // Count the number of words,letters and sentences in the text
    int word = 0;
    int letter = 0;
    int sentence = 0;
    for (int i = 0; i < length; i++)
    {
        // Calculate the number of words
        if (isalpha(text[i]) && (i == length - 1 || !isalpha(text[i + 1])) &&
            (text[i + 1] != 45 && text[i + 1] != 39))
        {
            word++;
        }
        else if ((text[i] == 39) && (text[i + 1] == 109 || text[i + 1] == 114 ||
                                     text[i + 1] == 100 || text[i + 1] == 118))
        {
            word++;
        }

        // Calculate the number of letters
        if (isalpha(text[i]))
        {
            letter++;
        }
        else if (text[i] == 39 && (text[i + 1] == 109 || text[i + 1] == 114 || text[i + 1] == 116))
        {
            letter++;
        }
        else if (text[i] == 39 && text[i + 1] == 100)
        {
            letter += 4;
        }
        else if (text[i] == 39 && text[i + 1] == 118)
        {
            letter += 2;
        }

        // Calculate the number of sentences
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentence++;
        }
    }
    // printf("%i,%i,%i",word,letter,sentence);

    // compute the coleman-liau index
    float index =
        5.88 * ((float) letter / (float) word) - 29.6 * ((float) sentence / (float) word) - 15.8;

    return index;
}
