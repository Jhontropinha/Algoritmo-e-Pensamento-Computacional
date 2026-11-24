/*
 * Aula 07 - Funcoes
 * Questao 09 - Exibe a tabuada de 1 a 10 de um numero.
 */
#include <stdio.h>

void mostrarTabuada(int numero) {
    int i;

    printf("\nTabuada do %d:\n", numero);
    for (i = 1; i <= 10; i++) {
        printf("%d x %2d = %d\n", numero, i, numero * i);
    }
}

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    mostrarTabuada(numero);

    return 0;
}
