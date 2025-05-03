#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bst.h"

BSTNode* create_node(const char* track_name, const char* artist_name) {
    BSTNode* new_node = (BSTNode*)malloc(sizeof(BSTNode));
    if (new_node == NULL) {
        perror("Erro ao alocar memória para o nó");
        exit(1);
    }
    strncpy(new_node->track_name, track_name, sizeof(new_node->track_name));
    strncpy(new_node->artist_name, artist_name, sizeof(new_node->artist_name));
    new_node->left = new_node->right = NULL;
    return new_node;
}

BSTNode* insert_bst(BSTNode* root, const char* track_name, const char* artist_name) {
    if (root == NULL) {
        return create_node(track_name, artist_name);
    }
    int cmp = strcmp(track_name, root->track_name);
    if (cmp < 0) {
        root->left = insert_bst(root->left, track_name, artist_name);
    } else if (cmp > 0) {
        root->right = insert_bst(root->right, track_name, artist_name);
    } else {
        // Música já existe, pode ignorar ou atualizar artista
    }
    return root;
}

BSTNode* search_bst(BSTNode* root, const char* track_name) {
    if (root == NULL) return NULL;
    int cmp = strcmp(track_name, root->track_name);
    if (cmp == 0) return root;
    else if (cmp < 0) return search_bst(root->left, track_name);
    else return search_bst(root->right, track_name);
}

void inorder_traversal(BSTNode* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%s - %s\n", root->track_name, root->artist_name);
        inorder_traversal(root->right);
    }
}

void free_bst(BSTNode* root) {
    if (root != NULL) {
        free_bst(root->left);
        free_bst(root->right);
        free(root);
    }
}
