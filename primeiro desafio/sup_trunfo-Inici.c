#include <stdio.h>
#include <string.h>

#define NUM_CARTAS 2


typedef struct {
    char estado;                
    char codigoCarta[4];        
    char nomeCidade[100];       
    int populacao;              
    float area;               
    float pib;                
    int pontosTuristicos;   
    
} CartaSuperTrunfo;

void lerCarta(CartaSuperTrunfo *carta, int numero) {
    printf("Digite os dados da carta %d:\n", numero + 1);

    printf("Estado (letra de A a H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%3s", carta->codigoCarta);

    printf("Nome da Cidade: ");
    getchar();
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);

    size_t len = strlen(carta->nomeCidade);
    if (len > 0 && carta->nomeCidade[len - 1] == '\n') {
        carta->nomeCidade[len - 1] = '\0';
    }

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB: ");
    scanf("%f", &carta->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    printf("\n");
}

void exibirCarta(CartaSuperTrunfo carta, int numero) {
    printf("=== Carta %d ===\n", numero + 1);
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigoCarta);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
      
    printf("\n");
}

int main() {
    CartaSuperTrunfo cartas[NUM_CARTAS];

    // Leitura dos dados
    for (int i = 0; i < NUM_CARTAS; i++) {
        lerCarta(&cartas[i], i);
    }

    // Exibição dos dados
    printf("=== Cartas Cadastradas ===\n\n");
    for (int i = 0; i < NUM_CARTAS; i++) {
        exibirCarta(cartas[i], i);
    }

    return 0;
}