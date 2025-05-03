#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list_tree.h"
#include "bst.h"
#include "utils.h"

int main() {
    // **arvore com Lista de Filhos**
    printf("Carregando dados na arvore com Lista de Filhos...\n");
    ListTreeNode* list_tree_root = create_list_node("Músicas", "");

    clock_t start_time_list_tree = clock();
    load_csv_to_list_tree("../data/top_500_musicas.csv", list_tree_root);
    clock_t end_time_list_tree = clock();
    double processing_time_list_tree = (double)(end_time_list_tree - start_time_list_tree) / CLOCKS_PER_SEC;

    printf("\nEstrutura da arvore com Lista de Filhos:\n");
    //print_list_tree(list_tree_root, 0);
    printf("\nTempo de processamento (arvore com Lista de Filhos): %f segundos\n", processing_time_list_tree);

    free_list_tree(list_tree_root);

    // **arvore Binaria de Busca**
    printf("\nCarregando dados na arvore Binaria de Busca...\n");
    BSTNode* bst_root = NULL;

    clock_t start_time_bst = clock();
    FILE* file = fopen("../data/top_500_musicas.csv", "r");
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
    double processing_time_bst = (double)(end_time_bst - start_time_bst) / CLOCKS_PER_SEC;

    printf("\nEstrutura da arvore Binaria de Busca (em ordem):\n");
    //inorder_traversal(bst_root);
    printf("\nTempo de processamento (arvore Binaria de Busca): %f segundos\n", processing_time_bst);

    free_bst(bst_root);

    // **Comparação**
    printf("\n--- Comparação de Estruturas ---\n");
    if (processing_time_list_tree < processing_time_bst) {
        printf("A arvore com Lista de Filhos foi mais rapida por %.6f segundos.\n", processing_time_bst - processing_time_list_tree);
    } else if (processing_time_bst < processing_time_list_tree) {
        printf("A arvore Binaria de Busca foi mais rapida por %.6f segundos.\n", processing_time_list_tree - processing_time_bst);
    } else {
        printf("Ambas as estruturas tiveram tempos de processamento iguais.\n");
    }

    return 0;
}