// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1; // DENNIS: probebly I whant to change this number later to something larger

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
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
        return false;
    }
    //start the singly linked-list
    struct node* list = NULL;

    char dicWord[LENGTH];

    while (fscanf(dic, "%s", dicWord ) != EOF)
    {
        // printf("%s\n", dicWord); //just checking if I got the word
        node *w = malloc(sizeof(node)); // saving memory for the new word
        // printf("%p\n", w); //checking where it saved the memorie
        if (w == NULL) // chellig if there is memorie for my new word
        {
            return 1;
        }
        if (list == NULL)
        {
            // printf("list == NULL\n");
            strcpy(w->word, dicWord);
            w -> next = NULL;
            list = w;
        }
        else
        {
            strcpy(w->word, dicWord);
            w -> next = list;
            list = w;

            // printf("list != NULL\n");
            // printf("List pointer = %p \n", &list); // the pointer of the list
            // printf("first word of the list is %s\n", list->word); // the first word of the list
            // printf("next word of the list is %p\n", list->next); // the next pointer of the list
        }

        for (node *tmp = list; tmp != NULL; tmp = tmp->next)
        {
            printf("%s\n", tmp->word);
        }

    }

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
