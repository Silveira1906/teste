#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Programa: Simulador de Fila de Peças Futuras do Tetris Stack
 * Objetivo: Simular o gerenciamento da fila de peças do jogo Tetris.
 * Autor: Marcio Silveira

 *
 * Funcionalidades:
 *  - Inicializa fila com 5 peças
 *  - Permite jogar (remover) uma peça da frente
 *  - Permite inserir (gerar) nova peça no final
 *  - Exibe o estado atual da fila após cada operação
 *
 * Conceitos aplicados:
 *  - Fila circular
 *  - Structs e arrays
 *  - Modularização e funções
 */

// Definição da struct Peça
typedef struct {
    char nome;  // Tipo da peça ('I', 'O', 'T', 'L')
    int id;     // Identificador único
} Peca;

// Constantes para o tamanho máximo da fila
#define TAM_MAX 5

// Estrutura da fila circular
typedef struct {
    Peca itens[TAM_MAX];
    int frente;
    int tras;
    int tamanho;
} Fila;

// Protótipos das funções
void inicializarFila(Fila *fila);
int filaCheia(Fila *fila);
int filaVazia(Fila *fila);
void enfileirar(Fila *fila, Peca novaPeca);
void desenfileirar(Fila *fila);
void exibirFila(Fila *fila);
Peca gerarPeca();

// Variável global para controlar IDs únicos
int contadorID = 0;

/* 
 * Função principal - controla o menu de ações
 */
int main() {
    Fila fila;
    int opcao;
    srand(time(NULL)); // Semente para geração aleatória de peças

    inicializarFila(&fila);

    // Inicializa a fila com 5 peças
    for (int i = 0; i < TAM_MAX; i++) {
        enfileirar(&fila, gerarPeca());
    }

    do {
        printf("\n=== FILA DE PECAS FUTURAS - TETRIS STACK ===\n");
        exibirFila(&fila);
        printf("\nOpcoes de acao:\n");
        printf("1 - Jogar peca (dequeue)\n");
        printf("2 - Inserir nova peca (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                desenfileirar(&fila);
                break;
            case 2:
                enfileirar(&fila, gerarPeca());
                break;
            case 0:
                printf("Encerrando o simulador...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

/*
 * Função: inicializarFila
 * Objetivo: Configura a fila vazia no início do programa.
 */
void inicializarFila(Fila *fila) {
    fila->frente = 0;
    fila->tras = -1;
    fila->tamanho = 0;
}

/*
 * Função: filaCheia
 * Objetivo: Retorna 1 se a fila estiver cheia, caso contrário 0.
 */
int filaCheia(Fila *fila) {
    return fila->tamanho == TAM_MAX;
}

/*
 * Função: filaVazia
 * Objetivo: Retorna 1 se a fila estiver vazia, caso contrário 0.
 */
int filaVazia(Fila *fila) {
    return fila->tamanho == 0;
}

/*
 * Função: gerarPeca
 * Objetivo: Gera uma nova peça aleatória do tipo I, O, T ou L.
 */
Peca gerarPeca() {
    Peca nova;
    char tipos[] = {'I', 'O', 'T', 'L'};
    nova.nome = tipos[rand() % 4]; // Escolhe tipo aleatório
    nova.id = contadorID++;        // ID único
    return nova;
}

/*
 * Função: enfileirar
 * Objetivo: Insere uma nova peça no final da fila (enqueue).
 */
void enfileirar(Fila *fila, Peca novaPeca) {
    if (filaCheia(fila)) {
        printf("\nA fila esta cheia! Nao e possivel adicionar nova peca.\n");
        return;
    }
    fila->tras = (fila->tras + 1) % TAM_MAX;
    fila->itens[fila->tras] = novaPeca;
    fila->tamanho++;
    printf("\nPeca [%c %d] adicionada ao final da fila!\n", novaPeca.nome, novaPeca.id);
}

/*
 * Função: desenfileirar
 * Objetivo: Remove a peça da frente da fila (dequeue).
 */
void desenfileirar(Fila *fila) {
    if (filaVazia(fila)) {
        printf("\nA fila esta vazia! Nenhuma peca para jogar.\n");
        return;
    }
    Peca removida = fila->itens[fila->frente];
    fila->frente = (fila->frente + 1) % TAM_MAX;
    fila->tamanho--;
    printf("\nPeca [%c %d] jogada (removida da fila)!\n", removida.nome, removida.id);
}

/*
 * Função: exibirFila
 * Objetivo: Mostra todas as peças da fila com nome e ID.
 */
void exibirFila(Fila *fila) {
    printf("\n=== FILA DE PECAS ===\n");

    if (filaVazia(fila)) {
        printf("[Fila vazia]\n");
        return;
    }

    int i, indice;
    for (i = 0; i < fila->tamanho; i++) {
        indice = (fila->frente + i) % TAM_MAX;
        printf("[%c %d] ", fila->itens[indice].nome, fila->itens[indice].id);
    }
    printf("\n");
}