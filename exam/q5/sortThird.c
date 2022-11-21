#include <stdio.h>
#include <stdlib.h>

//sort every third element in an array
int * sortEveryThirdElement(int * a, int n){
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

int main( ){
    int a[] = {12,20,2,13,32,50,82,21,18,91, 45, 67, 89, 23, 56, 78, 90, 34, 76, 9};
    int n = 20;
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    printf("\n");
    int * b = sortEveryThirdElement(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",b[i]);
    }

    return 0;
}