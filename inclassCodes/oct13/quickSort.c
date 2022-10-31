/* DIVIDE AND CONQUOR METHOD

for any comparison based sorting algorithm,
HOW MUCH time it takes to sort a list of n elements

n -> 2 branches of decision making 

there is starting list [x1, x2, x3, ... xn] --> sorted list
there are n! possible ways to sort the list
1 out of n! is the correct answer

How many IFs do we need to write to sort a list of n elements?
log_2 (n!) = log_2 (n * (n-1) * (n-2) * ... * 1) = log_2 (n) + log_2 (n-1) + log_2 (n-2) + ... + log_2 (1) > log_2(n^n) = n*log_2(n)
- Need more than nlogn time to do it.

how to put let's say element a[485] = 14 at its correct position - we go through the list and find all elements smaller than 14 (let's say 300 of them), then we put 14 at 301 position

Run through the list, and find a pivot element and put it at beginning. Smaller element go to one side of pivot, and put greater the other side. 
Then we sort the two sides. 

- Time complexity analysis

n/2 gives log_2 (n)
if we divide the list in 10:90 ratio then time complexity is log_(10/9) (n)

log n rows - and each row we are doing n work - so nlogn

Worst case: you pick smallest element every single time - n^2
Best case: you pick the middle element every single time - nlogn

*/
// QUICK SORT CODE TO SORT AN ARRAY

#include <stdio.h>
#include <stdlib.h>

int partition1(int *a, int start, int stop){
    int pivot = a[start];
    int i = start+1;
    int j = stop;

    while (i <= j){
        if (a[i] > pivot){
            swap (a, i, j);
            j--;
        }
        else { 
            i++;
        }
    }
    swap (a, start, j);
    return j;
}

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