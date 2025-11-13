#include <stdio.h>
#include <stdlib.h>
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0) e alguns navios (3)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Adicionando alguns navios (valor 3) para testes
    tabuleiro[2][2] = 3;
    tabuleiro[3][2] = 3;
    tabuleiro[4][4] = 3;
    tabuleiro[5][5] = 3;
}

// Função para exibir o tabuleiro com símbolos
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para criar matriz de habilidade em forma de cone
void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int meio = TAM_HABILIDADE / 2;
            habilidade[i][j] = (j >= meio - i && j <= meio + i) ? 1 : 0;
        }
    }
}

// Função para criar matriz de habilidade em forma de cruz
void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int meio = TAM_HABILIDADE / 2;
            habilidade[i][j] = (i == meio || j == meio) ? 1 : 0;
        }
    }
}

// Função para criar matriz de habilidade em forma de octaedro (losango)
void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int meio = TAM_HABILIDADE / 2;
            habilidade[i][j] = (abs(i - meio) + abs(j - meio) <= meio) ? 1 : 0;
        }
    }
}

// Função para aplicar a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                       int origem_linha, int origem_coluna) {
    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linha_tab = origem_linha - offset + i;
            int col_tab = origem_coluna - offset + j;

            // Verifica se está dentro dos limites do tabuleiro
            if (linha_tab >= 0 && linha_tab < TAM_TABULEIRO &&
                col_tab >= 0 && col_tab < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linha_tab][col_tab] == 0) {
                    tabuleiro[linha_tab][col_tab] = 5; // Marca como área afetada
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    printf("Tabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro);

    // Exemplo: aplicar Cone
    criarCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4); // centro do cone
    printf("Tabuleiro após habilidade Cone:\n");
    exibirTabuleiro(tabuleiro);

    // Exemplo: aplicar Cruz
    criarCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 7, 2); // centro da cruz
    printf("Tabuleiro após habilidade Cruz:\n");
    exibirTabuleiro(tabuleiro);

    // Exemplo: aplicar Octaedro
    criarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 2, 7); // centro do octaedro
    printf("Tabuleiro após habilidade Octaedro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}