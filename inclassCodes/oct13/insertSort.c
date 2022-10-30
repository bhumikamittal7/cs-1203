/* Insertion Sort 
there is a list - [977, 305, 7, 885, 428, 819, 929, 118, 640]
whenever you get the element - put it at the right place in the list
*/


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

int findIndexofMax(int *a, int n){
    //error case - there is no element in the array
    if (n<1) {return -1;}

    int imax = 0;   //index of max element = 0 initially
    for (int i = 1; i < n; i++){
        if (a[i] > a[imax]) imax = i;
    }
    return imax;
}

void swap (int *a, int *b){ 
    //why are we sending the address of a and b? 
    //because we want to change the value of a and b
    //if we send the value of a and b, we are just changing the value of the local variables (copy of that thing) and not the actual variables
    //also called pass by reference in some languages, C is pass by value

    int t = *a; *a = *b; *b = t;    
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
