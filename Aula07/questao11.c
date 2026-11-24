/*
 * Aula 07 - Funcoes
 * Questao 11 - Analise das notas finais de uma turma de 10 alunos.
 *
 * As funcoes de calculo apenas retornam valores; somente exibirResultados imprime.
 */
#include <stdio.h>

#define ALUNOS 10

float calcularMediaTurma(float notas[], int quantidade) {
    int i;
    float soma = 0;

    for (i = 0; i < quantidade; i++) {
        soma = soma + notas[i];
    }
    return soma / quantidade;
}

float encontrarMaiorNota(float notas[], int quantidade) {
    int i;
    float maior = notas[0];

    for (i = 1; i < quantidade; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    }
    return maior;
}

int contarAprovados(float notas[], int quantidade) {
    int i, aprovados = 0;

    for (i = 0; i < quantidade; i++) {
        if (notas[i] >= 7.0) {
            aprovados++;
        }
    }
    return aprovados;
}

void exibirResultados(float media, float maior, int aprovados, int totalAlunos) {
    printf("\n===== RESULTADOS DA TURMA =====\n");
    printf("Media da turma: %.2f\n", media);
    printf("Maior nota: %.2f\n", maior);
    printf("Alunos aprovados: %d\n", aprovados);
    printf("Alunos reprovados: %d\n", totalAlunos - aprovados);
}

int main() {
    float notas[ALUNOS];
    int i;

    for (i = 0; i < ALUNOS; i++) {
        do {
            printf("Nota final do aluno %d (0 a 10): ", i + 1);
            scanf("%f", &notas[i]);
            if (notas[i] < 0 || notas[i] > 10) {
                printf("Nota invalida. Digite um valor entre 0 e 10.\n");
            }
        } while (notas[i] < 0 || notas[i] > 10);
    }

    exibirResultados(calcularMediaTurma(notas, ALUNOS),
                     encontrarMaiorNota(notas, ALUNOS),
                     contarAprovados(notas, ALUNOS),
                     ALUNOS);

    return 0;
}
