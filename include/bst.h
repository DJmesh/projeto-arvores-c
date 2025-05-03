#ifndef BST_H
#define BST_H

#include <stdbool.h>

// Estrutura de um nó da árvore
typedef struct BSTNode {
    char track_name[100];
    char artist_name[100];
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Funções públicas do TAD
BSTNode* create_node(const char* track_name, const char* artist_name);
BSTNode* insert_bst(BSTNode* root, const char* track_name, const char* artist_name);
BSTNode* search_bst(BSTNode* root, const char* track_name);
void inorder_traversal(BSTNode* root);
void free_bst(BSTNode* root);

#endif // BST_H
