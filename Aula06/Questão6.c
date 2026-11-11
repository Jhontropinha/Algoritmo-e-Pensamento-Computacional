/*
 * Aula 06 — Questão 6 — Estoque de 10 produtos
 * Material da Profa. Joanacelle Caldas, página 29.
 *
 * Uma loja possui 10 produtos. Armazene em um vetor a quantidade disponível de
 * cada produto e apresente os seguintes resultados.
 *
 * - A quantidade de cada produto.
 * - Os produtos com estoque baixo, com menos de 5 unidades.
 * - Os produtos esgotados, com 0 unidades.
 * - O número de produtos com mais de 20 unidades.
 * - O produto com a maior quantidade em estoque.
 */

#include <stdio.h>

int main(void) {
    int estoque[10];
    int acimaDeVinte = 0;
    int maior = 0;

    for (int i = 0; i < 10; i++) {
        printf("Digite a quantidade do produto %d: ", i + 1);
        if (scanf("%d", &estoque[i]) != 1 || estoque[i] < 0) {
            puts("Quantidade invalida.");
            return 1;
        }
    }

    puts("\nEstoque por produto");
    for (int i = 0; i < 10; i++) {
        printf("Produto %d: %d unidade(s)", i + 1, estoque[i]);
        if (estoque[i] < 5) {
            printf(" [estoque baixo]");
        }
        if (estoque[i] == 0) {
            printf(" [esgotado]");
        }
        putchar('\n');

        if (estoque[i] > 20) {
            acimaDeVinte++;
        }
        if (estoque[i] > estoque[maior]) {
            maior = i;
        }
    }

    printf("\nProdutos com mais de 20 unidades: %d\n", acimaDeVinte);
    printf("Maior estoque: produto %d com %d unidade(s).\n", maior + 1, estoque[maior]);
    return 0;
}
