/* Notes for Linked List

head = NULL
temp = allocate a house with 2 pointers
temp -> val = debG’s value (secret code 22812)
temp -> next = NULL

while(debG’s number is +ve):
    temp->next = malloc #get a new house with 2p
    temp = temp->next
    temp->val = debG val
    temp->next = NULL

struct node *c;
for (c = head; c != NULL; c = c->next){
    printf("%d\n", c->val);}
*/

#include <stdio.h>
#include <stdlib.h>


// Print the list
int main(){
    struct node *head = NULL;
    struct node *temp = NULL;
    int debG = 22812;
    while (debG > 0){
        temp = malloc(sizeof(struct node));
        temp->val = debG;
        temp->next = head;
        head = temp;
        debG = debG/2;
    }
    struct node *c;
    for (c = head; c != NULL; c = c->next){
        printf("%d\n", c->val);}
}