#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
};

void displayList(struct node *head)
{
    if(head==NULL)
    {
        printf("The list is empty");
    }
    else
    {
        struct node *temp = head;
        while(temp!=head->next)
        {
            printf("%d-->",temp->data);
            temp= temp->next;
        }
    }
}

struct node *InsertBeg(struct node *head, int d)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    
    if(head==NULL)
    {
        newnode->data=d;
        newnode->next=head;
        return newnode;
    }
    else
    {
        temp = head;
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        //When temp is one before head
        temp->next = newnode;
        newnode->data = d;
        newnode->next=head;
        
        return newnode;

    }

}

struct node *InsertEnd(struct node *head, int d)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    
    if(head==NULL)
    {
        newnode->data = d;
        newnode->next = newnode;
        return newnode;
    }
    else
    {
        temp = head;
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        //When temp is one before head
        temp->next = newnode;
        newnode->data = d;
        newnode->next = head;
        return head;

    }

}


int main()
{
    struct node *head;
    //struct node *last = NULL;

    // Allocate memory for nodes in the linked list 
    head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    //last = (struct node *)malloc(sizeof(struct node));

    head = InsertBeg(head,55);
    //displayList(head);

    head = InsertBeg(head,100);
    displayList(head);

    return 0;
}