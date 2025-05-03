#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list_tree.h"
#include "bst.h"
#include "utils.h"

int main() {
    const char* csv_file = "../data/top_10000_musicas.csv";

    // **Árvore com Lista de Filhos**
    printf("Carregando dados na Árvore com Lista de Filhos...\n");
    ListTreeNode* list_tree_root = create_list_node("Músicas", "");

    clock_t start_time_list_tree = clock();
    load_csv_to_list_tree(csv_file, list_tree_root);
    clock_t end_time_list_tree = clock();
    double insertion_time_list_tree = (double)(end_time_list_tree - start_time_list_tree) / CLOCKS_PER_SEC;

    printf("\nTempo de processamento (inserção na Árvore com Lista de Filhos): %f segundos\n", insertion_time_list_tree);

    // Solicitar música para busca na Árvore com Lista de Filhos
    char search_track[100];
    printf("\nDigite o nome da música para buscar na Árvore com Lista de Filhos: ");
    fgets(search_track, sizeof(search_track), stdin);
    search_track[strcspn(search_track, "\n")] = '\0'; // Remover newline

    clock_t start_search_list_tree = clock();
    // Busca simulada (não implementada na estrutura atual)
    printf("Busca na Árvore com Lista de Filhos não implementada.\n");
    clock_t end_search_list_tree = clock();
    double search_time_list_tree = (double)(end_search_list_tree - start_search_list_tree) / CLOCKS_PER_SEC;

    free_list_tree(list_tree_root);

    // **Árvore Binária de Busca**
    printf("\nCarregando dados na Árvore Binária de Busca...\n");
    BSTNode* bst_root = NULL;

    clock_t start_time_bst = clock();
    FILE* file = fopen(csv_file, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo CSV");
        return 1;
    }

    char line[512];
    fgets(line, sizeof(line), file); // Ignorar cabeçalho
    while (fgets(line, sizeof(line), file)) {
        char* track_name = strtok(line, ",");
        char* artist_name = strtok(NULL, "\n");
        if (track_name && artist_name) {
            bst_root = insert_bst(bst_root, track_name, artist_name);
        }
    }
    fclose(file);
    clock_t end_time_bst = clock();
    double insertion_time_bst = (double)(end_time_bst - start_time_bst) / CLOCKS_PER_SEC;

    printf("\nTempo de processamento (inserção na Árvore Binária de Busca): %f segundos\n", insertion_time_bst);

    // Solicitar música para busca na Árvore Binária de Busca
    printf("\nDigite o nome da música para buscar na Árvore Binária de Busca: ");
    fgets(search_track, sizeof(search_track), stdin);
    search_track[strcspn(search_track, "\n")] = '\0'; // Remover newline

    clock_t start_search_bst = clock();
    BSTNode* found_node = search_bst(bst_root, search_track);
    clock_t end_search_bst = clock();
    double search_time_bst = (double)(end_search_bst - start_search_bst) / CLOCKS_PER_SEC;

    if (found_node) {
        printf("Música encontrada: %s - %s\n", found_node->track_name, found_node->artist_name);
    } else {
        printf("Música não encontrada.\n");
    }

    free_bst(bst_root);

    // **Comparação**
    printf("\n--- Comparação de Estruturas ---\n");
    printf("Tempo de inserção (Árvore com Lista de Filhos): %f segundos\n", insertion_time_list_tree);
    printf("Tempo de inserção (Árvore Binária de Busca): %f segundos\n", insertion_time_bst);
    printf("Tempo de busca (Árvore com Lista de Filhos): %f segundos\n", search_time_list_tree);
    printf("Tempo de busca (Árvore Binária de Busca): %f segundos\n", search_time_bst);

    if (insertion_time_list_tree < insertion_time_bst) {
        printf("A Árvore com Lista de Filhos foi mais rápida na inserção por %.6f segundos.\n", insertion_time_bst - insertion_time_list_tree);
    } else {
        printf("A Árvore Binária de Busca foi mais rápida na inserção por %.6f segundos.\n", insertion_time_list_tree - insertion_time_bst);
    }

    if (search_time_list_tree < search_time_bst) {
        printf("A Árvore com Lista de Filhos foi mais rápida na busca por %.6f segundos.\n", search_time_bst - search_time_list_tree);
    } else {
        printf("A Árvore Binária de Busca foi mais rápida na busca por %.6f segundos.\n", search_time_list_tree - search_time_bst);
    }

    return 0;
}