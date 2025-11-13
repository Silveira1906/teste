#include <stdio.h>
#include <string.h>

/*
 * Programa: Cadastro de Territórios
 * Objetivo: Criar uma base de dados com 5 territórios,
 *            armazenando nome, cor do exército e número de tropas.
 * Autor: [Seu Nome]
 * Data: [Data atual]
 */

// Definição da struct Territorio
// Cada território terá nome, cor do exército e quantidade de tropas
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    struct Territorio territorios[5]; // Vetor para armazenar 5 territórios
    int i;

    printf("=== CADASTRO DE TERRITORIOS ===\n\n");

    // Laço para entrada de dados dos 5 territórios
    for (i = 0; i < 5; i++) {
        printf("Cadastro do territorio %d:\n", i + 1);

        // Leitura do nome do território
        printf("Digite o nome do territorio: ");
        scanf(" %29[^\n]", territorios[i].nome); // lê até 29 caracteres ou nova linha

        // Leitura da cor do exército
        printf("Digite a cor do exercito: ");
        scanf(" %9s", territorios[i].cor); // lê até 9 caracteres (sem espaços)

        // Leitura da quantidade de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n"); // Linha em branco para separar cadastros
    }

    // Exibição dos dados cadastrados
    printf("\n=== DADOS DOS TERRITORIOS CADASTRADOS ===\n\n");
    for (i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exercito: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
        printf("-------------------------------------\n");
    }

    return 0;
}
