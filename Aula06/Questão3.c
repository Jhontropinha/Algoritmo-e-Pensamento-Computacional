/*
 * Aula 06 — Questão 3 — Matriz de inteiros
 * Material da Profa. Joanacelle Caldas, páginas 22–23.
 *
 * Gere uma matriz 3 × 3 de inteiros. Exiba os elementos de cada linha
 * separados por um traço e coloque cada linha da matriz em uma nova linha da
 * saída.
 *
 * Exemplo de saída
 *
 * 300 - 5 - 3
 * 4 - 10 - 3
 * 12 - 337 - 5
 */

#include <stdio.h>

int main(void) {
    int matriz[3][3];

    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            printf("Digite o inteiro da linha %d, coluna %d: ", linha + 1, coluna + 1);
            if (scanf("%d", &matriz[linha][coluna]) != 1) {
                puts("Entrada invalida.");
                return 1;
            }
        }
    }

    puts("\nMatriz 3 x 3");
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            if (coluna > 0) {
                printf(" - ");
            }
            printf("%d", matriz[linha][coluna]);
        }
        putchar('\n');
    }

    return 0;
}
