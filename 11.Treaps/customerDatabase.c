#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
  char name[100];
  int id;
} Customer;

typedef struct nodeType {
  Customer data;
  int priority;
  struct nodeType *left;
  struct nodeType *right;
} NodeAddress;

typedef struct treap {
  NodeAddress *root;
} Treap;

//create a new node with the given data and priority
NodeAddress* createNode(Customer data, int priority) {
    NodeAddress *node = (NodeAddress*)malloc(sizeof(NodeAddress));
    node->data = data;
    node->priority = priority;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//left rotate the tree
void rotateLeft(NodeAddress **root) {
    NodeAddress *temp = *root;
    *root = temp->right;
    temp->right = (*root)->left;
    (*root)->left = temp;
}

//right rotate the tree
void rotateRight(NodeAddress **root) {
    NodeAddress *temp = *root;
    *root = temp->left;
    temp->left = (*root)->right;
    (*root)->right = temp;
}

//insert a node in the tree and then balance the tree
void insert(Treap *treap, Customer data, int priority) {
    NodeAddress *node = createNode(data, priority);

    if (treap->root == NULL) {
        // Treap is empty, insert node as root
        treap->root = node;
    } else {
        // Find the correct position to insert the node
        NodeAddress *temp = treap->root, *parent = NULL;
        while (temp != NULL) {
            parent = temp;
            if (node->data.id < temp->data.id) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        // Insert the node
        if (node->data.id < parent->data.id) {
            parent->left = node;
        } else {
            parent->right = node;
        }

        // Balance the tree
        while (node != treap->root && node->priority < parent->priority) {
            if (node == parent->left) {
                rotateRight(&parent);
            } else {
                rotateLeft(&parent);
            }
        }
    }
}

//delete a node from the treap
void deleteNode(NodeAddress **root, int id) {
    if (*root == NULL) {
        return;
    }

    if (id < (*root)->data.id) {
        deleteNode(&(*root)->left, id);
    } else if (id > (*root)->data.id) {
        deleteNode(&(*root)->right, id);
    } else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            NodeAddress *temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            NodeAddress *temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            if ((*root)->left->priority < (*root)->right->priority) {
                rotateRight(root);
                deleteNode(&(*root)->right, id);
            } else {
                rotateLeft(root);
                deleteNode(&(*root)->left, id);
            }
        }
    }
}

void deleteTreap(NodeAddress *root) {
  if (root != NULL) {
    deleteTreap(root->left);
    deleteTreap(root->right);
    free(root);
  }
}

void search(NodeAddress *root, int id) {
  if (root != NULL) {
    if (root->data.id == id) {
      printf("Customer found: %s %d %d\n", root->data.name, root->data.id, root->priority);
    } else if (id < root->data.id) {
      search(root->left, id);
    } else {
      search(root->right, id);
    }
  }
  else {
    printf("Customer not found\n");
  }
}

void searchName(NodeAddress *root, char name[]) {
  if (root != NULL) {
    if (strcmp(root->data.name, name) == 0) {
      printf("Customer found: %s %d %d\n", root->data.name, root->data.id, root->priority);
      } 
    else if (strcmp(name, root->data.name) < 0) {
        search(root->left, name);
        } 
    else {
        search(root->right, name);
        }
    }
    else {
        printf("Customer not found\n");
    }
}

void printTreap(NodeAddress *root) {
  if (root != NULL) {
    printTreap(root->left);
    printf("%s %d %d\n", root->data.name, root->data.id, root->priority);
    printTreap(root->right);
  }
}

// Function to print the customer records in an in-order traversal
int main(void) {
    Treap treap;
    treap.root = NULL;

  // Insert some customers into the treap
    insert(&treap, (Customer){"Aman", 123}, 1);
    insert(&treap, (Customer){"Bhumika", 456}, 2);
    insert(&treap, (Customer){"Chhavi", 789}, 3);
    insert(&treap, (Customer){"Krutika", 321}, 4);
    insert(&treap, (Customer){"Prakhar", 654}, 5);

  // Print the customer records in different orders
    printf("In-order traversal:\n");
    printTreap(treap.root);
    printf("\n");

    search(treap.root, 123);
    printf("\n");
    searchName(treap.root, "Prabal");

    printf("\n");
    deleteNode(&treap.root, 123);
    printf("In-order traversal after deleting Aman:\n");
    printTreap(treap.root);
    
    deleteTreap(treap.root);

  return 0;
}