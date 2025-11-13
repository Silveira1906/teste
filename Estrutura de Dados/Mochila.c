#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Programa: Sistema de Inventário de Mochila
 * Objetivo: Simular a mochila de loot inicial de um jogador.
 * Autor: [Marcio Silveira]
 *
 * Funcionalidades:
 *  - Cadastrar até 10 itens
 *  - Remover item pelo nome
 *  - Listar todos os itens
 *  - Buscar item pelo nome (busca sequencial)
 */

// Definição da struct Item
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// Funções do sistema
void inserirItem(struct Item mochila[], int *qtd);
void removerItem(struct Item mochila[], int *qtd);
void listarItens(struct Item mochila[], int qtd);
void buscarItem(struct Item mochila[], int qtd);

int main() {
    struct Item mochila[10]; // Vetor que armazena até 10 itens
    int qtd = 0;             // Quantidade atual de itens na mochila
    int opcao;

    do {
        printf("\n=== SISTEMA DE INVENTARIO ===\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                inserirItem(mochila, &qtd);
                listarItens(mochila, qtd);
                break;
            case 2:
                removerItem(mochila, &qtd);
                listarItens(mochila, qtd);
                break;
            case 3:
                listarItens(mochila, qtd);
                break;
            case 4:
                buscarItem(mochila, qtd);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

/* 
 * Função: inserirItem
 * Objetivo: Cadastrar um novo item na mochila.
 */
void inserirItem(struct Item mochila[], int *qtd) {
    if (*qtd >= 10) {
        printf("A mochila esta cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    printf("\n--- Cadastro de Item ---\n");

    printf("Nome do item: ");
    fgets(mochila[*qtd].nome, 30, stdin);
    mochila[*qtd].nome[strcspn(mochila[*qtd].nome, "\n")] = '\0'; // Remove '\n'

    printf("Tipo do item (ex: arma, municao, cura): ");
    fgets(mochila[*qtd].tipo, 20, stdin);
    mochila[*qtd].tipo[strcspn(mochila[*qtd].tipo, "\n")] = '\0'; // Remove '\n'

    printf("Quantidade: ");
    scanf("%d", &mochila[*qtd].quantidade);
    getchar(); // Limpa o buffer

    (*qtd)++;
    printf("Item cadastrado com sucesso!\n");
}

/* 
 * Função: removerItem
 * Objetivo: Remover um item da mochila com base no nome.
 */
void removerItem(struct Item mochila[], int *qtd) {
    if (*qtd == 0) {
        printf("A mochila esta vazia! Nao ha itens para remover.\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item a ser removido: ");
    fgets(nomeRemover, 30, stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    int i, encontrado = 0;
    for (i = 0; i < *qtd; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = 1;
            // Desloca os itens seguintes para "fechar o buraco"
            for (int j = i; j < *qtd - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*qtd)--;
            printf("Item '%s' removido com sucesso!\n", nomeRemover);
            break;
        }
    }

    if (!encontrado)
        printf("Item nao encontrado!\n");
}

/* 
 * Função: listarItens
 * Objetivo: Exibir todos os itens cadastrados.
 */
void listarItens(struct Item mochila[], int qtd) {
    printf("\n=== ITENS NA MOCHILA ===\n");

    if (qtd == 0) {
        printf("Nenhum item cadastrado.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

/* 
 * Função: buscarItem
 * Objetivo: Realizar busca sequencial por um item com base no nome.
 */
void buscarItem(struct Item mochila[], int qtd) {
    if (qtd == 0) {
        printf("A mochila esta vazia!\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < qtd; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\nTipo: %s\nQuantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
        printf("Item nao encontrado na mochila.\n");
}