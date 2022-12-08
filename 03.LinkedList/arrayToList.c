#include <stdio.h>
#include <stdlib.h>

struct nodeType{
int val;
struct nodeType * next;
};

typedef struct nodeType NodeAddress;

//NodeAddress * head is equivalent to NodeAddress head

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

//driver function
int main( ){
    int n = rand()%25 + 1;    //generate random numbers between 1 and 25
    int * a = generateRandomArray(n);

    printf("The original array of length %d is: \n", n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    printf("\n");

    //print linked list
    printf("The linked list from the array is: \n");
    NodeAddress * head = arrayToList(a,n);
    printLinkedList(head);

    return 0;
}