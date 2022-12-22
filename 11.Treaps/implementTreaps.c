/*
1. Create a node with data and priority
2. Insert a node in the tree and then balance the tree
3. Keep doing it as we traverse through the given array
4. Print the tree in inorder
5. Delete -- delete a node from the tree and then balance the tree
6. Search -- search a node in the tree
7. Max Min-- get max/min value in the tree
8. Priority -- find priority of a node
9. PrintTreap -- print treap with priority
*/

#include <stdio.h>
#include <stdlib.h>

//generate a random array
int * generateRandomArray(int n){
    int * a = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i] = rand()%500 - 50;    //generate random numbers between -50 and 450
    }
    return a;
}

struct nodeType
{
    int data;
    int priority;
    struct nodeType *left;
    struct nodeType *right;
};

typedef struct nodeType NodeAddress;

NodeAddress *root = NULL;

//create a new node
NodeAddress *create(int data)
{
    NodeAddress *temp = (NodeAddress *)malloc(sizeof(NodeAddress));
    temp->data = data;
    temp->priority = rand() % 100;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//left rotate the tree
NodeAddress *leftrotate(NodeAddress *x)
{
    NodeAddress *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

//right rotate the tree
NodeAddress *rightrotate(NodeAddress *x)
{
    NodeAddress *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

//insert a node in the tree and then balance the tree
NodeAddress *insert(NodeAddress *root, int data)
{
    if (root == NULL)
        return create(data);
    if (data < root->data)
    {
        root->left = insert(root->left, data);
        if (root->left->priority > root->priority)
            root = rightrotate(root);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
        if (root->right->priority > root->priority)
            root = leftrotate(root);
    }
    return root;
}

//print the tree in inorder
void print(NodeAddress *root)
{
    if (root == NULL)
        return;
    print(root->left);
    printf("%d ", root->data);
    print(root->right);
}

//delete a node from the tree
NodeAddress *deletenode(NodeAddress *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deletenode(root->left, data);
    else if (data > root->data)
        root->right = deletenode(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            NodeAddress *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            NodeAddress *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            if (root->left->priority > root->right->priority)
            {
                root = rightrotate(root);
                root->right = deletenode(root->right, data);
            }
            else
            {
                root = leftrotate(root);
                root->left = deletenode(root->left, data);
            }
        }
    }
    return root;
}

//search a node in the tree
int search(NodeAddress *root, int data)
{
    if (root == NULL)
        return 0;
    if (root->data == data)
        return 1;
    if (root->data > data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

//get max value in the tree
int max(NodeAddress *root)
{
    if (root == NULL)
        return -1;
    if (root->right == NULL)
        return root->data;
    return max(root->right);
}

//get min value in the tree
int min(NodeAddress *root)
{
    if (root == NULL)
        return -1;
    if (root->left == NULL)
        return root->data;
    return min(root->left);
}

//find priority of a node
int priority(NodeAddress *root, int data)
{
    if (root == NULL)
        return -1;
    if (root->data == data)
        return root->priority;
    if (root->data > data)
        return priority(root->left, data);
    else
        return priority(root->right, data);
}

//print treap with priority
void printtreap(NodeAddress *root)
{
    if (root == NULL)
        return;
    printtreap(root->left);
    printf("%d(%d) ", root->data, root->priority);
    printtreap(root->right);
}

//driver function
int main()
{
    //int n = rand()%15 + 1;
    //int * arr = generateRandomArray(n);

    //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200};
    
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    //insert all the elements in the tree
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    //print the tree
    printf("Inorder traversal of the given tree:\n");
    printtreap(root);
    printf("\n");
    //delete a node from the trees
    int k = 5;
    root = deletenode(root, k);
    printf("After deleting a node %d, the tree is:\n", k);
    printtreap(root);    
    printf("\n");

    //search a node in the tree
    k = 10;
    if (search(root, k))
        printf("The node %d is present in the tree\n", k);
    else
        printf("The node %d is not present in the tree\n", k);

    //get max value in the tree
    printf("The maximum value in the tree is %d \n", max(root));

    //get min value in the tree
    printf("The minimum value in the tree is %d \n", min(root));

    //find priority of a node
    k = 7;
    printf("The priority of node %d is %d \n", k, priority(root, k));

    return 0;
}