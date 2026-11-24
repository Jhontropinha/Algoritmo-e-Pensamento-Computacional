/*
 * Aula 07 - Funcoes
 * Questao 05 - Funcao que retorna 1 se o numero for par e 0 se for impar.
 */
#include <stdio.h>

int ehPar(int numero) {
    if (numero % 2 == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (ehPar(numero) == 1) {
        printf("O numero %d e par.\n", numero);
    } else {
        printf("O numero %d e impar.\n", numero);
    }

    return 0;
}
