#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node *NodeAddress;

void bubbleSort(int *a, int n){
    int done, i, t, swap; //number of elements already sorted

    for(done = 0; done<n; done++){  //n could be n-1 as well because if n-1 is sorted, n is also sorted
        
        swap = 0;
        for(i=0; i<n-1-done; i++){
            if(a[i]>a[i+1]){
                //swap these elements because they are out of order
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
                swap = 1;
            }
        }   //end of inner for loop
        if (swap == 0) 
            break;
    }  //end of outer for loop
}

NodeAddress bubbleSortLinkedList(NodeAddress head){
    NodeAddress c, lastDone;
    for (lastDone = NULL; lastDone != head; lastDone = c /*wherever the inner loop finishes*/ ){
        for (c = head; c->next != lastDone; c = c->next){
            if (c->val > c->next->val){
                //just swap the values
                int t = c->val;
                c->val = c->next->val;
                c->next->val = t;
            }
        } //end of c loop - the element has been bubbled upto position c
    }
    
    return head;
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
    bubbleSort(a,n);
    printArray(a,n);
    
    printLinkedList(list);
    bubbleSortLinkedList(list);
    printLinkedList(list);

    free(a);
    freeLinkedList(list);
    
    return 0;
}