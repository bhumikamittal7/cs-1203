//given a linked list, print the first half of the list without knowing the length of the list

/* 
print the first half of the linked list - tortosie and hare algorithm
have two pointers pointing at head position
move one pointer twice as fast as the other
when the fast pointer reaches the end, the slow pointer is at the middle
*/

/*
//include functions from other files
#include "arrayToList.c"
#include "printLinkedList.c"
*/

#include <stdio.h>
#include <stdlib.h>

struct nodeType{
int val;
struct nodeType * next;
};

typedef struct nodeType NodeAddress;

//print linked list
void printLinkedList(NodeAddress * head){
    NodeAddress * current = head;
    while(current!=NULL){
        if (current->next==NULL){
            printf("%d",current->val);
        }
        else{
            printf("%d->",current->val);
        }
        current = current->next;
    }
    printf("\n");
}

//given an array, make a linked list and print it
NodeAddress * arrayToList(int * a, int n){
    NodeAddress * head = NULL;
    NodeAddress * current = NULL;
    for(int i=0;i<n;i++){
        NodeAddress * temp = malloc(sizeof(NodeAddress));
        temp->val = a[i];
        temp->next = NULL;
        if (i==0){
            head = temp;
            current = temp;
        }
        else{
            current->next = temp;
            current = temp;
        }
    }
    return head;
}

//generate random array
int * generateRandomArray(int n){
    int * a = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i] = rand()%500 - 50;    //generate random numbers between -50 and 450
    }
    return a;
}


//Second half of the list - hare and tortoise algorithm
void secondHalfList(NodeAddress * head){
    NodeAddress * slow = head;
    NodeAddress * fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    printLinkedList(slow);
}
//First half of the list - hare and tortoise algorithm
void firstHalfList(NodeAddress * head){
    NodeAddress * slow = head;
    NodeAddress * fast = head;
    printf("%d ",slow->val);
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        if (fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            printf("%d ",slow->val);
        }
    }
    printf("\n");
}

int main(){
    int n = rand()%25 + 1;    //generate random numbers between 1 and 10
    int * a = generateRandomArray(n);

    NodeAddress * head = arrayToList(a,n);

    printf("The linked list is: \n");
    printLinkedList(head);

    printf("The first half of the linked list is: \n");
    firstHalfList(head);

    printf("The second half of the linked list is: \n");
    secondHalfList(head);

    return 0;
}