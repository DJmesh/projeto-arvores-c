# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(projeto_arvores)

set(CMAKE_C_STANDARD 11)

# Diretórios de headers
include_directories(include)

# Executável principal para árvore binária
add_executable(arvore_binaria
        src/main.c
        src/bst.c
        src/utils.c
        src/list_tree.c  # Add this line
)
