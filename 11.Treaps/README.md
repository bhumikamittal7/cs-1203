# CS-1203 Project - Treaps

## Introduction
A treap is a self-balancing binary search tree that uses a combination of the binary search tree property and a priority value associated with each node to maintain balance. The priority values are usually assigned randomly to each node when it is inserted into the tree.

## Why Treaps?
Since we learnt about BST, and heaps in class, it would be interesting to look at the data structure which combines the properties of both trees and heaps – hence, the name TREAPS. It is a very useful data structure as it is used to solve various problems like connectivity problems, range query problems and can be used as good alternatives to segment trees/sparse tables and splay trees in some of the scenerios as they are relatively also easier to code. It uses randomization of nodes which drives the spontaneous rotations to keep itself balanced in terms of height such that the operations that are performed on Treaps stay efficient in terms of time complexity. 

They are used to store data in a way that is easy to search and easy to maintain such as in a database. 

## Operations on Treaps
1. Create a node with data and priority
2. Insert a node in the tree and then balance the tree
3. Keep doing it as we traverse through the given array
4. Print the tree in inorder
5. Delete -- delete a node from the tree and then balance the tree
6. Search -- search a node in the tree
7. Max Min-- get max/min value in the tree
8. Priority -- find priority of a node
9. PrintTreap -- print treap with priority

## Time Complexity
1. Insertion - O(log n)
2. Deletion - O(log n)
3. Search - O(log n)
4. Max Min - O(log n)
5. Priority - O(log n)
6. PrintTreap - O(n)

## Space Complexity
1. Insertion - O(n)
2. Deletion - O(n)
3. Search - O(n)
4. Max Min - O(n)
5. Priority - O(n)
6. PrintTreap - O(n)

## Testing the code
I have generated a random array of size 200 and then inserted it into the treap. I have then printed the treap inorder and then deleted the nodes one by one and printed the treap inorder after each deletion. I have also tested the search, max, min and priority functions.

## How to run the code - implementTreaps.c
1. Download the code
2. Open the code in any IDE (preferably VS Code)
3. Run the code (gcc -o treap implementTreaps.c)


## Implementation on Real Life Problem - Customer Records
One real-life example of using a treap might be in a database of customer records for a company. Each customer record could be stored in a node in the treap, with the customer's name as the key value. The treap would be balanced so that the records are stored in alphabetical order by customer name, making it easy to search for a particular customer by name.

NOTE -- I have used the same code for implementing the treap and the customer database. I have just added the customer database code in the same file. Also, since the treaps works best for sorted data, I have sorted the priority before inserting it into the treap.
 
## How to run the code - customerDatabase.c
1. Download the code
2. Open the code in any IDE (preferably VS Code)
3. Run the code (gcc -o records customerDatabase.c)

## Further Improvements
1. Add more functions like split, merge, etc.
2. Add more functions to the customer database code.
3. Make the customer database code work for random order of priority as well.
4. Visualize the treap using graphics.