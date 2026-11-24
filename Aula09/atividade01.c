/*
 * Aula 09 - Registros e Arquivos
 * Atividade 1 - Estoque de uma loja de eletronicos em arquivo texto.
 *
 * Cada linha do estoque.txt tem o formato:  codigo;nome;preco
 * O separador ';' permite que o nome tenha espacos.
 */
#include <stdio.h>

#define QTD 3

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

int main() {
    Produto produtos[QTD];
    Produto lido;
    FILE *arquivo;
    int i;

    /* a) Leitura dos 3 produtos */
    for (i = 0; i < QTD; i++) {
        printf("\nProduto %d\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);
        printf("Nome: ");
        scanf(" %49[^\n]", produtos[i].nome);
        printf("Preco: R$ ");
        scanf("%f", &produtos[i].preco);
    }

    /* b) Gravacao no arquivo texto, um produto por linha */
    arquivo = fopen("estoque.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo estoque.txt\n");
        return 1;
    }
    for (i = 0; i < QTD; i++) {
        fprintf(arquivo, "%d;%s;%.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }
    fclose(arquivo);
    printf("\nDados salvos em estoque.txt\n");

    /* c) Reabre para leitura e exibe os produtos */
    arquivo = fopen("estoque.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo estoque.txt\n");
        return 1;
    }

    printf("\n================ ESTOQUE ================\n");
    printf("%-8s %-22s %10s\n", "Codigo", "Nome", "Preco");
    printf("-----------------------------------------\n");
    while (fscanf(arquivo, "%d;%49[^;];%f\n", &lido.codigo, lido.nome, &lido.preco) == 3) {
        printf("%-8d %-22s R$ %7.2f\n", lido.codigo, lido.nome, lido.preco);
    }
    printf("=========================================\n");

    fclose(arquivo);
    return 0;
}
