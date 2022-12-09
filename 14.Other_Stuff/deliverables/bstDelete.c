struct nodeType{
    int val;
    struct nodeType *left;      //left child - smaller than parent
    struct nodeType *right;     //right child - larger than parent
};

typedef struct nodeType *NodeAddress;

NodeAddress find Root (NodeAddresss x)
if (!x) return NULL;

while (x -> parent )
    x = x -> parent;

return x;

NodeAddress findMin (NodeAddress x)
if (!x) return NULL;

while (x -> left )
    x = x -> left;

return x;

NodeAddress findMax (NodeAddress x)
if (!x) return NULL;

while (x -> right )
    x = x -> right;

return x;

NodeAddress successor (NodeAddress x)
if (!x) return NULL;

if (x -> right )
    return findMin (x -> right);

NodeAddress y = x -> parent ;
while (y && x == y -> right )
{
    x = y;
    y = y -> parent ;
}

return y;

NodeAddress predecessor (NodeAddress x)
if (!x) return NULL;

if (x -> left )
    return findMax (x -> left);

NodeAddress y = x -> parent;
while (y && x == y -> left )
{
    x = y;
    y = y -> parent ;
}

return y;


NodeAddress search(NodeAddress root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->val == val){
        return root;
    }
    if(val < root->val){
        return search(root->left, val);
    }
    else{
        return search(root->right, val);
    }
}

//insert a node into the tree
NodeAddress insert(NodeAddress root, int val){
    if(root == NULL){
        root = (NodeAddress)malloc(sizeof(struct nodeType));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if(val < root->val){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

NodeAddress delete(NodeAddress root, int val){
    if(root == NULL){
        return NULL;
    }
    if(val < root->val){
        root->left = delete(root->left, val);
    }
    else if(val > root->val){
        root->right = delete(root->right, val);
    }
    else{
        if(root->left == NULL){
            NodeAddress temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            NodeAddress temp = root->left;
            free(root);
            return temp;
        }
        NodeAddress temp = findMin(root->right);
        root->val = temp->val;
        root->right = delete(root->right, temp->val);
    }
    return root;
}