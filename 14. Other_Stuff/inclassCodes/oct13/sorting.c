//Insert Sort
//Select Sort
//Quick Sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node *NodeAddress;

int generateArray(int n){
    int *t = malloc (n*sizeof(int));
    if(t) {
        for (int i = 0; i < n; i++){ t[i] = rand()%1000;} //generate number between 0-999
        //variable i is local to this function - variable scope thing
    }
    return t;
}

NodeAddress linkedlistFromArray(int *a, int n){
    NodeAddress head = NULL;
    NodeAddress temp = NULL;
    
    // special case for head
    if(n>0){
        head = malloc(sizeof(struct node));
        head->val = a[0];
        head->next = NULL;
        temp = head;
    }

    for (int i = 1; i < n; i++){
        temp ->next = malloc(sizeof(struct node));
        temp = temp->next;
        temp->val = a[i];
        temp->next = NULL;
        
    }
    return head;
}


void freeLinkedList (NodeAddress head){
    //can't delete the current object, otherwise we can't move ahead anymore
    //so we move ahead, and then delete the previous object

    NodeAddress prev;
    while (head){
        prev = head;
        head = head->next;
        free(prev);
    }
}

void printArray(int *a, int n){
    printf("Array = ");
    for (int i = 0; i < n; i++){
        printf(i?", %d":"%d", a[i]);
    }
    printf("\n");
}

void printArray1(int *a, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

void printLinkedList(NodeAddress head){
    NodeAddress c;
    printf("Linked List = ");
    for (c = head; c!=NULL; c = c->next){
        printf(c==head?"%d":", %d", c->val);
    }
    printf("\n");
}

int main(int argc, char **argv){
    int *a;
    int n = 10;
    NodeAddress list;
    srand(time(NULL));

    a = generateArray(n);
    list = linkedlistFromArray(a,n);

    printArray(a,n);

    free(a);
    freeLinkedList(list);
    
    return 0;
}