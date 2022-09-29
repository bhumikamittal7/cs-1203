/*
print the first half of the linked list - tortosie and hare algorithm
have two pointers pointing at head position
move one pointer twice as fast as the other
when the fast pointer reaches the end, the slow pointer is at the middle
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    int count = 0;
    struct node *t;
    struct node *r;
    t =r = head;

    //writing one loop, instead of multiple - maybe even if they are doing same thing is better because when there is a loop, 
    //there is a bunch of code that is repeated
    
    while (r != NULL && r->next != NULL){
        t = t->next;
        r = r->next->next;
    }

/*  while (r != NULL){
        r = r->next;
        count++;
    }
    for (i = 0; i < count/2; i++){
        t = t->next;
    for (i = 0; i < count/2; i++){
        printf("%d
    }

HOW TO DETECT A LOOP IN A LINKED LIST
1. create a link list
2. mess with that list, to test it.
3. take head of list, tell if the list has a weird loop inside it.

    struct node *t;
    struct node *r;
    t =r = head;

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

*/
   
    while(r){
        printf("%d\n", t->val);
        t = t->next;
        r = r->next;
        if(r){ // if r is not null, because you will get a seg fault if you try to access r->next when r is null
            r = r->next;
        }
        count++;
    }

}
