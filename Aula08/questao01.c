/*
 * Aula 08 - Ponteiros e Vetores Dinamicos
 * Questao 01 - Sorteio beneficente.
 *
 * Conteudos usados: vetores, funcoes, ponteiros e alocacao dinamica (malloc/free).
 * Como "struct" so e visto na Aula 09, os produtos sao guardados em vetores
 * paralelos: nomes[k], precos[k] e quantidades[k] pertencem ao mesmo produto.
 *
 * Regras:
 *  - numero com quantidade IMPAR de ocorrencias -> representa a quantidade de
 *    unidades de um produto a ser comprado; o usuario cadastra nome e preco.
 *  - numero com quantidade PAR de ocorrencias -> vai para um segundo vetor,
 *    ordenado em ordem decrescente.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 12
#define TAM_NOME 50

/* Procura 'valor' no vetor; retorna o indice ou -1 */
int buscar(int *vetor, int quantidade, int valor) {
    int i;
    for (i = 0; i < quantidade; i++) {
        if (*(vetor + i) == valor) {
            return i;
        }
    }
    return -1;
}

void trocarInteiros(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void trocarFloats(float *a, float *b) {
    float aux = *a;
    *a = *b;
    *b = aux;
}

/* Bubble sort em ordem decrescente */
void ordenarDecrescente(int *vetor, int quantidade) {
    int i, j;
    for (i = 0; i < quantidade - 1; i++) {
        for (j = 0; j < quantidade - 1 - i; j++) {
            if (vetor[j] < vetor[j + 1]) {
                trocarInteiros(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

/* Ordena os produtos em ordem alfabetica, mantendo preco e quantidade associados.
   Como cada nome e um ponteiro (char *), basta trocar os ponteiros de lugar. */
void ordenarProdutos(char **nomes, float *precos, int *quantidades, int total) {
    int i, j;
    char *auxNome;

    for (i = 0; i < total - 1; i++) {
        for (j = 0; j < total - 1 - i; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                auxNome = nomes[j];
                nomes[j] = nomes[j + 1];
                nomes[j + 1] = auxNome;
                trocarFloats(&precos[j], &precos[j + 1]);
                trocarInteiros(&quantidades[j], &quantidades[j + 1]);
            }
        }
    }
}

int main() {
    int numeros[TAM];
    int *distintos, *ocorrencias, *pares, *quantidades;
    char **nomes;
    float *precos;
    int qtdDistintos = 0, qtdImpares = 0, qtdPares = 0;
    int i, pos, k;

    /* Leitura dos 12 numeros */
    printf("Digite 12 numeros inteiros:\n");
    for (i = 0; i < TAM; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    /* a) Contagem de ocorrencias (no maximo 12 numeros distintos) */
    distintos = (int *) malloc(TAM * sizeof(int));
    ocorrencias = (int *) malloc(TAM * sizeof(int));
    if (distintos == NULL || ocorrencias == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < TAM; i++) {
        pos = buscar(distintos, qtdDistintos, numeros[i]);
        if (pos == -1) {
            distintos[qtdDistintos] = numeros[i];
            ocorrencias[qtdDistintos] = 1;
            qtdDistintos++;
        } else {
            ocorrencias[pos]++;
        }
    }

    for (i = 0; i < qtdDistintos; i++) {
        if (ocorrencias[i] % 2 != 0) {
            qtdImpares++;
        } else {
            qtdPares++;
        }
    }

    /* c) Segundo vetor com os numeros de ocorrencia par (alocado no tamanho exato) */
    pares = (int *) malloc((qtdPares > 0 ? qtdPares : 1) * sizeof(int));
    k = 0;
    for (i = 0; i < qtdDistintos; i++) {
        if (ocorrencias[i] % 2 == 0) {
            pares[k] = distintos[i];
            k++;
        }
    }
    ordenarDecrescente(pares, qtdPares);

    /* d) Cadastro dos produtos (um para cada numero de ocorrencia impar) */
    nomes = (char **) malloc((qtdImpares > 0 ? qtdImpares : 1) * sizeof(char *));
    precos = (float *) malloc((qtdImpares > 0 ? qtdImpares : 1) * sizeof(float));
    quantidades = (int *) malloc((qtdImpares > 0 ? qtdImpares : 1) * sizeof(int));
    if (nomes == NULL || precos == NULL || quantidades == NULL || pares == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    if (qtdImpares > 0) {
        printf("\n===== CADASTRO DOS PRODUTOS PARA O SORTEIO =====\n");
    }
    k = 0;
    for (i = 0; i < qtdDistintos; i++) {
        if (ocorrencias[i] % 2 != 0) {
            nomes[k] = (char *) malloc(TAM_NOME * sizeof(char));
            quantidades[k] = distintos[i];

            printf("\nProduto %d (quantidade a comprar: %d)\n", k + 1, distintos[i]);
            printf("Nome do produto: ");
            scanf(" %49[^\n]", nomes[k]);
            printf("Preco unitario: R$ ");
            scanf("%f", &precos[k]);
            k++;
        }
    }

    /* e) Ordem alfabetica */
    ordenarProdutos(nomes, precos, quantidades, qtdImpares);

    /* ================== SAIDA ================== */
    printf("\n================ RESULTADO ================\n");

    printf("\na) Numeros informados:\n   ");
    for (i = 0; i < TAM; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    printf("\nb) Ocorrencias de cada numero:\n");
    for (i = 0; i < qtdDistintos; i++) {
        printf("   Numero %d: %d vez(es)\n", distintos[i], ocorrencias[i]);
    }

    printf("\nc) Produtos para compra (ordem alfabetica):\n");
    if (qtdImpares == 0) {
        printf("   Nenhum produto cadastrado.\n");
    }
    for (i = 0; i < qtdImpares; i++) {
        printf("   %-25s Preco: R$ %8.2f   Quantidade: %d\n", nomes[i], precos[i], quantidades[i]);
    }

    printf("\nd) Numeros com quantidade par de ocorrencias (ordem decrescente):\n   ");
    if (qtdPares == 0) {
        printf("Nenhum numero.");
    }
    for (i = 0; i < qtdPares; i++) {
        printf("%d ", pares[i]);
    }
    printf("\n");

    /* Libera a memoria alocada */
    for (i = 0; i < qtdImpares; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(precos);
    free(quantidades);
    free(pares);
    free(distintos);
    free(ocorrencias);

    return 0;
}
