/*
 * Aula 07 — Questão 2 — Dobro de um inteiro
 * Material da Profa. Joanacelle Caldas, página 26.
 *
 * Crie a função calcularDobro, que recebe um inteiro e retorna seu dobro. Na
 * main, leia um número, chame a função e exiba o resultado.
 */

#include <stdio.h>

long long calcularDobro(int numero) {
    return 2LL * numero;
}

int main(void) {
    int numero;

    printf("Digite um inteiro: ");
    if (scanf("%d", &numero) != 1) {
        puts("Entrada invalida.");
        return 1;
    }

    printf("Dobro: %lld\n", calcularDobro(numero));
    return 0;
}
