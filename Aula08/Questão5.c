/*
 * Aula 08 — Questão 5 — Participantes e diagonal do retângulo
 * Material da Profa. Joanacelle Caldas, páginas 26–27.
 *
 * 1. Cadastre o nome e a idade de quatro participantes. Calcule o ID de cada
 *    um pelo fatorial da idade dividido por 2. Em caso de duplicidade, use o
 *    fatorial da metade da idade elevado à quantidade de valores capturados.
 *    Repita o cálculo se a duplicidade persistir.
 * 2. Leia a quantidade de valores por participante e armazene os dados em uma
 *    matriz. Cada linha pertence a um participante e pode conter valores
 *    positivos, negativos ou zero.
 * 3. Organize os participantes em ordem alfabética, mantendo os IDs e os
 *    valores associados à pessoa correta.
 * 4. Crie uma função para calcular a média ponderada de cada participante, com
 *    pesos 1, 2, 3, … na ordem de entrada.
 * 5. Use os dois primeiros valores não negativos digitados como lados de um
 *    retângulo. Calcule a diagonal pelo Teorema de Pitágoras. Se houver menos
 *    de dois valores não negativos, informe que a diagonal não pôde ser
 *    calculada.
 * 6. Classifique cada participante como acima, abaixo ou sobre a diagonal,
 *    conforme a comparação com sua média ponderada.
 * 7. Exiba os quatro nomes em ordem alfabética e suas classificações.
 *
 * A solução conserva o ID de quem já foi cadastrado e reduz a idade inteira
 * pela metade a cada nova tentativa. Quando o fatorial chega a 1 e o ID
 * continua ocupado, acrescenta um sufixo numérico para manter os
 * identificadores únicos. A classificação fica indisponível quando faltam
 * lados do retângulo.
 *
 * Ao compilar com GCC, use -lm para vincular a biblioteca matemática.
 */

#include <ctype.h>
#include <float.h>
#include <locale.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[80];
    int idade;
    long double baseId;
    int sufixoId;
    double *valores;
} Participante;

static long double fatorial(int numero) {
    long double resultado = 1;
    for (int fator = 2; fator <= numero; fator++) {
        if (resultado > LDBL_MAX / fator) {
            return HUGE_VALL;
        }
        resultado *= fator;
    }
    return resultado;
}

static int idOcupado(const Participante participantes[], int indice) {
    for (int i = 0; i < indice; i++) {
        if (participantes[i].baseId == participantes[indice].baseId &&
            participantes[i].sufixoId == participantes[indice].sufixoId) {
            return 1;
        }
    }
    return 0;
}

static int definirId(Participante participantes[], int indice, int quantidade) {
    Participante *participante = &participantes[indice];
    int idade = participante->idade;
    participante->baseId = fatorial(idade) / 2;
    if (!isfinite(participante->baseId)) {
        return 0;
    }

    if (idOcupado(participantes, indice)) {
        do {
            idade /= 2;
            participante->baseId = powl(fatorial(idade), quantidade);
        } while (idade > 1 &&
                 (!isfinite(participante->baseId) || idOcupado(participantes, indice)));

        // Com 0! ou 1!, reduzir a idade nao gera outra base para o ID.
        while (idOcupado(participantes, indice)) {
            participante->sufixoId++;
        }
    }
    return 1;
}

static long double calcularMediaPonderada(const double valores[], int quantidade) {
    long double soma = 0;
    long double somaPesos = 0;

    for (int i = 0; i < quantidade; i++) {
        long double peso = i + 1;
        soma += valores[i] * peso;
        somaPesos += peso;
    }
    return soma / somaPesos;
}

static void copiarEmMinusculas(char destino[], const char origem[]) {
    int i = 0;
    for (; origem[i] != '\0'; i++) {
        destino[i] = (char)tolower((unsigned char)origem[i]);
    }
    destino[i] = '\0';
}

static int compararParticipantes(const void *primeiro, const void *segundo) {
    const Participante *participante1 = primeiro;
    const Participante *participante2 = segundo;
    char nome1[80];
    char nome2[80];
    copiarEmMinusculas(nome1, participante1->nome);
    copiarEmMinusculas(nome2, participante2->nome);
    return strcoll(nome1, nome2);
}

static const char *classificar(long double media, long double diagonal) {
    // Compensa o arredondamento na leitura e nos calculos com decimais.
    long double tolerancia = 8 * DBL_EPSILON * fmaxl(fabsl(media), diagonal);
    if (fabsl(media - diagonal) <= tolerancia) {
        return "Sobre a diagonal";
    }
    if (media > diagonal) {
        return "Acima da diagonal";
    }
    return "Abaixo da diagonal";
}

int main(void) {
    enum { PARTICIPANTES = 4 };
    Participante participantes[PARTICIPANTES] = {0};
    int quantidade;
    double lados[2];
    int quantidadeLados = 0;

    setlocale(LC_COLLATE, "");
    setlocale(LC_CTYPE, "");

    for (int i = 0; i < PARTICIPANTES; i++) {
        printf("Digite o nome do participante %d: ", i + 1);
        if (scanf(" %79[^\n]", participantes[i].nome) != 1) {
            puts("Nome invalido.");
            return 1;
        }
        printf("Digite a idade: ");
        if (scanf("%d", &participantes[i].idade) != 1 || participantes[i].idade < 0) {
            puts("Idade invalida.");
            return 1;
        }
    }

    printf("Digite a quantidade de valores por participante: ");
    if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
        puts("Quantidade invalida.");
        return 1;
    }

    for (int i = 0; i < PARTICIPANTES; i++) {
        if (!definirId(participantes, i, quantidade)) {
            puts("O fatorial da idade ultrapassa o limite numerico do ID.");
            return 1;
        }
    }

    if ((size_t)quantidade > SIZE_MAX / sizeof(double) / PARTICIPANTES) {
        puts("Quantidade de valores muito grande.");
        return 1;
    }
    double *matriz = malloc(PARTICIPANTES * (size_t)quantidade * sizeof *matriz);
    if (matriz == NULL) {
        puts("Memoria insuficiente para a matriz.");
        return 1;
    }

    for (int i = 0; i < PARTICIPANTES; i++) {
        // Cada participante aponta para sua linha da matriz.
        participantes[i].valores = matriz + (size_t)i * (size_t)quantidade;
        printf("\nValores de %s\n", participantes[i].nome);
        for (int j = 0; j < quantidade; j++) {
            double valor;
            printf("Digite o valor %d: ", j + 1);
            if (scanf("%lf", &valor) != 1 || !isfinite(valor)) {
                puts("Valor invalido.");
                free(matriz);
                return 1;
            }
            participantes[i].valores[j] = valor;
            if (quantidadeLados < 2 && valor >= 0) {
                lados[quantidadeLados++] = valor;
            }
        }
    }

    qsort(participantes, PARTICIPANTES, sizeof *participantes, compararParticipantes);

    puts("\nClassificacao final");
    if (quantidadeLados < 2) {
        puts("Nao foi possivel calcular a diagonal.");
        for (int i = 0; i < PARTICIPANTES; i++) {
            printf("%s - Sem classificacao\n", participantes[i].nome);
        }
    } else {
        long double diagonal = hypotl(lados[0], lados[1]);
        for (int i = 0; i < PARTICIPANTES; i++) {
            long double media = calcularMediaPonderada(participantes[i].valores, quantidade);
            printf("%s - %s\n", participantes[i].nome, classificar(media, diagonal));
        }
    }

    free(matriz);
    return 0;
}
