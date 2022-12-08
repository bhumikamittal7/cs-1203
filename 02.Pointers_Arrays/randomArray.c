#include <stdio.h>

//generate random array
int * generateRandomArray(int n){
    int * a = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i] = rand()%500 - 50;    //generate random numbers between -50 and 450
    }
    return a;
}

int main( ){
    int n = rand()%25 + 1;    //generate random numbers between 1 and 25
    int * a = generateRandomArray(n);

    printf("The original array of len %d is: \n", n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    printf("\n");

    return 0;
}