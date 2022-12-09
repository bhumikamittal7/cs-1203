#include <stdio.h>
#include <stdlib.h>

struct nodeType{
int val;
struct nodeType * next;
struct nodeType * next5;
struct nodeType * next10;
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
//print linked list with next5
void printLinkedList5(NodeAddress * head){
    printf("%d ",head->val);
    NodeAddress * current = head;
    while(current!=NULL){
        if (current->next5!=NULL){
            printf("%d ",current->next->val);
        }
        current = current->next;
    }
    printf("\n");
}
//print linked list with next10
void printLinkedList10(NodeAddress * head){
    printf("%d ",head->val);
    NodeAddress * current = head;
    while(current!=NULL){
        if (current->next10!=NULL){
            printf("%d ",current->next->val);
        }
        current = current->next;
    }
    printf("\n");
}

//convert an array to skip list
NodeAddress * arrayToSkipList(int * a, int n){
    NodeAddress * head = (NodeAddress *)malloc(sizeof(NodeAddress));
    head->val = a[0];
    head->next = NULL;
    head->next5 = NULL;
    head->next10 = NULL;

    NodeAddress * current = head;
    for(int i=1;i<n;i++){
        NodeAddress * newNode = (NodeAddress *)malloc(sizeof(NodeAddress));
        newNode->val = a[i];
        newNode->next = NULL;
        newNode->next5 = NULL;
        newNode->next10 = NULL;

        current->next = newNode;
        current = current->next;
    }

    //add next5 and next10
    current = head;
    int count = 0;
    while(current!=NULL){
        count++;
        if (count%5==0){
            current->next5 = current->next;
        }
        if (count%10==0){
            current->next10 = current->next;
        }
        current = current->next;
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
    int n = 31;    
    int * a = generateRandomArray(n);

    printf("The original array of length %d is: \n", n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    printf("\n");

    printf("The skip list is: \n");
    NodeAddress * head = arrayToSkipList(a,n);
    printLinkedList(head);
    printLinkedList5(head);
    printLinkedList10(head);

    return 0;
}