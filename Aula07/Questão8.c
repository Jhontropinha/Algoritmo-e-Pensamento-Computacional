/*
 * Aula 07 — Questão 8 — Verificação de número primo
 * Material da Profa. Joanacelle Caldas, página 27.
 *
 * Crie a função ehPrimo, que recebe um inteiro e retorna 1 se ele for primo ou
 * 0 nos demais casos. Na main, solicite um número e informe o resultado.
 * Números menores que 2 recebem 0. Como desafio, teste os divisores somente
 * até a raiz quadrada do número, sem usar sqrt().
 */

#include <stdio.h>

int ehPrimo(int numero) {
    if (numero < 2) {
        return 0;
    }

    // Testa ate a raiz sem calcular o quadrado do divisor.
    for (int divisor = 2; divisor <= numero / divisor; divisor++) {
        if (numero % divisor == 0) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    int numero;

    printf("Digite um inteiro: ");
    if (scanf("%d", &numero) != 1) {
        puts("Entrada invalida.");
        return 1;
    }

    if (ehPrimo(numero)) {
        printf("%d e primo.\n", numero);
    } else {
        printf("%d nao e primo.\n", numero);
    }

    return 0;
}
