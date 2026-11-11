/*
 * Aula 07 — Questão 5 — Par ou ímpar
 * Material da Profa. Joanacelle Caldas, página 26.
 *
 * Crie a função ehPar, que recebe um inteiro e retorna 1 para um número par ou
 * 0 para um número ímpar. Na main, leia um número e informe se ele é par ou
 * ímpar usando o resultado da função.
 */

#include <stdio.h>

int ehPar(int numero) {
    return numero % 2 == 0;
}

int main(void) {
    int numero;

    printf("Digite um inteiro: ");
    if (scanf("%d", &numero) != 1) {
        puts("Entrada invalida.");
        return 1;
    }

    if (ehPar(numero)) {
        printf("%d e par.\n", numero);
    } else {
        printf("%d e impar.\n", numero);
    }

    return 0;
}
