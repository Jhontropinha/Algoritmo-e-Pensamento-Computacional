/*
 * Aula 07 — Questão 9 — Tabuada
 * Material da Profa. Joanacelle Caldas, página 27.
 *
 * Crie a função mostrarTabuada, que recebe um inteiro e exibe sua tabuada de 1
 * a 10. Na main, leia o número informado e chame a função.
 */

#include <stdio.h>

void mostrarTabuada(int numero) {
    for (int fator = 1; fator <= 10; fator++) {
        printf("%d x %d = %lld\n", numero, fator, (long long)numero * fator);
    }
}

int main(void) {
    int numero;

    printf("Digite um inteiro: ");
    if (scanf("%d", &numero) != 1) {
        puts("Entrada invalida.");
        return 1;
    }

    mostrarTabuada(numero);
    return 0;
}
