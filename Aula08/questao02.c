/*
 * Aula 08 - Ponteiros e Vetores Dinamicos
 * Questao 02 - Separa os valores positivos e pares e os negativos e impares
 * em vetores distintos (alocados dinamicamente) e os mostra em ordem crescente.
 *
 * Observacao: o zero nao e positivo nem negativo, entao nao entra em nenhum grupo.
 */
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void ordenarCrescente(int *vetor, int quantidade) {
    int i, j, aux;
    for (i = 0; i < quantidade - 1; i++) {
        for (j = 0; j < quantidade - 1 - i; j++) {
            if (*(vetor + j) > *(vetor + j + 1)) {
                aux = *(vetor + j);
                *(vetor + j) = *(vetor + j + 1);
                *(vetor + j + 1) = aux;
            }
        }
    }
}

void mostrarVetor(int *vetor, int quantidade) {
    int i;
    if (quantidade == 0) {
        printf("nenhum valor");
    }
    for (i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int valores[TAM];
    int *positivosPares, *negativosImpares;
    int qtdPosPares = 0, qtdNegImpares = 0;
    int i, a, b;

    printf("Digite 10 valores inteiros:\n");
    for (i = 0; i < TAM; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valores[i]);
    }

    /* Primeiro conta quantos valores cabem em cada grupo */
    for (i = 0; i < TAM; i++) {
        if (valores[i] > 0 && valores[i] % 2 == 0) {
            qtdPosPares++;
        } else if (valores[i] < 0 && valores[i] % 2 != 0) {
            qtdNegImpares++;
        }
    }

    /* Aloca cada vetor com o tamanho exato necessario */
    positivosPares = (int *) malloc((qtdPosPares > 0 ? qtdPosPares : 1) * sizeof(int));
    negativosImpares = (int *) malloc((qtdNegImpares > 0 ? qtdNegImpares : 1) * sizeof(int));
    if (positivosPares == NULL || negativosImpares == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    a = 0;
    b = 0;
    for (i = 0; i < TAM; i++) {
        if (valores[i] > 0 && valores[i] % 2 == 0) {
            positivosPares[a++] = valores[i];
        } else if (valores[i] < 0 && valores[i] % 2 != 0) {
            negativosImpares[b++] = valores[i];
        }
    }

    ordenarCrescente(positivosPares, qtdPosPares);
    ordenarCrescente(negativosImpares, qtdNegImpares);

    printf("\nPositivos e pares (ordem crescente): ");
    mostrarVetor(positivosPares, qtdPosPares);
    printf("Negativos e impares (ordem crescente): ");
    mostrarVetor(negativosImpares, qtdNegImpares);

    free(positivosPares);
    free(negativosImpares);

    return 0;
}
