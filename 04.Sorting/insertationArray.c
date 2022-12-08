//Insertation sort for array
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

//Insertation sort for array
void insertationSort(int *a, int n){
    int i, j, key;
    for (i = 1; i < n; i++){
        key = a[i];
        j = i-1;
        while (j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(int argc, char **argv){
    int *a;
    int n = 10;

    srand(time(NULL));

    a = generateArray(n);
    printArray(a,n);

    insertationSort(a,n);
    printArray(a,n);
    
    free(a);
    return 0;
}