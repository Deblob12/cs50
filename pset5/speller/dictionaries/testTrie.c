#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

unsigned int entries = 0;

typedef struct trie
{
    struct trie *child[26];
    bool end;
}
trie;

trie* makeNode(void)
{
    trie *head = NULL;
    head = malloc(sizeof(trie));
    if (head)
    {
        head->end = false;
        for (int i = 0; i < 26; i++)
        {
            head->child[i] = NULL;
        }
    }
    return head;
}

void insertNode(trie* head, const char* word)
{
    trie* ptr = head;
    int index = 0;
    int loc;
    while (word[index] != '\0')
    {
        loc = word[index] - 'a';
        if (ptr->child[loc] == NULL)
        {
            ptr->child[loc] = makeNode();
        }
        ptr = ptr->child[loc];
        index++;
    }
    ptr->end = true;
    entries++;
}

bool search(trie* head, const char *word)
{
    trie* ptr = head;
    int index = 0;
    int loc;

    while (word[index] != '\0')
    {
        loc = word[index] - 'a';
        ptr = ptr->child[loc];
        if (!ptr)
        {
            printf("%s\n", "dab");
            return false;
        }
        index++;
    }
    printf("%i\n", ptr->end);
    return ptr->end;
}

int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};

    char output[][32] = {"Not present in trie", "Present in trie"};


    trie *root = makeNode();

    // Construct trie
    int i;
    for (i = 0; i < sizeof(keys)/sizeof(keys[0]); i++)
        insertNode(root, keys[i]);

    // Search for different keys
    printf("%s --- %s\n", "the", output[search(root, "the")] );
    printf("%s --- %s\n", "these", output[search(root, "these")] );
    printf("%s --- %s\n", "their", output[search(root, "their")] );
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );
    printf("%i\n", (root->child[0]->end));


    return 0;

}