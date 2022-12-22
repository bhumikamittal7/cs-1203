//Given a set of values (assume int), create a linked list from them and print the list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

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
        free(temp);
    }
    struct node *c;
    for (c = head; c != NULL; c = c->next){
        printf("%d", c->val);}
}
