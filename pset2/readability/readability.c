#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void count_letters(string txt);

int main(void)
{
    string text = get_string("Text: ");
    count_letters(text);
}

void count_letters(string txt)
{
    int n = 0;
    int letters = 0;
    int words = 1; // There is no space in the front of the first word, neither at the end of the lest word
    int sentences = 0;

    while (txt[n] != '\0')
    {

        // counting the letters
        if ((txt[n] >= 'a' && txt[n] <= 'z') || (txt[n] >= 'A' && txt[n] <= 'Z'))
        {
            letters++;
        }

        // counting the words
        if (txt[n] == ' ')
        {
            words++;
        }

        // counting the sentences
        if (txt[n] == '.' || txt[n] == '?' || txt[n] == '!')
        {
            sentences++;
        }

        n++;
    }

    float L = (float)letters * 100.0 / words;
    float S = (float)sentences * 100.0 / words;
    int index = round((L * 0.0588) - (S * 0.296) - 15.8);

    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16) 
    {
        printf("Grade 16+\n");
    } 
    else 
    {
        printf("Grade %i\n", index);
    }
}
