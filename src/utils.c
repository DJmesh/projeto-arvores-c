#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/list_tree.h"

#define MAX_LINE_LENGTH 512

void load_csv_to_list_tree(const char* filename, ListTreeNode* root) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo CSV");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file); // Ignorar cabeçalho

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char* track_name = strtok(line, ",");
        char* artist_name = strtok(NULL, "\n");

        if (track_name && artist_name) {
            ListTreeNode* node = create_list_node(track_name, artist_name);
            add_child(root, node);
        }
    }

    fclose(file);
}