//given an array of integers, create an AVL tree

//create a node
struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
typedef struct nodeType *NodeAddress;

//create a new node
NodeAddress newNode(int data){
    NodeAddress node = (NodeAddress)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}

//get the height of a node
int height(NodeAddress node){
    if(node == NULL)
        return -1;
    else
        return node->height;
}

//get the maximum of two integers
int max(int a, int b){
    return (a > b)? a : b;
}

//get the balance factor of a node
int getBalance(NodeAddress node){
    if(node == NULL)
        return 0;
    else
        return height(node->left) - height(node->right);
}

//right rotate
NodeAddress rightRotate(NodeAddress head){
    NodeAddress temp = head->left;
    NodeAddress temp2 = temp->right;
    temp->right = y;
    head->left = temp2;
    head->height = max(height(head->left), height(head->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    return x;
}

//left rotate
NodeAddress leftRotate(NodeAddress head){
    NodeAddress temp = head->right;
    NodeAddress temp2 = temp->left;
    temp->left = head;
    head->right = temp2;
    head->height = max(height(head->left), height(head->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    return temp;
}

//insert a node
NodeAddress insert(NodeAddress head, int data){
    if(head == NULL)
        return newNode(data);
    if(data < head->data)
        head->left = insert(head->left, data);
    else if(data > head->data)
        head->right = insert(head->right, data);
    else
        return head;
    head->height = 1 + max(height(head->left), height(head->right));
    int balance = getBalance(head);
    if(balance > 1 && data < head->left->data)
        return rightRotate(head);
    if(balance < -1 && data > head->right->data)
        return leftRotate(head);
    if(balance > 1 && data > head->left->data){
        head->left = leftRotate(head->left);
        return rightRotate(head);
    }
    if(balance < -1 && data < head->right->data){
        head->right = rightRotate(head->right);
        return leftRotate(head);
    }
    return head;
}

//create an AVL tree from an array
NodeAddress arrayToAVL(int arr[], int n){
    NodeAddress head = NULL;
    for(int i = 0; i < n; i++)
        head = insert(head, arr[i]);
    return head;
}

//print the tree
void printTree(NodeAddress head){
    if(head == NULL)
        return;
    printTree(head->left);
    printf("%d ", head->data);
    printTree(head->right);
}

//main function
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    NodeAddress head = arrayToAVL(arr, n);
    printTree(head);
    return 0;
}