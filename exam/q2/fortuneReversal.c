#include <stdio.h>
#include <stdlib.h>

struct nodeType{
int val;
struct nodeType * next;
struct nodeType * next2;
struct nodeType * nextk;
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

//next2 points two nodes ahead, i.e., next next. 
//Given an array with n elements, convert it into such a linked list.

NodeAddress* arrayToLLWithNext2(int * a, int n){
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

NodeAddress * reverseLLWithNext2(NodeAddress * head){
    NodeAddress * temp = head;
    NodeAddress * prev = NULL;
    NodeAddress * prev2 = NULL;
    NodeAddress * next = NULL;
    NodeAddress * next2 = NULL;

    while(temp!=NULL){
        next = temp->next;
        temp->next = prev;
        next2 = temp->next2;
        temp->next2 = prev2;
        prev = temp;
        prev2 = temp->next;
        temp = next;
    }
    head = prev;
    return head;
}


int main(int argc, char **argv){
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    NodeAddress * head = arrayToLLWithNext2(a,n);
    printLinkedList(head);
    head = reverseLLWithNext2(head);
    printLinkedList(head);
    free(head);
    return 0;
}