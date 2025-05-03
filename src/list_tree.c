#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_tree.h"

ListTreeNode* create_list_node(const char* track_name, const char* artist_name) {
    ListTreeNode* node = (ListTreeNode*)malloc(sizeof(ListTreeNode));
    if (!node) {
        perror("Erro ao alocar nó da árvore em lista");
        exit(1);
    }
    strncpy(node->track_name, track_name, sizeof(node->track_name));
    strncpy(node->artist_name, artist_name, sizeof(node->artist_name));
    node->children = NULL;
    return node;
}

void add_child(ListTreeNode* parent, ListTreeNode* child) {
    ChildNode* new_child = (ChildNode*)malloc(sizeof(ChildNode));
    new_child->child = child;
    new_child->next = parent->children;
    parent->children = new_child;
}

void print_list_tree(ListTreeNode* root, int depth) {
    if (!root) return;
    for (int i = 0; i < depth; i++) printf("  ");
    printf("- %s (%s)\n", root->track_name, root->artist_name);

    ChildNode* current = root->children;
    while (current) {
        print_list_tree(current->child, depth + 1);
        current = current->next;
    }
}

void free_list_tree(ListTreeNode* root) {
    if (!root) return;

    ChildNode* current = root->children;
    while (current) {
        ChildNode* temp = current;
        free_list_tree(current->child);
        current = current->next;
        free(temp);
    }

    free(root);
}
