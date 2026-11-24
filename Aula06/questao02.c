/*
 * Aula 06 - Vetores
 * Questao 02 - Controle de estoque de 10 produtos.
 *
 * Conteudos usados: variaveis, entrada/saida, if/else, for e vetores.
 * Os produtos sao numerados de 1 a 10 para o usuario.
 */
#include <stdio.h>

int main() {
    int estoque[10];
    int i;
    int baixo = 0, esgotados = 0, acimaDe20 = 0;
    int posicaoMaior = 0;

    printf("Informe a quantidade disponivel de cada produto:\n");
    for (i = 0; i < 10; i++) {
        do {
            printf("Produto %d: ", i + 1);
            scanf("%d", &estoque[i]);
            if (estoque[i] < 0) {
                printf("A quantidade nao pode ser negativa. Tente novamente.\n");
            }
        } while (estoque[i] < 0);
    }

    /* a) Quantidade de cada produto */
    printf("\n===== QUANTIDADE DE CADA PRODUTO =====\n");
    for (i = 0; i < 10; i++) {
        printf("Produto %2d: %d unidade(s)\n", i + 1, estoque[i]);
    }

    /* b) Estoque baixo (quantidade < 5). Os esgotados (0) aparecem na lista de esgotados. */
    printf("\nProdutos com estoque baixo (menos de 5 unidades): ");
    for (i = 0; i < 10; i++) {
        if (estoque[i] > 0 && estoque[i] < 5) {
            printf("%d ", i + 1);
            baixo++;
        }
    }
    if (baixo == 0) {
        printf("nenhum");
    }
    printf("\n");

    /* c) Produtos esgotados (quantidade = 0) */
    printf("Produtos esgotados: ");
    for (i = 0; i < 10; i++) {
        if (estoque[i] == 0) {
            printf("%d ", i + 1);
            esgotados++;
        }
    }
    if (esgotados == 0) {
        printf("nenhum");
    }
    printf("\n");

    /* d) Quantos produtos possuem mais de 20 unidades */
    for (i = 0; i < 10; i++) {
        if (estoque[i] > 20) {
            acimaDe20++;
        }
    }
    printf("Quantidade de produtos com mais de 20 unidades: %d\n", acimaDe20);

    /* e) Produto com a maior quantidade em estoque */
    for (i = 1; i < 10; i++) {
        if (estoque[i] > estoque[posicaoMaior]) {
            posicaoMaior = i;
        }
    }
    printf("Produto com maior quantidade em estoque: Produto %d (%d unidades)\n",
           posicaoMaior + 1, estoque[posicaoMaior]);

    return 0;
}
