/*
 * Aula 07 — Questão 10 — Vendas de cinco dias
 * Material da Profa. Joanacelle Caldas, página 27.
 *
 * Leia os valores das vendas de cinco dias. Implemente calcularTotal para
 * receber os valores e retornar a soma, calcularMedia para receber o total e a
 * quantidade de dias e retornar a média diária, e contarVendasAcimaDaMedia
 * para receber os valores e a média e contar os dias com vendas acima dela. Ao
 * final, apresente o total vendido, a média diária e a quantidade de dias
 * acima da média.
 */

#include <stdio.h>

double calcularTotal(const double vendas[], int dias) {
    double total = 0;
    for (int i = 0; i < dias; i++) {
        total += vendas[i];
    }
    return total;
}

double calcularMedia(double total, int dias) {
    return total / dias;
}

int contarVendasAcimaDaMedia(const double vendas[], int dias, double media) {
    int acima = 0;
    for (int i = 0; i < dias; i++) {
        if (vendas[i] > media) {
            acima++;
        }
    }
    return acima;
}

int main(void) {
    enum { DIAS = 5 };
    double vendas[DIAS];

    for (int i = 0; i < DIAS; i++) {
        printf("Digite o valor das vendas do dia %d: ", i + 1);
        if (scanf("%lf", &vendas[i]) != 1) {
            puts("Valor invalido.");
            return 1;
        }
    }

    double total = calcularTotal(vendas, DIAS);
    double media = calcularMedia(total, DIAS);
    int acima = contarVendasAcimaDaMedia(vendas, DIAS, media);

    printf("\nTotal vendido: %.2f\n", total);
    printf("Media diaria: %.2f\n", media);
    printf("Dias acima da media: %d\n", acima);
    return 0;
}
