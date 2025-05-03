#ifndef UTILS_H
#define UTILS_H

#include "list_tree.h"

// Função para carregar músicas e artistas do CSV para a árvore
void load_csv_to_list_tree(const char* filename, ListTreeNode* root);

#endif // UTILS_H