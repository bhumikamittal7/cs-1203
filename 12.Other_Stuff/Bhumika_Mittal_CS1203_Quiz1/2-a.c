#include <stdio.h>
#include <stdlib.h>

struct nodeType{
int val;
struct nodeType * next;
struct nodeType * next2;
struct nodeType * nextk;
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

//next2 points two nodes ahead, i.e., next next.
//Given an array with n elements, convert it into such a linked list.
NodeAddress * arrayToLLWithNext2(int * a, int n){
    if (n<=0){
        return NULL;
    }
    NodeAddress * head = malloc(sizeof(NodeAddress));
    head->val = a[0];
    head->next = NULL;
    head->next2 = NULL;
    NodeAddress * temp = head;
    int i;
    for(i=1;i<n;i++){
        NodeAddress * newNode = malloc(sizeof(NodeAddress));
        newNode->val = a[i];
        newNode->next = NULL;
        newNode->next2 = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    for(i=0;i<n;i++){
        if(i+2<n){
            temp->next2 = temp->next->next;
        }
        temp = temp->next;
    }
    return head;
}

//driver function
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(a)/sizeof(a[0]);

    NodeAddress * head = arrayToLLWithNext2(a,n);
    printLinkedList(head);

    return 0;
}