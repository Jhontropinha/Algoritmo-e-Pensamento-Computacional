/*
 * Aula 07 - Funcoes
 * Questao 04 - Conversao de Celsius para Fahrenheit: F = (9 x C) / 5 + 32
 */
#include <stdio.h>

float celsiusParaFahrenheit(float celsius) {
    return (9 * celsius) / 5 + 32;
}

int main() {
    float celsius;

    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &celsius);

    printf("%.2f graus Celsius equivalem a %.2f graus Fahrenheit\n",
           celsius, celsiusParaFahrenheit(celsius));

    return 0;
}
