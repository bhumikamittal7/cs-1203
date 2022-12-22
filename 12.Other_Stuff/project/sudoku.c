//sudoku checker using hash table 
//given a sudoku board, check if it is valid 
//a valid sudoku board is one that has no duplicate numbers in each row, column, and 3x3 sub-boxes
//the board is represented by a 2D array of size 9x9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9

//hash table node
typedef struct node{
    int key;
    struct node *next;
}node;

//hash table
typedef struct hash_table{
    int size;
    node **table;
}hash_table;

//create a new hash table
hash_table *create_hash_table(int size){
    hash_table *new_hash_table = malloc(sizeof(hash_table));
    new_hash_table->size = size;
    new_hash_table->table = malloc(sizeof(node*) * size);
    for(int i = 0; i < size; i++){
        new_hash_table->table[i] = NULL;
    }
    return new_hash_table;
}

//create a new node
node *create_node(int key){
    node *new_node = malloc(sizeof(node));
    new_node->key = key;
    new_node->next = NULL;
    return new_node;
}

//hash function
int hash(hash_table *hash_table, int key){
    return key % hash_table->size;
}

//insert a node into the hash table
void insert(hash_table *hash_table, int key){
    int index = hash(hash_table, key);
    node *new_node = create_node(key);
    new_node->next = hash_table->table[index];
    hash_table->table[index] = new_node;
}

//search for a node in the hash table
int search(hash_table *hash_table, int key){
    int index = hash(hash_table, key);
    node *current = hash_table->table[index];
    while(current != NULL){
        if(current->key == key){
            return 1;
        }
        current = current->next;
    }
    return 0;
}

//delete a node from the hash table
void delete(hash_table *hash_table, int key){
    int index = hash(hash_table, key);
    node *current = hash_table->table[index];
    node *previous = NULL;
    while(current != NULL){
        if(current->key == key){
            if(previous == NULL){
                hash_table->table[index] = current->next;
            }else{
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

//free the hash table
void free_hash_table(hash_table *hash_table){
    for(int i = 0; i < hash_table->size; i++){
        node *current = hash_table->table[i];
        while(current != NULL){
            node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hash_table->table);
    free(hash_table);
}

//check if the sudoku board is valid 
void main(){
    int board[MAX][MAX] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };
    hash_table *hash_table = create_hash_table(MAX);
    int valid = 1;
    //check rows
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(search(hash_table, board[i][j])){
                valid = 0;
                break;
            }
            insert(hash_table, board[i][j]);
        }
        if(!valid){
            break;
        }
        free_hash_table(hash_table);
        hash_table = create_hash_table(MAX);
    }
    //check columns
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(search(hash_table, board[j][i])){
                valid = 0;
                break;
            }
            insert(hash_table, board[j][i]);
        }
        if(!valid){
            break;
        }
        free_hash_table(hash_table);
        hash_table = create_hash_table(MAX);
    }
    //check sub-boxes
    for(int i = 0; i < MAX; i += 3){

    }