/*
 * Aula 06 - Vetores
 * Questao 01 - Pesquisa de um numero em um vetor de 10 inteiros.
 *
 * Conteudos usados: variaveis, entrada/saida, if/else, for e vetores.
 * As posicoes sao mostradas a partir de 0 (indice do vetor), como no exemplo
 * do enunciado: 5 8 3 8 2 8 1 4 6 8 -> o 8 esta nas posicoes 1, 3, 5, 9.
 */
#include <stdio.h>

int main() {
    int numeros[10];
    int i, busca, quantidade = 0, impressos = 0;

    printf("Digite 10 numeros inteiros:\n");
    for (i = 0; i < 10; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\nArray: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    printf("Digite um numero: ");
    scanf("%d", &busca);

    /* Conta quantas vezes o numero aparece */
    for (i = 0; i < 10; i++) {
        if (numeros[i] == busca) {
            quantidade++;
        }
    }

    if (quantidade == 0) {
        printf("O numero %d nao foi encontrado.\n", busca);
    } else {
        if (quantidade == 1) {
            printf("O numero %d foi encontrado 1 vez.\n", busca);
        } else {
            printf("O numero %d foi encontrado %d vezes.\n", busca, quantidade);
        }

        printf("Posicoes: ");
        for (i = 0; i < 10; i++) {
            if (numeros[i] == busca) {
                if (impressos > 0) {
                    printf(", ");
                }
                printf("%d", i);
                impressos++;
            }
        }
        printf("\n");
    }

    return 0;
}
