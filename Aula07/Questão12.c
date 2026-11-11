/*
 * Aula 07 — Questão 12 — Estoque de oito produtos
 * Material da Profa. Joanacelle Caldas, página 28.
 *
 * Armazene em um vetor as quantidades de oito produtos. Implemente
 * calcularTotalEstoque para somar as quantidades e contarEstoqueBaixo para
 * contar os produtos com menos de cinco unidades. Implemente buscarProduto,
 * que recebe o vetor e o código do produto e retorna seu índice ou -1 caso o
 * produto não exista. Os códigos vão de 1 a 8 e devem ser convertidos para
 * índices do vetor.
 */

#include <stdio.h>

enum { PRODUTOS = 8 };

long long calcularTotalEstoque(const int estoque[]) {
    long long total = 0;
    for (int i = 0; i < PRODUTOS; i++) {
        total += estoque[i];
    }
    return total;
}

int contarEstoqueBaixo(const int estoque[]) {
    int baixos = 0;
    for (int i = 0; i < PRODUTOS; i++) {
        if (estoque[i] < 5) {
            baixos++;
        }
    }
    return baixos;
}

int buscarProduto(const int estoque[], int codigo) {
    if (estoque == NULL || codigo < 1 || codigo > PRODUTOS) {
        return -1;
    }
    return codigo - 1;
}

int main(void) {
    int estoque[PRODUTOS];
    int codigo;

    for (int i = 0; i < PRODUTOS; i++) {
        printf("Digite a quantidade do produto %d: ", i + 1);
        if (scanf("%d", &estoque[i]) != 1 || estoque[i] < 0) {
            puts("Quantidade invalida.");
            return 1;
        }
    }

    printf("\nTotal em estoque: %lld\n", calcularTotalEstoque(estoque));
    printf("Produtos com estoque baixo: %d\n", contarEstoqueBaixo(estoque));
    printf("Digite o codigo do produto para buscar: ");
    if (scanf("%d", &codigo) != 1) {
        puts("Codigo invalido.");
        return 1;
    }

    int posicao = buscarProduto(estoque, codigo);
    if (posicao == -1) {
        puts("Produto nao encontrado.");
    } else {
        printf("Produto %d no indice %d: %d unidade(s).\n", codigo, posicao, estoque[posicao]);
    }

    return 0;
}
