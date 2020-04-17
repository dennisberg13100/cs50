// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1400; 

// Hash table
node *table[N];

// Dictionary size

int dictionary_size = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO

    int h = hash(word);
    node *cursor = table[h];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
            break;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int hash = 0;
    for (int i = 0, w = strlen(word); i < w; i++)
    {
        int n = tolower((int)word[i]);
        hash += n;
    }

    hash = hash % N;
    return hash;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    
    // open the dictionary
    FILE *dic = fopen(dictionary, "r");
    
    // check if it work else return false
    if (dic == NULL)
    {
        printf("could not open the dictionary!");
        return false;
    }
    
    //start the singly linked-list in the table (sting all as NULL)
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char dicWord[LENGTH];

    while (fscanf(dic, "%s", dicWord) != EOF)
    {
        dictionary_size++;
        int h = hash(dicWord);
        // saving memory for the new word
        node *w = malloc(sizeof(node)); 
        //checking where it saved the memorie
        if (w == NULL) 
        {
            return 1;
        }
        if (table[h] == NULL)
        {
            strcpy(w->word, dicWord);
            w -> next = NULL;
            table[h] = w;
        }
        else
        {
            strcpy(w->word, dicWord);
            w -> next = table[h];
            table[h] = w;
        }


    }
    
    fclose(dic);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictionary_size;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
