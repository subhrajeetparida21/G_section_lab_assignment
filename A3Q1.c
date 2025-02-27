#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode
{
    char ch;
    struct lnode *next;
};
struct lnode *start1 = NULL, *end1 = NULL;

struct dnode
{
    char st[20];
    struct dnode *next;
    struct dnode *prev;
};
struct dnode *start2 = NULL, *end2 = NULL;

void AddLNode(char c)
{
    struct lnode *newnode = (struct lnode*)malloc(sizeof(struct lnode));
    if(newnode == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }
    newnode->ch = c;
    newnode->next = start1;
    start1 = newnode;
}

void AddDNode(char word[])
{
    struct dnode *newnode = (struct dnode*)malloc(sizeof(struct dnode));
    if(newnode == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }
    strcpy(newnode->st, word);
    newnode->next = NULL;

    if(start2 == NULL)
    {
        start2 = newnode;
        end2 = newnode;
    }
    else
    {
        end2->next = newnode;
        end2 = newnode;
    }
}

void display()
{
    struct dnode *temp = start2;
    while(temp != NULL)
    {
        printf("%s ", temp->st);
        temp = temp->next;
    }
}

void freeList(struct lnode **head)
{
    struct lnode *temp;
    while(*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    char sent[80];
    printf("Enter the problem string:\n");
    gets(sent);
    sent[strlen(sent)]=' ';
    sent[strlen(sent)]='\0';
    char word[20];
    int n = 0;

    for(int i = 0; i < strlen(sent); i++)
    {
        char c = sent[i];
        if(c == ' ')
        {
            struct lnode *temp = start1;
            n = 0;
            while(temp != NULL)
            {
                word[n] = temp->ch;
                temp = temp->next;
                n++;
            }
            word[n] = '\0';

            if(word[0] == '\0')
            {
                word[0] = ' ';
                word[1] = '\0';
            }

            AddDNode(word);
            freeList(&start1);
            start1 = NULL;
        }
        else 
        {
            AddLNode(c);
        }
    }
    display();
    return 0;
}
