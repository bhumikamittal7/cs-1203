/*
HOW TO DETECT A LOOP IN A LINKED LIST
1. create a link list
2. mess with that list, to test it.
3. take head of list, tell if the list has a weird loop inside it.
*/

#include <stdlib.h>
#include <stdio.h>

    struct node *t;
    struct node *r;
    t =r = head;

int main(){
    while (r != NULL && r->next != NULL){
        t = t->next;
        r = r->next->next;
        if (t == r){
            printf("Loop detected");
            break;
        }
    }
    if (r == NULL || r->next == NULL){
        printf("No loop detected");
    }

}