#include <stdio.h>
#include <stdlib.h>

struct nodeType{
int val;
int k;
struct nodeType * next;
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

//generate random number between 2 and 5
int randomNum(){
    return rand()%4 + 2;
}

//convert array to linked list with connection between nodes k nodes apart
NodeAddress* arrayToLLWithNextK(int * a, int n){
    if (n<=0){
        return NULL;
    }
    NodeAddress * head = malloc(sizeof(NodeAddress));
    head->val = a[0];
    head->k = randomNum();
    head->next = NULL;
    head->nextk = NULL;
    NodeAddress * temp = head;
    int i;
    for(i=1;i<n;i++){
        NodeAddress * newNode = malloc(sizeof(NodeAddress));
        newNode->val = a[i];
        newNode->k = randomNum();
        newNode->next = NULL;
        newNode->nextk = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    for(i=0;i<n;i++){
        if(i+temp->k<n){
            temp->nextk = temp->next;
            int j;
            for(j=0;j<temp->k-1;j++){
                temp->nextk = temp->nextk->next;
            }
        }
        temp = temp->next;
    }
    return head;
}

//reverse the above linked list
NodeAddress * reverseLLWithNextK(NodeAddress * head){
    NodeAddress * temp = head;
    NodeAddress * prev = NULL;
    NodeAddress * prev2 = NULL;
    NodeAddress * next = NULL;
    NodeAddress * nextk = NULL;

    while(temp!=NULL){
        next = temp->next;
        temp->next = prev;
        nextk = temp->nextk;
        temp->nextk = prev2;
        prev = temp;
        prev2 = temp->next;
        temp = next;
    }
    head = prev;
    return head;
}

//driver function
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(a)/sizeof(a[0]);

    NodeAddress * head = arrayToLLWithNextK(a,n);
    head = reverseLLWithNextK(head);
    printLinkedList(head);
    
    return 0;
}