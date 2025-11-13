#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Programa: Mapa da Mansão - Árvore Binária
 * Objetivo: Simular a exploração de uma mansão representada como uma árvore binária.
 * Autor: Marcio Silveira
 *
 * Funcionalidades:
 *  - Cria automaticamente o mapa da mansão (árvore binária)
 *  - Permite exploração interativa a partir do Hall de Entrada
 *  - Jogador escolhe entre esquerda (e) ou direita (d)
 *  - A exploração termina ao chegar em um cômodo sem caminhos
 */

// Estrutura que representa uma sala (nó da árvore)
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// --- Protótipos das funções ---
Sala* criarSala(const char *nome);
void explorarSalas(Sala *atual);
void liberarArvore(Sala *raiz);

/*
 * Função principal: monta o mapa da mansão e inicia a exploração
 */
int main() {
    // Criação manual e estática da estrutura da mansão (árvore)
    Sala *hall = criarSala("Hall de Entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *cozinha = criarSala("Cozinha");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *jardim = criarSala("Jardim");
    Sala *porao = criarSala("Porao");
    Sala *suite = criarSala("Suite Principal");

    // Conectando os cômodos (estrutura da árvore)
    hall->esquerda = salaEstar;
    hall->direita = cozinha;

    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;

    cozinha->esquerda = porao;
    cozinha->direita = suite;

    // Início da exploração
    printf("=== EXPLORACAO DA MANSAO ===\n\n");
    explorarSalas(hall);

    // Libera memória após o término da exploração
    liberarArvore(hall);

    printf("\nExploracao encerrada. Obrigado por jogar!\n");
    return 0;
}

/*
 * Função: criarSala
 * Objetivo: Cria dinamicamente uma nova sala com o nome informado.
 */
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memoria para sala!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

/*
 * Função: explorarSalas
 * Objetivo: Permite que o jogador explore as salas interativamente.
 */
void explorarSalas(Sala *atual) {
    char escolha;

    if (atual == NULL)
        return;

    printf("Voce esta no: %s\n", atual->nome);

    // Caso seja uma sala sem saídas (folha)
    if (atual->esquerda == NULL && atual->direita == NULL) {
        printf("Nao ha mais caminhos a partir daqui. Fim da exploracao!\n");
        return;
    }

    printf("\nEscolha um caminho:\n");
    if (atual->esquerda != NULL) {
        printf(" (e) Ir para a esquerda -> %s\n", atual->esquerda->nome);
    }
    if (atual->direita != NULL) {
        printf(" (d) Ir para a direita -> %s\n", atual->direita->nome);
    }
    printf(" (s) Sair da exploracao\n");
    printf("Opcao: ");
    scanf(" %c", &escolha);

    switch (escolha) {
        case 'e':
        case 'E':
            explorarSalas(atual->esquerda);
            break;
        case 'd':
        case 'D':
            explorarSalas(atual->direita);
            break;
        case 's':
        case 'S':
            printf("Voce decidiu encerrar a exploracao.\n");
            return;
        default:
            printf("Opcao invalida! Tente novamente.\n");
            explorarSalas(atual); // Repete a escolha na mesma sala
    }
}

/*
 * Função: liberarArvore
 * Objetivo: Libera toda a memória alocada pela árvore recursivamente.
 */
void liberarArvore(Sala *raiz) {
    if (raiz == NULL)
        return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}
