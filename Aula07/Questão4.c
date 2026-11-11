/*
 * Aula 07 — Questão 4 — Celsius para Fahrenheit
 * Material da Profa. Joanacelle Caldas, página 26.
 *
 * Crie a função celsiusParaFahrenheit, que recebe uma temperatura em Celsius e
 * retorna o valor em Fahrenheit pela fórmula F = (9 × C) / 5 + 32. Na main,
 * solicite a temperatura e apresente o resultado com duas casas decimais.
 */

#include <stdio.h>

double celsiusParaFahrenheit(double celsius) {
    return celsius * (9.0 / 5.0) + 32.0;
}

int main(void) {
    double celsius;

    printf("Digite a temperatura em Celsius: ");
    if (scanf("%lf", &celsius) != 1) {
        puts("Temperatura invalida.");
        return 1;
    }

    printf("Temperatura em Fahrenheit: %.2f\n", celsiusParaFahrenheit(celsius));
    return 0;
}
