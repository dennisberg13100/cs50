#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char *word = get_string("Type a word to hash: ");
    for (int i = 0, w = strlen(word); i < w; i++)
    {
        word[i] = tolower((int)word[i]);
    }
    printf("%s\n", word);
    int hash = 0;
    for (int i = 0, w = strlen(word); i < w; i++)
    {
        int n = (int)word[i];
        printf("%i\n", n);
        hash += n;
    }

    hash = hash % 5;
    printf("%i\n", hash);
}