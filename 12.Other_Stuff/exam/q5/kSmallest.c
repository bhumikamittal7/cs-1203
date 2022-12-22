#include<stdio.h>
#include<stdlib.h>

//remove the every third element from the array
int * removeEveryThirdElement(int * a, int n){
    int * b = (int *)malloc(sizeof(int)*n);
    int j=0;
    for(int i=0;i<n;i++){
        if(i%3!=2){
            b[j] = a[i];
            j++;
        }
    }
    return b;
}

//heapify the array
void heapify(int *a, int n, int currentIndex){
    //set the smallest index to the current index(i), left to 2i+1, right to 2i+2
    int smallest = currentIndex;
    int left = 2*currentIndex+1;
    int right = 2*currentIndex+2;

    //if left child is larger than root, set smallest to left
    if(left < n && a[left] < a[smallest]){
        smallest = left;
    }

    //if right child is smallest than root, set smallest to right
    if(right < n && a[right] < a[smallest]){
        smallest = right;
    }

    //if smallest is not the root, swap and heapify (recursively)
    if(smallest != currentIndex){
        int temp = a[currentIndex];
        a[currentIndex] = a[smallest];
        a[smallest] = temp;
        heapify(a, n, smallest);
    }
}

//create min heap using heapify
void minHeap(int *a, int n){
    //start with the first non-leaf node and work up
    for(int i = n/2-1; i>=0; i--){
        heapify(a, n, i);
    }
}

//extract the root node and heapify the tree
int extractMin(int *minHeap, int n){
    int min = minHeap[0];
    minHeap[0] = minHeap[n-1];
    heapify(minHeap, n-1, 0);
    return min;
}


//find the kth smallest element in an array
void findKthSmallest(int *a, int k, int n){
    if (n>3){
    int * b = removeEveryThirdElement(a,n);
    n = n-n/3;
    if (k>n || k<1){
        return;
    }
    //create a min heap
    minHeap(b, n);
    //extract the root node k times
    for(int i=0; i<k-1; i++){
            extractMin(b, n);
    }
    //print the kth smallest element
    printf("%d", b[0]);
}
}


int main( ){
    int a[] = {12,20,2,13,32,50,82,21,18,91, 45, 67, 89, 23, 56, 78, 90, 34, 76, 9};
    int n = 20;
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    printf("\n");
    findKthSmallest(a,0,n);
    return 0;
}