#include <stdio.h>
#include <string.h>

// Estrutura representando uma carta de país
typedef struct {
    char nomePais[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica; // populacao / area
} Carta;

// Função para comparar e exibir resultados
void compararCartas(Carta c1, Carta c2, int opcao) {
    printf("\n--- Comparação ---\n");
    printf("País 1: %s\n", c1.nomePais);
    printf("País 2: %s\n", c2.nomePais);
    
    switch (opcao) {
        case 1:
            printf("Comparação por População\n");
            printf("%s: %d habitantes\n", c1.nomePais, c1.populacao);
            printf("%s: %d habitantes\n", c2.nomePais, c2.populacao);
            if (c1.populacao > c2.populacao)
                printf("Vencedor: %s\n", c1.nomePais);
            else if (c2.populacao > c1.populacao)
                printf("Vencedor: %s\n", c2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Comparação por Área\n");
            printf("%s: %.2f km²\n", c1.nomePais, c1.area);
            printf("%s: %.2f km²\n", c2.nomePais, c2.area);
            if (c1.area > c2.area)
                printf("Vencedor: %s\n", c1.nomePais);
            else if (c2.area > c1.area)
                printf("Vencedor: %s\n", c2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("Comparação por PIB\n");
            printf("%s: %.2f\n", c1.nomePais, c1.pib);
            printf("%s: %.2f\n", c2.nomePais, c2.pib);
            if (c1.pib > c2.pib)
                printf("Vencedor: %s\n", c1.nomePais);
            else if (c2.pib > c1.pib)
                printf("Vencedor: %s\n", c2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Comparação por Pontos Turísticos\n");
            printf("%s: %d pontos\n", c1.nomePais, c1.pontosTuristicos);
            printf("%s: %d pontos\n", c2.nomePais, c2.pontosTuristicos);
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedor: %s\n", c1.nomePais);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Vencedor: %s\n", c2.nomePais);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Comparação por Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", c1.nomePais, c1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", c2.nomePais, c2.densidadeDemografica);
            if (c1.densidadeDemografica < c2.densidadeDemografica)
                printf("Vencedor: %s (menor densidade)\n", c1.nomePais);
            else if (c2.densidadeDemografica < c1.densidadeDemografica)
                printf("Vencedor: %s (menor densidade)\n", c2.nomePais);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
    }
}

int main() {
    // Cartas fixas (ou previamente cadastradas)
    Carta carta1 = {"Brasil", 214000000, 8515767.0, 2200000.0, 12, 214000000 / 8515767.0};
    Carta carta2 = {"Argentina", 46000000, 2780000.0, 3500000.0, 8, 46000000 / 2780000.0};

    int escolha;

    do {
        printf("\n===== MENU DE COMPARAÇÃO =====\n");
        printf("1 - Comparar População\n");
        printf("2 - Comparar Área\n");
        printf("3 - Comparar PIB\n");
        printf("4 - Comparar Pontos Turísticos\n");
        printf("5 - Comparar Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        if (escolha != 0) {
            compararCartas(carta1, carta2, escolha);
        }

    } while (escolha != 0);

    printf("Programa encerrado.\n");
    return 0;
}