//quick sort for linked list

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node *NodeAddress;

void quickSortLinkedList(NodeAddress head, NodeAddress tail){
    NodeAddress i, j, pivot, temp;
    if (head != tail){
        pivot = head;
        i = head;
        j = head->next;
        while (j != tail){
            if (j->val < pivot->val){
                i = i->next;
                temp = i->val;
                i->val = j->val;
                j->val = temp;
            }
            j = j->next;
        }
        temp = i->val;
        i->val = pivot->val;
        pivot->val = temp;
        quickSortLinkedList(head, i);
        quickSortLinkedList(i->next, tail);
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
    quickSortLinkedList(list, NULL);
    printLinkedList(list);

    free(a);
    freeLinkedList(list);
    
    return 0;
}