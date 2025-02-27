#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int no;
    struct node *next;
};
struct node *start = NULL, *end = NULL, *fast, *slow, *ipoint=NULL;
int lap=0;

void addtrack(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory Allocation Failed! \n");
        return;
    }
    newnode->no=data;
    newnode->next = NULL;
    if(start == NULL)
    {
        start = newnode;
        end = newnode;
    }
    else
    {
        end->next = newnode;
        end = newnode;
    }
}

void showtrack()
{
    struct node *temp;
    temp=start;
    while (temp!=NULL)
    {
        printf("%d->", temp->no);
        temp=temp->next;
    }
}

int race(int target)
{
    fast=start;
    slow=start;
    lap=0;
    while(lap<=target)
    {
        if(fast->next==NULL || fast->next->next==NULL)
        {
            fast=ipoint;
            lap++;
        }
        if(slow->next==NULL)
        {
            slow=ipoint;
        }

        if(slow==ipoint && fast==ipoint)
        {
            //printf("Dominic win");
            return 1;
        }
        fast=fast->next;
        fast=fast->next;
        slow=slow->next;
        if(lap==target)
        {
            //printf("Stephano wins");
            return 0;
        }
    }
    //printf("Stephano wins");
    return 0;
}


int main()
{
    int i=0,n,k;
    printf("Enter the size of track: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        addtrack(i);
    }
    printf("Enter the intersection point: ");
    scanf("%d",&k);
    ipoint=start;
    for(i=1; i<=n; i++)
    {
        ipoint=ipoint->next;
        if(i==k)
        break;
    }
    addtrack(k);
    showtrack();
    int targt;
    printf("\nEnter the target for Stephano: ");
    scanf("%d",&targt);
    int c=race(targt);
    if(c==1)
    {
        printf("\nDominic wins");
    }
    else
    {
        printf("\nStephano wins");
    }

    return 0;
}