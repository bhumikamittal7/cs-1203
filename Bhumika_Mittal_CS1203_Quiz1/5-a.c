#include <stdio.h>
#include <stdlib.h>

//generate random array
int * generateRandomArray(int n){
    int * a = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i] = rand()%500 - 50;    //generate random numbers between -50 and 450
    }
    return a;
}

//sort every third element in an array
int * sortEveryThirdElement(int * a, int n){
    if (n<1){
        return NULL;            //if the array is smaller than 3, return Null
    }
    for(int i=5;i<n;i++){
        if(i%3==2){
            int j;
            for(j=2;j<n;j++){
                if(j%3==2){
                    if(a[j] > a[i]){
                        int tempVal = a[j];
                        a[j] = a[i];
                        a[i] = tempVal;
                    }
                }
            }
        }
    }
    return a;
}

//driver function
int main( ){
    int n = rand()%25 + 1;    //generate random numbers between 1 and 25
    int * a = generateRandomArray(n);

    printf("The original array is: \n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    printf("\n");

    printf("The every third element sorted array is: \n");
    int * b = sortEveryThirdElement(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",b[i]);
    }

    return 0;
}