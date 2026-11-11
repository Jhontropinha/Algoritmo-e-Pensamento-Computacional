/*
 * Aula 08 — Questão 3 — Ocorrências e cadastro de animais
 * Material da Profa. Joanacelle Caldas, páginas 23–24.
 *
 * Leia 15 inteiros e armazene-os em um vetor. Identifique os números repetidos
 * e conte quantas vezes cada um aparece. Para cada número primo repetido com
 * frequência ímpar, some todas as ocorrências desse número e cadastre essa
 * quantidade de nomes de animais. Para os números com frequência par, use a
 * posição no vetor original para buscar o animal correspondente entre os nomes
 * cadastrados. Ao final, apresente os resultados das correspondências.
 *
 * A solução usa a primeira posição de cada número distinto com frequência par.
 * As posições são numeradas a partir de 1, assim como a lista de animais.
 * Quando a posição ultrapassa o tamanho da lista, o programa informa que não
 * existe correspondência.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero;
    int frequencia;
    int primeiroIndice;
} Ocorrencia;

typedef char NomeAnimal[80];

static int ehPrimo(int numero) {
    if (numero < 2) {
        return 0;
    }
    for (int divisor = 2; divisor <= numero / divisor; divisor++) {
        if (numero % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    enum { ENTRADAS = 15 };
    int numeros[ENTRADAS];
    Ocorrencia ocorrencias[ENTRADAS];
    int distintos = 0;
    size_t totalAnimais = 0;

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
            ocorrencias[j].primeiroIndice = i;
            distintos++;
        }
        ocorrencias[j].frequencia++;
    }

    for (int i = 0; i < distintos; i++) {
        int numero = ocorrencias[i].numero;
        int frequencia = ocorrencias[i].frequencia;
        if (frequencia > 1 && frequencia % 2 != 0 && ehPrimo(numero)) {
            size_t vagas = SIZE_MAX / sizeof(NomeAnimal) - totalAnimais;
            if ((size_t)numero > vagas / (size_t)frequencia) {
                puts("Quantidade de animais muito grande.");
                return 1;
            }
            totalAnimais += (size_t)numero * (size_t)frequencia;
        }
    }

    NomeAnimal *animais = NULL;
    if (totalAnimais > 0) {
        animais = malloc(totalAnimais * sizeof *animais);
        if (animais == NULL) {
            puts("Memoria insuficiente para os animais.");
            return 1;
        }

        printf("\nCadastre %zu nome(s) de animais.\n", totalAnimais);
        for (size_t i = 0; i < totalAnimais; i++) {
            printf("Nome do animal %zu: ", i + 1);
            if (scanf(" %79[^\n]", animais[i]) != 1) {
                puts("Nome invalido.");
                free(animais);
                return 1;
            }
        }
    }

    puts("\nCorrespondencias");
    for (int i = 0; i < distintos; i++) {
        if (ocorrencias[i].frequencia % 2 == 0) {
            int indice = ocorrencias[i].primeiroIndice;
            printf("Numero %d na posicao %d: ", ocorrencias[i].numero, indice + 1);
            if ((size_t)indice < totalAnimais) {
                puts(animais[indice]);
            } else {
                puts("Nao existe correspondencia.");
            }
        }
    }

    free(animais);
    return 0;
}
