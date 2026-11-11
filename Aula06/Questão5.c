/*
 * Aula 06 — Questão 5 — Busca de um número no vetor
 * Material da Profa. Joanacelle Caldas, página 28.
 *
 * Leia 10 números inteiros e armazene-os em um vetor. Peça ao usuário um
 * número para pesquisar e informe se ele foi encontrado, quantas vezes aparece
 * e em quais posições.
 *
 * No exemplo do slide, a busca por 8 no vetor 5 8 3 8 2 8 1 4 6 8 encontra
 * quatro ocorrências nos índices 1, 3, 5, 9. Os índices começam em zero.
 */

#include <stdio.h>

int main(void) {
    int valores[10];
    int numero;
    int posicoes[10];
    int ocorrencias = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite o inteiro %d: ", i + 1);
        if (scanf("%d", &valores[i]) != 1) {
            puts("Entrada invalida.");
            return 1;
        }
    }

    printf("Digite o numero para pesquisar: ");
    if (scanf("%d", &numero) != 1) {
        puts("Entrada invalida.");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        if (valores[i] == numero) {
            posicoes[ocorrencias] = i;
            ocorrencias++;
        }
    }

    if (ocorrencias == 0) {
        printf("\nO numero %d nao foi encontrado (0 ocorrencias).\n", numero);
        return 0;
    }

    printf("\nO numero %d foi encontrado %d vez(es).\n", numero, ocorrencias);
    printf("Posicoes: %d", posicoes[0]);
    for (int i = 1; i < ocorrencias; i++) {
        printf(", %d", posicoes[i]);
    }
    putchar('\n');

    return 0;
}
