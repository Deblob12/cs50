// Implements a dictionary's functionality
/**
 * CS50 Pset 5
 * dictionary.c
 *
 * Author: Jeffrey Chiu
 * Program to check if a word is spelled correctly
 *
**/
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

bool loaded;
unsigned int entries = 0;
bool breakout = false;
trie *entry;

//function to create a cliche empty node
trie *makeNode(void)
{
    trie *head = NULL;
    head = malloc(sizeof(trie));

    head->end = false;

    //26 letters of the alphabet and the apostrophe mark
    for (int i = 0; i < 27; i++)
    {
        head->child[i] = NULL;
    }
    return head;
}

//function to insert a word into the trie
void insertNode(trie *head, const char *word)
{
    trie *ptr = head;
    int index = 0;
    int loc;

    //keep going until reach the null character
    while (word[index] != '\0')
    {
        //if the char is an apostrophe
        if (word[index] == '\'')
        {
            loc = 26;
        }

        //scale down everything by 'a'
        else
        {
            loc = tolower(word[index]) - 'a';
        }


        //if not pointing to anything, assign a node to it
        if (ptr->child[loc] == NULL)
        {
            ptr->child[loc] = makeNode();
        }
        ptr = ptr->child[loc];
        index++;
    }
    ptr->end = true;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    trie *ptr = entry;
    int index = 0;
    int loc;

    //keep going until reach the null character
    while (word[index] != '\0')
    {
        //if the char is an apostrophe
        if (word[index] == '\'')
        {
            loc = 26;
        }
        //scale down everything by 'a'
        else
        {
            loc = tolower(word[index]) - 'a';
        }
        ptr = ptr->child[loc];

        //if null return false
        if (!ptr)
        {
            return false;
        }
        index++;
    }
    return ptr->end;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //create a file pointer
    FILE *dict = fopen(dictionary, "r");
    int index = 0;

    //make sure file pointer exists
    if (!dict)
    {
        fprintf(stderr, "Could not create %s.\n", dictionary);
        return false;
    }
    entry = makeNode();

    //make sure entry exists
    if (!entry)
    {
        fprintf(stderr, "Could not create entry");
        return false;
    }
    while (true)
    {
        //make string
        char *word = malloc(LENGTH * sizeof(char) + 1);

        //check to make sure you're not at the end of file
        if (feof(dict))
        {
            free(word);
            break;
        }
        else
        {
            //checks the necessary conditions
            for (char c = fgetc(dict); (c != '\n' && index < LENGTH * sizeof(char) + 1); c = fgetc(dict), index++)
            {
                if (c == EOF)
                {
                    free(word);
                    breakout = true;
                    break;
                }
                word[index] = tolower(c);
            }
            if (breakout)
            {
                break;
            }
            word[index++] = '\0';
            insertNode(entry, word);
            free(word);
            index = 0;
            entries++;
        }
    }
    loaded = true;
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (!loaded)
    {
        return 0;
    }
    else
    {
        return entries;
    }
}


// Unloads dictionary from memory, returning true if successful else false
bool freemem(trie *head)
{
    for (int i = 0; i < 27; i++)
    {
        if (head -> child[i] != NULL)
        {
            freemem(head->child[i]);
        }
    }
    free(head);
    return true;
}

bool unload(void)
{
    return freemem(entry);
    free(entry);
}