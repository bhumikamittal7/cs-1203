//Write a function to find the address of the max element in an array

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

int findAddressofMax(int *a, int n){
    int *amax = NULL;
    if (n>=1) {
        amax = a; //initially, the address of max element = address of first element
        for (int i = 1; i < n; i++){
            if (*(a+i) > *(a+amax)) {amax = i;}
        }
    }
    return amax;
}


int main(int argc, char **argv){
    int *a;
    int n = 10;
    srand(time(NULL));

    a = generateArray(n);

    printArray(a,n);
    printf("Address of max = %d , value of max element = %d \n", findAddressofMax(a,n), *(findAddressofMax(a,n)));

    free(a);
    
    return 0;
}