/*
max binary heap - parent is larger than both of its children
min binary heap - parent is smaller than both of its children (doesnn't have to perfectly balanced) - binary means atmost 2 children
           12
        /       \
       17        81
     /   \     /    \ 
    18   93   882    82
    /\   /\   /\     /
110 112 94 95 889 885 97

extractMin - the root is the smallest element
insert - insert at the end and bubble up
delete - delete the root and bubble down
Reheapify - bubble down (sift down) or bubble up (sift up)

left child at 2p+1 and right child at 2p+2
to find parent of a child at position c, use floor[(c-1)/2]

NOTE - use array to implement heap (because we know how to pretend and ofc we are smort af!)

logn time to extract min
- selection sort using heap is heap sort - O(nlogn)
*/

/*
Given the array - 88, 99, 4, 42, 11, 35, 57, 3, 49, 69, 73, 20
Reverse sort - 99, 88, 73, 69, 57, 49, 42, 35, 20, 11, 4, 3

The max heap would be 
99
88 73
69 57 49 42
35 20 11 4 3

extract the max element - 
3
88 73
69 57 49 42
35 20 11 4 99

sift down but ignore 99, the reheapified heap would be -
88
69 73
35 57 49 42
3 20 11 4 99
*/

