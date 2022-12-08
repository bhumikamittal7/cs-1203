//Write a function that takes a linked list and returns a new linked list that is the reverse of the original


#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *reverseList(struct node *head){
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next = NULL;
    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    struct node *head = NULL;
    struct node *temp = NULL;
    int val = scanf("%d", &val);
    while (val > 0){
        temp = malloc(sizeof(struct node));
        temp->val = val;
        temp->next = head;
        head = temp;
        val = scanf("%d", &val);
    }
    struct node *c;
    for (c = head; c != NULL; c = c->next){
        printf("%d", c->val);}
    printf("\n");
    head = reverseList(head);
    for (c = head; c != NULL; c = c->next){
        printf("%d", c->val);}
}
