/*
 * Aula 08 — Questão 1 — Compras para um sorteio beneficente
 * Material da Profa. Joanacelle Caldas, página 22.
 *
 * Leia 12 números inteiros e armazene-os em um vetor. Conte quantas vezes cada
 * número distinto aparece. Cada número com frequência ímpar indica quantos
 * produtos deverão ser comprados. Para cada um desses números, cadastre o nome
 * e o preço unitário de cada produto. Armazene os números com frequência par
 * em um segundo vetor e ordene esse vetor em ordem decrescente.
 *
 * Ao final, apresente os 12 números digitados, a frequência de cada número
 * distinto, os nomes e preços dos produtos em ordem alfabética e os números de
 * frequência par em ordem decrescente. Na solução, valores zero ou negativos
 * são contados normalmente e geram zero compras quando a frequência é ímpar.
 */

#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    int frequencia;
} Ocorrencia;

typedef struct {
    char nome[80];
    double preco;
} Produto;

static void copiarEmMinusculas(char destino[], const char origem[]) {
    int i = 0;
    for (; origem[i] != '\0'; i++) {
        destino[i] = (char)tolower((unsigned char)origem[i]);
    }
    destino[i] = '\0';
}

static int compararProdutos(const void *primeiro, const void *segundo) {
    const Produto *produto1 = primeiro;
    const Produto *produto2 = segundo;
    char nome1[80];
    char nome2[80];
    copiarEmMinusculas(nome1, produto1->nome);
    copiarEmMinusculas(nome2, produto2->nome);
    return strcoll(nome1, nome2);
}

int main(void) {
    enum { ENTRADAS = 12 };
    int numeros[ENTRADAS];
    Ocorrencia ocorrencias[ENTRADAS];
    int distintos = 0;
    int frequenciaPar[ENTRADAS];
    int quantidadePares = 0;
    size_t totalProdutos = 0;

    setlocale(LC_COLLATE, "");
    setlocale(LC_CTYPE, "");

    for (int i = 0; i < ENTRADAS; i++) {
        printf("Digite o inteiro %d: ", i + 1);
        if (scanf("%d", &numeros[i]) != 1) {
            puts("Entrada invalida.");
            return 1;
        }
    }

    for (int i = 0; i < ENTRADAS; i++) {
        int j = 0;
        while (j < distintos && ocorrencias[j].numero != numeros[i]) {
            j++;
        }
        if (j == distintos) {
            ocorrencias[j].numero = numeros[i];
            ocorrencias[j].frequencia = 0;
            distintos++;
        }
        ocorrencias[j].frequencia++;
    }

    for (int i = 0; i < distintos; i++) {
        int numero = ocorrencias[i].numero;
        if (ocorrencias[i].frequencia % 2 == 0) {
            frequenciaPar[quantidadePares++] = numero;
        } else if (numero > 0) {
            if ((size_t)numero > SIZE_MAX / sizeof(Produto) - totalProdutos) {
                puts("Quantidade de produtos muito grande.");
                return 1;
            }
            totalProdutos += (size_t)numero;
        }
    }

    Produto *produtos = NULL;
    if (totalProdutos > 0) {
        produtos = malloc(totalProdutos * sizeof *produtos);
        if (produtos == NULL) {
            puts("Memoria insuficiente para os produtos.");
            return 1;
        }
    }

    size_t cadastrados = 0;
    for (int i = 0; i < distintos; i++) {
        int numero = ocorrencias[i].numero;
        if (ocorrencias[i].frequencia % 2 == 0 || numero <= 0) {
            continue;
        }

        printf("\nCadastre %d produto(s).\n", numero);
        for (int j = 0; j < numero; j++) {
            Produto *produto = &produtos[cadastrados];
            printf("Nome do produto %zu: ", cadastrados + 1);
            if (scanf(" %79[^\n]", produto->nome) != 1) {
                puts("Nome invalido.");
                free(produtos);
                return 1;
            }

            printf("Preco unitario: ");
            if (scanf("%lf", &produto->preco) != 1 ||
                !isfinite(produto->preco) || produto->preco < 0) {
                puts("Preco invalido.");
                free(produtos);
                return 1;
            }
            cadastrados++;
        }
    }

    if (totalProdutos > 1) {
        qsort(produtos, totalProdutos, sizeof *produtos, compararProdutos);
    }

    for (int i = 0; i < quantidadePares; i++) {
        for (int j = i + 1; j < quantidadePares; j++) {
            if (frequenciaPar[j] > frequenciaPar[i]) {
                int temporario = frequenciaPar[i];
                frequenciaPar[i] = frequenciaPar[j];
                frequenciaPar[j] = temporario;
            }
        }
    }

    printf("\nNumeros informados:");
    for (int i = 0; i < ENTRADAS; i++) {
        printf(" %d", numeros[i]);
    }
    puts("\n\nOcorrencias por numero");
    for (int i = 0; i < distintos; i++) {
        printf("%d: %d vez(es)\n", ocorrencias[i].numero, ocorrencias[i].frequencia);
    }

    puts("\nProdutos em ordem alfabetica");
    if (totalProdutos == 0) {
        puts("Nenhum produto para comprar.");
    }
    for (size_t i = 0; i < totalProdutos; i++) {
        printf("%s - R$ %.2f\n", produtos[i].nome, produtos[i].preco);
    }

    printf("\nNumeros com frequencia par:");
    if (quantidadePares == 0) {
        printf(" nenhum");
    }
    for (int i = 0; i < quantidadePares; i++) {
        printf(" %d", frequenciaPar[i]);
    }
    putchar('\n');

    free(produtos);
    return 0;
}
