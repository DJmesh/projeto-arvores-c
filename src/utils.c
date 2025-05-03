#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bst.h"

#define MAX_LINE_LENGTH 512

void load_csv_to_bst(const char* filename, BSTNode** root) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo CSV");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char* track_name = strtok(line, ",");
        char* artist_name = strtok(NULL, "\n");

        if (track_name && artist_name) {
            *root = insert_bst(*root, track_name, artist_name);
        }
    }

    fclose(file);
}
