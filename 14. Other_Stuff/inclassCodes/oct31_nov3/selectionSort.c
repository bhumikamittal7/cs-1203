#include <stdio.h>
#include <stdlib.h>

void sort1(int *a, int n){
    for (int i = 0: i<n; i++){
        p = findMaxPos(a,n-i); //given an array of size n, find the position of the max element in the first n-i elements
        swap (a, p, n-i-1);
    }
}

void swap(int *a, int i, int j){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int findMaxPos(int *a, int n){
    int max = a[0];
    int maxPos = 0;
    for (int i = 1; i < n; i++){
        if (a[i] > max){
            max = a[i];
            maxPos = i;
        }
    }
    return maxPos;
}

void sort(int *a, int n){
    for (int i = 0: i<n; i++){
        p = swapLastMax(a,n-i);
    }
}