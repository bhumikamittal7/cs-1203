//Selection Sort for Array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateArray(int n){
    int *t = malloc (n*sizeof(int));
    if(t) {
        for (int i = 0; i < n; i++){ t[i] = rand()%1000;} //generate number between 0-999
        //variable i is local to this function - variable scope thing
    }
    return t;
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

int main(int argc, char **argv){
    int *a;
    int n = 10;
    NodeAddress list;
    srand(time(NULL));

    a = generateArray(n);

    printArray(a,n);
    selectionSort(a,n);
    printArray(a,n);

    free(a);
    
    return 0;
}

/*
void selectionSort2(int *a, int n){
    for (int *c = a+n-1; c !=a; c--){
        swap(findAddressofMax(a, c), c);
    }
}
*/