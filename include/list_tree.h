#ifndef LIST_TREE_H
#define LIST_TREE_H



// Estrutura do nó da lista de filhos
typedef struct ChildNode {
    struct ListTreeNode* child;
    struct ChildNode* next;
} ChildNode;

// Estrutura do nó da árvore com lista de filhos
typedef struct ListTreeNode {
    char track_name[100];
    char artist_name[100];
    ChildNode* children;
} ListTreeNode;

// Funções públicas do TAD
ListTreeNode* create_list_node(const char* track_name, const char* artist_name);
void add_child(ListTreeNode* parent, ListTreeNode* child);
void print_list_tree(ListTreeNode* root, int depth);
void free_list_tree(ListTreeNode* root);

#endif // LIST_TREE_H
