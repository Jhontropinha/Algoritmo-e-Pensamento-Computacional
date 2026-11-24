/*
 * Aula 07 - Funcoes
 * Questao 10 - Analise das vendas de cinco dias.
 *
 * O vetor e passado para as funcoes como parametro (float vendas[]),
 * sem uso de ponteiros explicitos.
 */
#include <stdio.h>

#define DIAS 5

float calcularTotal(float vendas[], int quantidade) {
    int i;
    float total = 0;

    for (i = 0; i < quantidade; i++) {
        total = total + vendas[i];
    }
    return total;
}

float calcularMedia(float total, int quantidadeDias) {
    return total / quantidadeDias;
}

int contarVendasAcimaDaMedia(float vendas[], int quantidade, float media) {
    int i, contador = 0;

    for (i = 0; i < quantidade; i++) {
        if (vendas[i] > media) {
            contador++;
        }
    }
    return contador;
}

int main() {
    float vendas[DIAS];
    float total, media;
    int i, diasAcima;

    for (i = 0; i < DIAS; i++) {
        printf("Valor das vendas do dia %d: R$ ", i + 1);
        scanf("%f", &vendas[i]);
    }

    total = calcularTotal(vendas, DIAS);
    media = calcularMedia(total, DIAS);
    diasAcima = contarVendasAcimaDaMedia(vendas, DIAS, media);

    printf("\n===== RESULTADO DAS VENDAS =====\n");
    printf("Total vendido: R$ %.2f\n", total);
    printf("Media diaria: R$ %.2f\n", media);
    printf("Dias com vendas acima da media: %d\n", diasAcima);

    return 0;
}
