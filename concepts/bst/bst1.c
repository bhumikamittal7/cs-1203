/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * @input B : Integer
 * 
 * @Output root pointer of tree.
 */
treenode* find(treenode* root,int B)
{
    treenode* current = root;
    if(root==NULL) return NULL;
    if(root->val==B) return root;
    if(root->val<B) return find(root->right,B);
    if(root->val>B) return find(root->left,B);
}
treenode* getSuccessor(treenode* A, int B) {
    //if(A==NULL) return A;
    treenode* current = find(A,B);
    if(current==NULL) return NULL;
    if(current->right!=NULL)
    {
        current = current->right;
        while(current->left!=NULL)
        current = current->left;
        return current;
    }
    treenode *a=A,*b=NULL;
    if(current->right==NULL)
    {
        while(a!=current)
        {
            if(current->val<a->val)
            {
                b = a;
                a = a->left;
            }
            else
                a = a->right;
        }
    return b;
    }
}
