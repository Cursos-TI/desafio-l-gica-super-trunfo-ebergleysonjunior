#include <stdio.h>
#include <string.h>

int main() {
    struct Carta {
        char nome[50];
        int populacao;
        float area;
        float pib;
        int pontos_turisticos;
        float densidade_demografica;
    };

    struct Carta carta1, carta2;
    int opcao1, opcao2;

    printf("=== Cadastro da Carta 1 ===\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", carta1.nome);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);
    carta1.densidade_demografica = carta1.populacao / carta1.area;

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", carta2.nome);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);
    carta2.densidade_demografica = carta2.populacao / carta2.area;

    // MENU 1: Escolher o primeiro atributo
    printf("\n=== Escolha o PRIMEIRO atributo para comparar ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    // MENU 2: Escolher o segundo atributo (sem repetir)
    printf("\n=== Escolha o SEGUNDO atributo para comparar ===\n");
    for (int i = 1; i <= 5; i++) {
        if (i == opcao1) continue; // não mostra o já escolhido
        switch (i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Pontos Turísticos\n"); break;
            case 5: printf("5 - Densidade Demográfica\n"); break;
        }
    }
    printf("Opção: ");
    scanf("%d", &opcao2);

    // Variáveis para armazenar os valores e soma
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;
    float soma_c1 = 0, soma_c2 = 0;

    // Função de comparação para o primeiro atributo
    switch (opcao1) {
        case 1:
            valor1_c1 = carta1.populacao;
            valor1_c2 = carta2.populacao;
            break;
        case 2:
            valor1_c1 = carta1.area;
            valor1_c2 = carta2.area;
            break;
        case 3:
            valor1_c1 = carta1.pib;
            valor1_c2 = carta2.pib;
            break;
        case 4:
            valor1_c1 = carta1.pontos_turisticos;
            valor1_c2 = carta2.pontos_turisticos;
            break;
        case 5:
            // Densidade: menor valor vence
            valor1_c1 = carta1.densidade_demografica;
            valor1_c2 = carta2.densidade_demografica;
            break;
    }

    // Função de comparação para o segundo atributo
    switch (opcao2) {
        case 1:
            valor2_c1 = carta1.populacao;
            valor2_c2 = carta2.populacao;
            break;
        case 2:
            valor2_c1 = carta1.area;
            valor2_c2 = carta2.area;
            break;
        case 3:
            valor2_c1 = carta1.pib;
            valor2_c2 = carta2.pib;
            break;
        case 4:
            valor2_c1 = carta1.pontos_turisticos;
            valor2_c2 = carta2.pontos_turisticos;
            break;
        case 5:
            valor2_c1 = carta1.densidade_demografica;
            valor2_c2 = carta2.densidade_demografica;
            break;
    }

    // Regra especial: se for densidade demográfica, inverte o sentido da "vantagem"
    float resultado1 = (opcao1 == 5) ? (valor1_c1 < valor1_c2) : (valor1_c1 > valor1_c2);
    float resultado2 = (opcao2 == 5) ? (valor2_c1 < valor2_c2) : (valor2_c1 > valor2_c2);

    // Soma dos atributos
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    // Exibição dos resultados
    printf("\n=== Resultado da Comparação ===\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    printf("Atributo 1 (%d): %.2f x %.2f -> %s vence\n", opcao1, valor1_c1, valor1_c2,
           resultado1 ? carta1.nome : carta2.nome);
    printf("Atributo 2 (%d): %.2f x %.2f -> %s vence\n", opcao2, valor2_c1, valor2_c2,
           resultado2 ? carta1.nome : carta2.nome);

    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma_c1);
    printf("%s: %.2f\n", carta2.nome, soma_c2);

    // Resultado final com operador ternário
    printf("\nResultado Final: ");
    if (soma_c1 == soma_c2)
        printf("Empate!\n");
    else
        printf("Vencedora: %s\n", (soma_c1 > soma_c2) ? carta1.nome : carta2.nome);

    return 0;
}
