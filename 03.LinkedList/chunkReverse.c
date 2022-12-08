// given a linked list, reverse the nodes in chunks of size k
// e.g. 1->2->3->4->5->6->7->8->9->NULL, k=3
// output: 3->2->1->6->5->4->9->8->7->NULL


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

//chunk reverse linked list
NodeAddress * chunkReverse(NodeAddress * head, int k){
    NodeAddress * current = head;
    NodeAddress * prev = NULL;
    NodeAddress * next = NULL;
    int count = 0;
    while(current!=NULL && count<k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next!=NULL){
        head->next = chunkReverse(next,k);
    }
    return prev;
}

//driver function
int main( ){
    int n = rand()%25 + 1;    //generate random numbers between 1 and 25
    int * a = generateRandomArray(n);

    //print linked list
    printf("The linked list from the array is: \n");
    NodeAddress * head = arrayToList(a,n);
    printLinkedList(head);

    int k = 2;
    printf("The linked list after chunk (%d) reverse is: \n", k);
    head = chunkReverse(head,k);
    printLinkedList(head);
    
    return 0;
}
