#include <stdio.h>

// Função recursiva para o movimento da Torre
void moverTorre(int casas) {
    if (casas == 0) {
        return;
    }
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Função recursiva para o movimento da Rainha
void moverRainha(int casas) {
    if (casas == 0) {
        return;
    }
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// Função recursiva para o movimento do Bispo com loops aninhados
void moverBispo(int casas) {
    if (casas == 0) {
        return;
    }

    // Loop externo: movimento vertical
    for (int i = 0; i < 1; i++) {  // Apenas 1 movimento vertical por chamada
        printf("Cima ");
        
        // Loop interno: movimento horizontal
        for (int j = 0; j < 1; j++) {  // Apenas 1 movimento horizontal por chamada
            printf("Direita\n");
        }
    }
    
    moverBispo(casas - 1);
}

int main() {
    // Torre - recursiva
    printf("Movimento da Torre:\n");
    moverTorre(5);

    printf("\n");

    // Bispo - recursiva + loops aninhados
    printf("Movimento do Bispo:\n");
    moverBispo(5);

    printf("\n");

    // Rainha - recursiva
    printf("Movimento da Rainha:\n");
    moverRainha(8);

    printf("\n");

    // Movimento do Cavalo - loops aninhados, múltiplas variáveis e controle de fluxo
    printf("Movimento do Cavalo:\n");

    int movimentosVertical = 2;
    int movimentosHorizontal = 1;

    for (int i = 0; i < movimentosVertical + movimentosHorizontal; i++) {
        if (i < movimentosVertical) {
            for (int j = 0; j < 1; j++) {
                if (i == 1) {
                    printf("Cima\n");
                    continue;  
                }
                printf("Cima\n");
            }
        } else {
            for (int k = 0; k < 1; k++) {
                printf("Direita\n");
                break; 
            }
        }
    }

    return 0;
}