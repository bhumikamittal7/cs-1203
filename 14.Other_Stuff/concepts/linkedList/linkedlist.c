#include <stdio.h>
#include <stdlib.h>

struct nodeType{
int val;
struct nodeType * next;
struct nodeType * next2;
struct nodeType * nextk;

};

typedef struct nodeType NodeAddress;

//convert array to linked list
NodeAddress * arrayToLinkedList(int * a, int n){
    NodeAddress * head = NULL;
    NodeAddress * current = NULL;
    int i;
    for(i=0;i<n;i++){
        current = malloc(sizeof(NodeAddress));
        current->val = a[i];
        current->next = NULL;
        if(head==NULL){
            head = current;
        }
        else{
            NodeAddress * temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = current;
        }
    }
    return head;
}

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

//reverse linked list
NodeAddress * reverseLLwithNext1(NodeAddress * head){
    NodeAddress * current = head;
    NodeAddress * prev = NULL;
    NodeAddress * next = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}


//sort every k nodes in the linked list
NodeAddress * sortK(NodeAddress * head, int k){
    NodeAddress * current = head;
    NodeAddress * next = NULL;
    NodeAddress * prev = NULL;
    NodeAddress * newHead = NULL;
    int count = 0;
    while(current!=NULL && count<k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if(next!=NULL){
        head->next = sortK(next, k);
    }
    return prev;
}


//sort every third element in the singly linked list
void sortThird(NodeAddress * head){
    NodeAddress * current = head;
    int i = 0;
    while(current!=NULL){
        if(i%3==2){
            NodeAddress * temp = current;
            int j = 0;
            while(temp!=NULL){
                if(j%3==0){
                    if(temp->val < current->val){
                        int tempVal = temp->val;
                        temp->val = current->val;
                        current->val = tempVal;
                    }
                }
                j++;
                temp = temp->next;
            }
        }
        i++;
        current = current->next;
    }
}

int main(int argc, char **argv){
    int a[] = {12,20,2,13,32,50,82,21,18,91};
    int n = 10;
    NodeAddress * head = arrayToLinkedList(a,n);
    printLinkedList(head);
    sortThird(head);
    printLinkedList(head);
    return 0;
}
