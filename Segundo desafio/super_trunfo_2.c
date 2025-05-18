#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta Super Trunfo
typedef struct {
    char estado[3];              // Estado, ex: "SP"
    char codigo[4];              // Código da carta, ex: "A01"
    char nomeCidade[100];       // Nome da cidade, ex: "São Paulo"
    int populacao;              // Número de habitantes
    float area;                 // Área da cidade em km²
    float pib;                  // Produto Interno Bruto
    int pontosTuristicos;       // Número de pontos turísticos
    float densidadePopulacional;// Densidade populacional
    float pibPerCapita;         // PIB per capita
} Carta;

int main() {
    // Declaração de duas cartas
    Carta carta1, carta2;

    printf("=== Cadastro de Cartas Super Trunfo ===\n");

    // Entrada de dados da primeira carta
    printf("\n--- Carta 1 ---\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);

    printf("Código da Carta: ");
    scanf("%s", carta1.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("População: ");
    scanf("%d", &carta1.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Cálculo da densidade populacional e PIB per capita
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    // Entrada de dados da segunda carta
    printf("\n--- Carta 2 ---\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);

    printf("Código da Carta: ");
    scanf("%s", carta2.codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("População: ");
    scanf("%d", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculo da densidade populacional e PIB per capita
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // === Comparação ===
    // Troque a variável de comparação aqui (ex: populacao, area, pib, densidadePopulacional, pibPerCapita)
    char atributoUsado[50] = "Área";
    float valor1 = carta1.area;
    float valor2 = carta2.area;
    int menorVence = 0; // 1 se o menor valor vence (como para densidade)

    printf("\n=== Comparação de Cartas (Atributo: %s) ===\n", atributoUsado);
    printf("\nCarta 1 - %s (%s): %.2f", carta1.nomeCidade, carta1.estado, valor1);
    printf("\nCarta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, valor2);

    // Lógica de comparação
    if (menorVence) {
        if (valor1 < valor2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valor1 > valor2) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    } else {
        if (valor1 > valor2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valor1 < valor2) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }

    return 0;
}