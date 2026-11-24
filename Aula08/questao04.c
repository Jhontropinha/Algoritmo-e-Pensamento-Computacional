/*
 * Aula 08 - Ponteiros e Vetores Dinamicos
 * Questao 04 - Competicao de apostadores com a soma da sequencia de Fibonacci.
 *
 * Sequencia de Fibonacci usada: 1, 1, 2, 3, 5, 8, ...
 * Ex.: valor 5 -> 1 + 1 + 2 + 3 + 5 = 12.
 * O valor informado fica limitado a 80 termos para o resultado caber em um long long.
 *
 * Premiacao (ninguem recebe mais de um premio):
 *   1o lugar: maior resultado primo.
 *   2o lugar: maior resultado par entre os ainda nao premiados.
 *   3o lugar: maior resultado acima da media entre os ainda nao premiados.
 * Se ninguem atender a um criterio, o premio fica sem vencedor.
 */
#include <stdio.h>
#include <stdlib.h>

#define APOSTADORES 5
#define TAM_NOME 50
#define MAX_TERMOS 80

/* b) Soma dos 'termos' primeiros termos da sequencia de Fibonacci */
long long somaFibonacci(int termos) {
    long long anterior = 0, atual = 1, proximo, soma = 0;
    int i;

    for (i = 1; i <= termos; i++) {
        soma += atual;
        proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }
    return soma;
}

/* d) Verifica se um resultado e primo */
int ehPrimo(long long n) {
    long long d;
    if (n < 2) return 0;
    if (n % 2 == 0) return n == 2;
    for (d = 3; d * d <= n; d += 2) {
        if (n % d == 0) return 0;
    }
    return 1;
}

/* Retorna o indice do maior resultado que atende ao criterio, ou -1.
   criterio 1 = primo, 2 = par, 3 = acima da media. */
int buscarVencedor(long long *resultados, int *premiado, int criterio, double media) {
    int i, vencedor = -1, atende;

    for (i = 0; i < APOSTADORES; i++) {
        if (premiado[i]) continue;

        if (criterio == 1) {
            atende = ehPrimo(resultados[i]);
        } else if (criterio == 2) {
            atende = (resultados[i] % 2 == 0);
        } else {
            atende = (resultados[i] > media);
        }

        if (atende && (vencedor == -1 || resultados[i] > resultados[vencedor])) {
            vencedor = i;
        }
    }
    return vencedor;
}

int main() {
    char nomes[APOSTADORES][TAM_NOME];
    int valores[APOSTADORES];
    int premiado[APOSTADORES] = {0};
    long long *resultados;
    double media = 0;
    int i, lugar, vencedor;

    /* c) Vetor de resultados alocado dinamicamente */
    resultados = (long long *) malloc(APOSTADORES * sizeof(long long));
    if (resultados == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    /* a) Cadastro dos apostadores */
    for (i = 0; i < APOSTADORES; i++) {
        printf("\nApostador %d\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", nomes[i]);
        do {
            printf("Numero inteiro positivo (1 a %d): ", MAX_TERMOS);
            scanf("%d", &valores[i]);
            if (valores[i] < 1 || valores[i] > MAX_TERMOS) {
                printf("Valor invalido.\n");
            }
        } while (valores[i] < 1 || valores[i] > MAX_TERMOS);

        resultados[i] = somaFibonacci(valores[i]);
        media += resultados[i];
    }
    media = media / APOSTADORES;

    /* e), f), g), h) Premiacao em sequencia, marcando quem ja foi premiado */
    printf("\n========== VENCEDORES ==========\n");
    for (lugar = 1; lugar <= 3; lugar++) {
        vencedor = buscarVencedor(resultados, premiado, lugar, media);
        if (vencedor != -1) {
            premiado[vencedor] = 1;
            printf("%do lugar: %s\n", lugar, nomes[vencedor]);
        } else {
            printf("%do lugar: sem vencedor\n", lugar);
        }
    }

    free(resultados);
    return 0;
}
