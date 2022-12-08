// QUICK SORT CODE TO SORT AN ARRAY

#include <stdio.h>
#include <stdlib.h>

int partition(int *a, int start, int end){
    int pivot = a[end];
    int pIndex = start;
    for (int i = start; i < end; i++){
        if(a[i] <= pivot){
            int temp = a[i];
            a[i] = a[pIndex];
            a[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = a[pIndex];
    a[pIndex] = a[end];
    a[end] = temp;
    return pIndex;
}

void quickSort(int *a, int start, int end){
    if(a && start < end){
        int pIndex = partition(a, start, end);
        quickSort(a, start, pIndex-1);
        quickSort(a, pIndex+1, end);
    }
}

void main(){
    int a[] = {7, 2, 1, 6, 8, 4, 3, 4};
    int n = sizeof(a)/sizeof(a[0]);
    quickSort(a, 0, n-1);
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}