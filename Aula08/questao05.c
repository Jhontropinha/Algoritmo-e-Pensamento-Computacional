/*
 * Aula 08 - Ponteiros e Vetores Dinamicos
 * Questao 05 - Cadastro de 4 participantes, IDs por fatorial, matriz dinamica,
 * media ponderada e classificacao em relacao a diagonal de um retangulo.
 *
 * Conteudos usados: vetores, matriz, funcoes, ponteiros e alocacao dinamica.
 * (Sem struct: os dados de cada participante ficam em vetores paralelos.)
 *
 * Observacoes de implementacao:
 *  - Como o recalculo do ID usa "a quantidade de valores capturados", os IDs sao
 *    calculados logo depois da captura dos valores.
 *  - ID = fatorial(idade) / 2 (divisao inteira). Se repetir um ID ja usado,
 *    recalcula com fatorial(metade da idade) elevado a quantidade de valores;
 *    se ainda repetir, divide a idade pela metade de novo, e assim por diante.
 *    Se a metade chegar a 0 e ainda houver repeticao (ex.: idades iguais),
 *    o ID e incrementado de 1 em 1 ate ficar unico, para o laco sempre terminar.
 *  - Fatoriais crescem muito rapido, por isso sao calculados em double.
 *  - A diagonal usa os dois primeiros valores nao negativos na ordem em que foram
 *    digitados (antes da ordenacao alfabetica).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define QTD 4
#define TAM_NOME 50
#define LARGURA 18          /* largura da coluna de nomes na saida final */
#define TOLERANCIA 0.0001   /* para comparar numeros reais (igualdade) */

