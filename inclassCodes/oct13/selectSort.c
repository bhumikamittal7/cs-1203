//Select Sort
/*  100 buckets filled with different amounts of water, 
    sort them by weight

    bucket numbers - 0,1,2,...,99

*COMPARISON SORTS*
find the max bucket and put it at the end

func selectionSort(a, n):
    n = 100

    for (i=n; i>0; i--){
        imax = findIndexofMax(a, i)
        //swap the last element with the max element - swap(a[i], a[imax])
        t = a[imax]; a[imax] = a[i-1]; a[i-1] =t; 
    }

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

void selectionSort(int *a, int n){
    int imax, t;
    for (int i = n; i > 0; i--){
        imax = findIndexofMax(a, i);
        swap(&a[imax], &a[i-1]);  //swap(a+imax, a+i-1);
    }
}

/*
void selectionSort2(int *a, int n){
    for (int *c = a+n-1; c !=a; c--){
        swap(findAddressofMax(a, c), c);
    }
}
*/

int main(int argc, char **argv){
    int *a;
    int n = 10;
    NodeAddress list;
    srand(time(NULL));

    a = generateArray(n);
    list = linkedlistFromArray(a,n);

    printArray(a,n);
    selectionSort(a,n);
    printArray(a,n);

    free(a);
    freeLinkedList(list);
    
    return 0;
}







//===============================================================================================

/* TO DO
1. Write a function to find the address of the max element in an array
 -  int findAddressofMax(int *a, int n)

    int *amax = NULL;
    if (n<1) {return amax;}
     for (int i = 1; i < n; i++){
        if (*(a+i) > *(a+amax) amax = i;
    }
    return amax;

2. Write a function to find the address of the max element in a linked list
    -  NodeAddress findAddressofMax(NodeAddress head)
    
        NodeAddress amax = NULL;
        if (head == NULL) {return amax;}
        amax = head;
        while (head){
            if (head->val > amax->val) amax = head;
            head = head->next;
        }
        return amax;

3. Write a piece of code to check if the given array is sorted.
    int isSorted(int *a, int n)
        for (int i = 1; i < n; i++){
            if (a[i] < a[i-1]) return 0;
        }
        return 1;
*/