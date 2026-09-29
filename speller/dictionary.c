// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int num;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int n = hash(word);
    node *temp = table[n];

    while(temp != NULL)
    {
        if(strcasecmp(word, temp->word) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash_value = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value += tolower(word[i]);
    }

    return hash_value % 26;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL) {
        return false;
    }

    // Read each word in the file
    char word[LENGTH + 1];
    while (fscanf(source, "%s", word) != EOF)
    {
        node *dict = malloc(sizeof(node));
        if(dict == NULL)
        {
            fclose(source);
            return false;
        }
        strcpy(dict->word, word);

        // Add each word to the hash table
        unsigned int hashValue = hash(word);
        dict->next = table[hashValue];
        table[hashValue] = dict;
        num++;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return num;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < 26; i++)
    {
        node *temp = table[i];
        while(temp != NULL)
        {
            node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    return true;
}
