#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main(int argc, char **argv){
    int *a;
    int n = 10;

    srand(time(NULL));

    a = generateArray(n);
    printArray(a,n);

    bubbleSort(a,n);
    printArray(a,n);
    
    free(a);
    return 0;
}