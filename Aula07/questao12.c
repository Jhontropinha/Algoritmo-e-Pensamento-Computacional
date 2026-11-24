/*
 * Aula 07 - Funcoes
 * Questao 12 - Sistema de estoque simplificado com 8 produtos.
 *
 * Os produtos tem codigos de 1 a 8, mas o vetor usa indices de 0 a 7.
 * Por isso a conversao e: indice = codigo - 1.
 */
#include <stdio.h>

#define PRODUTOS 8

int calcularTotalEstoque(int estoque[], int quantidade) {
    int i, total = 0;

    for (i = 0; i < quantidade; i++) {
        total = total + estoque[i];
    }
    return total;
}

int contarEstoqueBaixo(int estoque[], int quantidade) {
    int i, contador = 0;

    for (i = 0; i < quantidade; i++) {
        if (estoque[i] < 5) {
            contador++;
        }
    }
    return contador;
}

/* Retorna a posicao (indice) do produto no vetor, ou -1 se o codigo nao existir */
int buscarProduto(int estoque[], int codigo) {
    int indice = codigo - 1;

    if (indice >= 0 && indice < PRODUTOS) {
        return indice;
    }
    return -1;
}

int main() {
    int estoque[PRODUTOS];
    int i, codigo, posicao;

    printf("Informe a quantidade em estoque de cada produto:\n");
    for (i = 0; i < PRODUTOS; i++) {
        printf("Produto codigo %d: ", i + 1);
        scanf("%d", &estoque[i]);
    }

    printf("\nTotal de itens em estoque: %d\n", calcularTotalEstoque(estoque, PRODUTOS));
    printf("Produtos com estoque baixo (menos de 5 unidades): %d\n",
           contarEstoqueBaixo(estoque, PRODUTOS));

    printf("\nDigite o codigo do produto que deseja buscar (1 a 8): ");
    scanf("%d", &codigo);

    posicao = buscarProduto(estoque, codigo);
    if (posicao == -1) {
        printf("Produto de codigo %d nao encontrado.\n", codigo);
    } else {
        printf("Produto de codigo %d encontrado na posicao %d do vetor.\n", codigo, posicao);
        printf("Quantidade em estoque: %d\n", estoque[posicao]);
    }

    return 0;
}
