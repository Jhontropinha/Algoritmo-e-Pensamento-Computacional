/*
 * Aula 07 — Questão 3 — Maior de dois números
 * Material da Profa. Joanacelle Caldas, página 26.
 *
 * Crie a função maiorNumero, que recebe dois inteiros e retorna o maior. Caso
 * sejam iguais, retorne qualquer um dos valores.
 */

#include <stdio.h>

int maiorNumero(int primeiro, int segundo) {
    if (primeiro >= segundo) {
        return primeiro;
    }
    return segundo;
}

int main(void) {
    int primeiro;
    int segundo;

    printf("Digite dois inteiros: ");
    if (scanf("%d %d", &primeiro, &segundo) != 2) {
        puts("Entrada invalida.");
        return 1;
    }

    printf("Maior numero: %d\n", maiorNumero(primeiro, segundo));
    return 0;
}