double fatorial(int n) {
    double resultado = 1;
    int i;
    for (i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

double potencia(double base, int expoente) {
    double resultado = 1;
    int i;
    for (i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

/* Verifica se 'id' ja foi usado por algum dos 'quantidade' primeiros participantes */
int idRepetido(double *ids, int quantidade, double id) {
    int i;
    for (i = 0; i < quantidade; i++) {
        if (ids[i] == id) return 1;
    }
    return 0;
}

void calcularIds(int *idades, double *ids, int qtdValores) {
    int i, base;
    double id;

    for (i = 0; i < QTD; i++) {
        base = idades[i];
        id = floor(fatorial(base) / 2);

        while (idRepetido(ids, i, id) || isinf(id)) {
            if (base > 0) {
                base = base / 2;
                id = potencia(fatorial(base), qtdValores);
            } else {
                id = id + 1;
            }
        }
        ids[i] = id;
    }
}

/* 4) Media ponderada com pesos 1, 2, 3, ... */
double mediaPonderada(double *linha, int qtdValores) {
    double somaValores = 0, somaPesos = 0;
    int j;
    for (j = 0; j < qtdValores; j++) {
        somaValores += linha[j] * (j + 1);
        somaPesos += (j + 1);
    }
    return somaValores / somaPesos;
}

/* Compara dois nomes sem diferenciar maiusculas e minusculas */
int compararNomes(char *a, char *b) {
    while (*a != '\0' && *b != '\0') {
        int ca = tolower((unsigned char) *a);
        int cb = tolower((unsigned char) *b);
        if (ca != cb) return ca - cb;
        a++;
        b++;
    }
    return tolower((unsigned char) *a) - tolower((unsigned char) *b);
}

/* 3) Ordena por nome mantendo idade, ID e linha da matriz associados */
void ordenarParticipantes(char nomes[][TAM_NOME], int *idades, double *ids, double **valores) {
    int i, j, auxIdade;
    double auxId;
    double *auxLinha;
    char auxNome[TAM_NOME];

    for (i = 0; i < QTD - 1; i++) {
        for (j = 0; j < QTD - 1 - i; j++) {
            if (compararNomes(nomes[j], nomes[j + 1]) > 0) {
                strcpy(auxNome, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], auxNome);

                auxIdade = idades[j]; idades[j] = idades[j + 1]; idades[j + 1] = auxIdade;
                auxId = ids[j]; ids[j] = ids[j + 1]; ids[j + 1] = auxId;

                /* Troca so os ponteiros das linhas: os valores continuam juntos */
                auxLinha = valores[j]; valores[j] = valores[j + 1]; valores[j + 1] = auxLinha;
            }
        }
    }
}

/* 5) Procura os dois primeiros valores nao negativos. Retorna 1 se achou. */
int calcularDiagonal(double **valores, int qtdValores, double *diagonal) {
    double lados[2];
    int encontrados = 0, i, j;

    for (i = 0; i < QTD && encontrados < 2; i++) {
        for (j = 0; j < qtdValores && encontrados < 2; j++) {
            if (valores[i][j] >= 0) {
                lados[encontrados] = valores[i][j];
                encontrados++;
            }
        }
    }

    if (encontrados < 2) return 0;

    printf("\nLados do retangulo: %.2f e %.2f\n", lados[0], lados[1]);
    *diagonal = sqrt(lados[0] * lados[0] + lados[1] * lados[1]);
    return 1;
}

void imprimirNomeComPontos(char *nome) {
    int i, tamanho = strlen(nome);
    for (i = 0; i < tamanho; i++) {
        printf("%c", toupper((unsigned char) nome[i]));
    }
    printf(" ");
    for (i = tamanho; i < LARGURA; i++) {
        printf(".");
    }
    printf("... ");
}

int main() {
    char nomes[QTD][TAM_NOME];
    int idades[QTD];
    double ids[QTD], medias[QTD];
    double **valores;
    double diagonal = 0;
    int qtdValores, i, j, temDiagonal;

    /* 1) Cadastro */
    for (i = 0; i < QTD; i++) {
        printf("\nParticipante %d\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", nomes[i]);
        do {
            printf("Idade (1 a 120): ");
            scanf("%d", &idades[i]);
        } while (idades[i] < 1 || idades[i] > 120);
    }

    /* 2) Captura dos valores na matriz dinamica valores[participante][valor] */
    do {
        printf("\nQuantos valores serao registrados para cada participante? ");
        scanf("%d", &qtdValores);
    } while (qtdValores < 1);

    valores = (double **) malloc(QTD * sizeof(double *));
    if (valores == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    for (i = 0; i < QTD; i++) {
        valores[i] = (double *) malloc(qtdValores * sizeof(double));
        if (valores[i] == NULL) {
            printf("Erro ao alocar memoria.\n");
            return 1;
        }
        printf("\nValores de %s:\n", nomes[i]);
        for (j = 0; j < qtdValores; j++) {
            printf("Valor %d: ", j + 1);
            scanf("%lf", &valores[i][j]);
        }
    }

    /* IDs unicos */
    calcularIds(idades, ids, qtdValores);

    /* 5) Diagonal (antes de ordenar, para respeitar a ordem de digitacao) */
    temDiagonal = calcularDiagonal(valores, qtdValores, &diagonal);

    /* 3) Ordem alfabetica */
    ordenarParticipantes(nomes, idades, ids, valores);

    /* 4) Medias ponderadas */
    printf("\n%-20s %-6s %-25s %s\n", "Nome", "Idade", "ID", "Media ponderada");
    for (i = 0; i < QTD; i++) {
        medias[i] = mediaPonderada(valores[i], qtdValores);
        printf("%-20s %-6d %-25.0f %.2f\n", nomes[i], idades[i], ids[i], medias[i]);
    }

    if (temDiagonal) {
        printf("\nComprimento da diagonal: %.2f\n", diagonal);
    } else {
        printf("\nNao foi possivel calcular a diagonal: "
               "nao ha dois valores nao negativos.\n");
    }

    /* 6) e 7) Classificacao final */
    printf("\n========== CLASSIFICACAO FINAL ==========\n\n");
    for (i = 0; i < QTD; i++) {
        imprimirNomeComPontos(nomes[i]);
        if (!temDiagonal) {
            printf("SEM CLASSIFICACAO\n");
        } else if (fabs(medias[i] - diagonal) < TOLERANCIA) {
            printf("SOBRE A DIAGONAL\n");
        } else if (medias[i] > diagonal) {
            printf("ACIMA DA DIAGONAL\n");
        } else {
            printf("ABAIXO DA DIAGONAL\n");
        }
    }
    printf("\n=========================================\n");

    for (i = 0; i < QTD; i++) {
        free(valores[i]);
    }
    free(valores);

    return 0;
}
