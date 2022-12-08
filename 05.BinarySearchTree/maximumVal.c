//find the maximum value in the binary search tree
NodeAddress * maximum(NodeAddress * root){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL){
        return root;
    }
    else{
        return maximum(root->left);
    }   
}

//check if the value is the maximum value in the BST
int isMax(NodeAddress * root, int val){
    if(maximum(root)->val == val){
        return 1;       //if the value is the maximum value, return 1
    }
    else{
        return 0;       //if the value is not the maximum value, return 0
    }
}
