#include<stdio.h>
#include<stdlib.h>

//max heap - parent is larger than both of its children
//generate a max heap from an array

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

//extract the root node and heapify the tree
int extractMax(int *maxHeap, int n){
    int max = maxHeap[0];
    maxHeap[0] = maxHeap[n-1];
    heapify(maxHeap, n-1, 0);
    return max;
}

// print the third largest element in the max heap
void thirdLargestNum(int *maxHeap, int n){
    int max = 0;
    if (n<3){
        return;
    }
    for(int i = 0; i<3; i++){               //extract the root node 3 times - this can now be generalised to extract the kth largest element
        max = extractMax(maxHeap, n-i);
    }
    printf("\n%d", max);
}

//print the smallest element in the max heap
void returnsmallestNum(int *maxHeap, int n){
    int smallest = maxHeap[n/2-1];
    for (int i = n/2-1; i<n; i++){
        if (maxHeap[i] < smallest){
            smallest = maxHeap[i];
        }
    }
    printf("\n%d", smallest);
}

//driver function
int main(){
    int a[] = {11, 8};
    int n = sizeof(a)/sizeof(a[0]);
    maxHeap(a, n);
    thirdLargestNum(a, n);
    returnsmallestNum(a, n);
    return 0;

}