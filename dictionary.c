// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"

bool check(const char *word);
unsigned int hash(const char *word);
bool load(const char *dictionary);


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int noOfWords = 0;

bool loadedDict = false;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashValue = hash(word);
    node *cursorNode = table[hashValue];

    while (cursorNode != NULL)
    {
        if (strcasecmp(cursorNode->word, word) == 0)
        {
            return true;
        }
        cursorNode = cursorNode->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false

bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not load");
        return false;
    }

    char *string = malloc(LENGTH + 1);
    if (string == NULL)
    {
        printf("Memory allocation failed");
        fclose(dict);
        return false;
    }

    while (fscanf(dict, "%s", string) != EOF)
    {
        node *pointerNode = malloc(sizeof(node));
        if (pointerNode == NULL)
        {
            printf("Memory allocation failed");
            free(string);
            fclose(dict);
            return false;
        }

        strcpy(pointerNode->word, string);
        int hashValue = hash(string);

        if (table[hashValue] == NULL)
        {
            pointerNode->next = NULL;
        }
        else
        {
            pointerNode->next = table[hashValue];
        }

        table[hashValue] = pointerNode;
        noOfWords += 1;
    }

    free(string);
    loadedDict = true;
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (loadedDict)
    {
        return noOfWords;
    }
    return noOfWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursorNode = table[i];
        while (cursorNode != NULL)
        {
            node *temp = cursorNode;
            cursorNode = cursorNode->next;
            free(temp);
        }
    }
    return true;
}
