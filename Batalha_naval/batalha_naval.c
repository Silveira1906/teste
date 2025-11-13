#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 10
#define TAM_NAVIO 3

// Função para verificar se as posições do navio são válidas
bool posicaoValida(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, bool horizontal) {
    // Verifica se o navio cabe no tabuleiro
    if (horizontal) {
        if (coluna + TAM_NAVIO - 1 >= TAMANHO) return false;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return false; // Sobreposição
        }
    } else {
        if (linha + TAM_NAVIO - 1 >= TAMANHO) return false;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return false; // Sobreposição
        }
    }
    return true;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, bool horizontal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (horizontal) {
            tabuleiro[linha][coluna + i] = 3;
        } else {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];

    // Inicializa o tabuleiro com zeros (água)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas do primeiro navio (horizontal)
    int linhaNavio1 = 2; // exemplo
    int colunaNavio1 = 3; // exemplo

    // Coordenadas do segundo navio (vertical)
    int linhaNavio2 = 5; // exemplo
    int colunaNavio2 = 7; // exemplo

    // Posiciona o primeiro navio (horizontal)
    if (posicaoValida(tabuleiro, linhaNavio1, colunaNavio1, true)) {
        posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, true);
    } else {
        printf("Posição inválida para o navio horizontal.\n");
        return 1;
    }

    // Posiciona o segundo navio (vertical)
    if (posicaoValida(tabuleiro, linhaNavio2, colunaNavio2, false)) {
        posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, false);
    } else {
        printf("Posição inválida para o navio vertical.\n");
        return 1;
    }

    // Exibe o tabuleiro
    printf("Tabuleiro do Batalha Naval:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}