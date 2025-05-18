#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Carta;

// Função para ler os dados de uma carta
void lerCarta(Carta *carta) {
    printf("Informe o estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Informe o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("Informe a população: ");
    scanf("%d", &carta->populacao);

    printf("Informe a área (km²): ");
    scanf("%f", &carta->area);

    printf("Informe o PIB: ");
    scanf("%f", &carta->pib);

    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontosTuristicos
                        + carta->pibPerCapita + (1 / carta->densidadePopulacional);
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);

    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    carta.densidadePopulacional = carta.populacao / carta.area;
    printf("PIB per Capita: %.2f\n", carta.pibPerCapita);
    carta.pibPerCapita = carta.pib / carta.populacao;
    printf("Super Poder: %.2f\n", carta.superPoder);
}

// Função para comparar dois atributos
int compararMaior(float valor1, float valor2) {
    return valor1 > valor2 ? 1 : 0;
}

int compararMenor(float valor1, float valor2) {
    return valor1 < valor2 ? 1 : 0;
}

int main() {
    Carta carta1, carta2;

    printf("Digite os dados da Carta 1:\n");
    lerCarta(&carta1);

    printf("\nDigite os dados da Carta 2:\n");
    lerCarta(&carta2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Comparações
    printf("\nComparação de Cartas:\n\n");

    printf("População: Carta venceu (%d)\n", compararMaior(carta1.populacao, carta2.populacao));
    printf("Área: Carta venceu (%d)\n", compararMaior(carta1.area, carta2.area));
    printf("PIB: Carta venceu (%d)\n", compararMaior(carta1.pib, carta2.pib));
    printf("Pontos Turísticos: Carta venceu (%d)\n", compararMaior(carta1.pontosTuristicos, carta2.pontosTuristicos));
    printf("Densidade Populacional: Carta venceu (%d)\n", compararMenor(carta1.densidadePopulacional, carta2.densidadePopulacional));
    printf("PIB per Capita: Carta venceu (%d)\n", compararMaior(carta1.pibPerCapita, carta2.pibPerCapita));
    printf("Super Poder: Carta venceu (%d)\n", compararMaior(carta1.superPoder, carta2.superPoder));

    return 0;
}