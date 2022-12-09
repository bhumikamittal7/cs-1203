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

//sort every third element in an array
int * sortEveryThirdElement(int * a, int n){
    for(int i=5;i<n;i++){
        if(i%3==2){
            int j;
            for(j=2;j<n;j++){
                if(j%3==2){
                    if(a[j] > a[i]){
                        int tempVal = a[j];
                        a[j] = a[i];
                        a[i] = tempVal;
                    }
                }
            }
        }
    }
    return a;
}

//find the k smallest element among the untouched elements in an array
int findKthSmallest(int * a, int k, int n){
    int smallest = a[0];
    for (int i=0;i<n;i++){
        if(i%3!=2){
            if(a[i]<smallest){
                smallest = a[i];
            }
        }
    }
    return smallest;
}

int main(int argc, char **argv){
    int a[] = {12,20,2,13,32,50,82,21,18,91, 45, 67, 89, 23, 56, 78, 90, 34, 76, 9};
    int n = 20;
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    printf("\n");
    int * b = sortEveryThirdElement(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",b[i]);
    }
    printf("\n");
    printf("%d",findKthSmallest(a,1, n));

    return 0;
}