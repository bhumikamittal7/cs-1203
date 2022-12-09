//array implementation of max heap

#include <stdio.h>
#include <stdlib.h>


//heapify the array
void heapify(int *a, int n, int currentIndex){
    //set the largest index to the current index(i), left to 2i+1, right to 2i+2
    int largest = currentIndex;
    int left = 2*currentIndex+1;
    int right = 2*currentIndex+2;

    //if left child is larger than root, set largest to left
    if(left < n && a[left] > a[largest]){
        largest = left;
    }

    //if right child is larger than root, set largest to right
    if(right < n && a[right] > a[largest]){
        largest = right;
    }

    //if largest is not the root, swap and heapify (recursively)
    if(largest != currentIndex){
        int temp = a[currentIndex];
        a[currentIndex] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

//create maxheap using heapify 
//optimisation - start with the first non-leaf node (because all leaf nodes are already heapified by default) and work up, index = n/2-1
void maxHeap(int *a, int n){
    //start with the first non-leaf node and work up
    for(int i = n/2-1; i>=0; i--){
        heapify(a, n, i);
    }
    //print the heap
    for(int i = 0; i<n; i++){
        printf("%d ", a[i]);
    }
}

//driver code
int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a)/sizeof(a[0]);
    maxHeap(a, n);
    return 0;
}


