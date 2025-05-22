#include <stdio.h>

int main() {
    // Movimento da Torre - 5 casas para a direita (usando for)
    int i;
    printf("Movimento da Torre:\n");
    for(i = 1; i <= 5; i++) {
        printf("Direita\n");
    }

    printf("\n");

    // Movimento do Bispo - 5 casas na diagonal para cima e à direita (usando while)
    int j = 1;
    printf("Movimento do Bispo:\n");
    while(j <= 5) {
        printf("Cima Direita\n");
        j++;
    }

    printf("\n");

    // Movimento da Rainha - 8 casas para a esquerda (usando do-while)
    int k = 1;
    printf("Movimento da Rainha:\n");
    do {
        printf("Esquerda\n");
        k++;
    } while(k <= 8);

    printf("\n");

    // Movimento do Cavalo - 2 casas para baixo e 1 casa para a esquerda
    printf("Movimento do Cavalo:\n");

    // Primeiro loop: 2 casas para baixo (usando for)
    for(int m = 1; m <= 2; m++) {
        printf("Baixo\n");

        // Segundo loop: após cada movimento para baixo, verificamos se já chegamos ao fim
        if(m == 2) {
            int n = 0;
            while(n < 1) {  // apenas 1 movimento para a esquerda
                printf("Esquerda\n");
                n++;
            }
        }
    }

    return 0;
}