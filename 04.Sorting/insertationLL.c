//insertation sort for linked list
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node *NodeAddress;

void insertationSortLinkedList(NodeAddress head){
    NodeAddress i, j, key;
    for (i = head->next; i != NULL; i = i->next){
        key = i;
        j = i->next;
        while (j != NULL && j->val < key->val){
            key->val = j->val;
            j->val = key->val;
            j = j->next;
        }
    }
}

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

void printLinkedList(NodeAddress head){
    NodeAddress c;
    printf("Linked List = ");
    for (c = head; c!=NULL; c = c->next){
        printf(c==head?"%d":", %d", c->val);
    }
    printf("\n");
}

int main(){
    int *a;
    int n = 10;
    NodeAddress list;
    srand(time(NULL));

    a = generateArray(n);
    list = linkedlistFromArray(a,n);
    
    printLinkedList(list);
    insertationSortLinkedList(list);
    printLinkedList(list);

    free(a);
    freeLinkedList(list);
    
    return 0;
}