
//find the successor of the value in the BST
NodeAddress * successor(NodeAddress * root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->val == val){
        if(root->left != NULL){
            return root->left;
        }
        else{
            return NULL;
        }
    }
    if(val < root->val){
        return successor(root->right, val);
    }
    else{
        return successor(root->left, val);
    }
}
