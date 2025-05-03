// main_list.c - Teste da Árvore com Lista de Filhos
#include <stdio.h>
#include <stdlib.h>
#include "../include/list_tree.h"

int main() {
    // Raiz representa a categoria principal: "Músicas"
    ListTreeNode* root = create_list_node("Músicas", "");

    ListTreeNode* rock = create_list_node("Rock", "");
    ListTreeNode* pop = create_list_node("Pop", "");

    add_child(root, rock);
    add_child(root, pop);

    add_child(rock, create_list_node("Bohemian Rhapsody", "Queen"));
    add_child(rock, create_list_node("Back in Black", "AC/DC"));

    add_child(pop, create_list_node("Let it Be", "The Beatles"));
    add_child(pop, create_list_node("Shape of You", "Ed Sheeran"));

    printf("\nEstrutura da árvore com listas:\n");
    print_list_tree(root, 0);

    free_list_tree(root);
    return 0;
}
