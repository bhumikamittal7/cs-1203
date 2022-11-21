#include<stdio.h>
#include<stdlib.h>

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
void buildMaxHeap(int *a, int n){
    //start with the first non-leaf node and work up
    for(int i = n/2-1; i>=0; i--){
        heapify(a, n, i);
    }
}

//extract the root node and heapify the tree
int extractMax(int *maxHeap, int n){
    int max = maxHeap[0];
    maxHeap[0] = maxHeap[n-1];
    heapify(maxHeap, n-1, 0);
    return max;
}

//print the smallest element in the max heap
void returnsmallestNum(int *maxHeap, int n){
    if (n<1){
        return;            //if the heap array is smaller than 1, return Null
    }

    buildMaxHeap(maxHeap, n);

    int smallest = maxHeap[n/2-1];
    for (int i = n/2-1; i<n; i++){
        if (maxHeap[i] < smallest){
            smallest = maxHeap[i];
        }
    }
    printf("%d", smallest);
}

//driver function
int main(){
    int a[] = {89, 78, 1, 5, 81, 43, 8, 7, 6, 5, 4, 3, 2, 1, -1};
    int n = sizeof(a)/sizeof(a[0]);

    returnsmallestNum(a, n);

    return 0;

}