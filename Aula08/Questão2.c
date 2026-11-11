/*
 * Aula 08 — Questão 2 — Positivos pares e negativos ímpares
 * Material da Profa. Joanacelle Caldas, página 23.
 *
 * Leia 10 inteiros. Armazene os valores positivos e pares em um vetor e os
 * valores negativos e ímpares em outro. Exiba os dois conjuntos em ordem
 * crescente.
 */

#include <stdio.h>
#include <stdlib.h>

static void ordenar(int valores[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        for (int j = i + 1; j < quantidade; j++) {
            if (valores[j] < valores[i]) {
                int temporario = valores[i];
                valores[i] = valores[j];
                valores[j] = temporario;
            }
        }
    }
}

static void exibirVetor(const char *titulo, const int valores[], int quantidade) {
    printf("%s:", titulo);
    if (quantidade == 0) {
        printf(" nenhum");
    }
    for (int i = 0; i < quantidade; i++) {
        printf(" %d", valores[i]);
    }
    putchar('\n');
}

int main(void) {
    enum { ENTRADAS = 10 };
    int numeros[ENTRADAS];
    int quantidadePositivos = 0;
    int quantidadeNegativos = 0;

    for (int i = 0; i < ENTRADAS; i++) {
        printf("Digite o inteiro %d: ", i + 1);
        if (scanf("%d", &numeros[i]) != 1) {
            puts("Entrada invalida.");
            return 1;
        }
    }

    int *positivosPares = malloc(ENTRADAS * sizeof *positivosPares);
    int *negativosImpares = malloc(ENTRADAS * sizeof *negativosImpares);
    if (positivosPares == NULL || negativosImpares == NULL) {
        puts("Memoria insuficiente para os vetores.");
        free(positivosPares);
        free(negativosImpares);
        return 1;
    }

    for (int i = 0; i < ENTRADAS; i++) {
        int numero = numeros[i];
        if (numero > 0 && numero % 2 == 0) {
            positivosPares[quantidadePositivos++] = numero;
        } else if (numero < 0 && numero % 2 != 0) {
            negativosImpares[quantidadeNegativos++] = numero;
        }
    }

    ordenar(positivosPares, quantidadePositivos);
    ordenar(negativosImpares, quantidadeNegativos);
    putchar('\n');
    exibirVetor("Positivos e pares", positivosPares, quantidadePositivos);
    exibirVetor("Negativos e impares", negativosImpares, quantidadeNegativos);

    free(positivosPares);
    free(negativosImpares);
    return 0;
}
