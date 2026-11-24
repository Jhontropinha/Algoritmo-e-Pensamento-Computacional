/*
 * Aula 07 - Funcoes
 * Questao 08 - Verifica se um numero e primo.
 *
 * Desafio adicional: os divisores sao testados somente ate a raiz quadrada
 * do numero, sem usar sqrt(). Para isso, a condicao do laco e
 * divisor * divisor <= numero (equivale a divisor <= raiz(numero)).
 */
#include <stdio.h>

int ehPrimo(int numero) {
    int divisor;

    if (numero < 2) {
        return 0;
    }
    if (numero == 2) {
        return 1;
    }
    if (numero % 2 == 0) {
        return 0;
    }

    /* So precisa testar divisores impares ate a raiz quadrada */
    for (divisor = 3; divisor * divisor <= numero; divisor += 2) {
        if (numero % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    if (ehPrimo(numero)) {
        printf("O numero %d e primo.\n", numero);
    } else {
        printf("O numero %d nao e primo.\n", numero);
    }

    return 0;
}
