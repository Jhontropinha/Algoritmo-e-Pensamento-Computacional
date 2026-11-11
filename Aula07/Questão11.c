/*
 * Aula 07 — Questão 11 — Notas de uma turma
 * Material da Profa. Joanacelle Caldas, página 28.
 *
 * Armazene em um vetor as notas finais de 10 alunos. Implemente
 * calcularMediaTurma para retornar a média das notas, encontrarMaiorNota para
 * retornar a maior nota, contarAprovados para contar as notas maiores ou
 * iguais a 7,0, e exibirResultados para apresentar os resultados. As funções
 * de cálculo devem retornar os valores sem imprimi-los diretamente.
 */

#include <stdio.h>

double calcularMediaTurma(const double notas[], int quantidade) {
    double total = 0;
    for (int i = 0; i < quantidade; i++) {
        total += notas[i];
    }
    return total / quantidade;
}

double encontrarMaiorNota(const double notas[], int quantidade) {
    double maior = notas[0];
    for (int i = 1; i < quantidade; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    }
    return maior;
}

int contarAprovados(const double notas[], int quantidade) {
    int aprovados = 0;
    for (int i = 0; i < quantidade; i++) {
        if (notas[i] >= 7.0) {
            aprovados++;
        }
    }
    return aprovados;
}

void exibirResultados(double media, double maior, int aprovados) {
    printf("\nMedia da turma: %.2f\n", media);
    printf("Maior nota: %.2f\n", maior);
    printf("Alunos aprovados: %d\n", aprovados);
}

int main(void) {
    enum { ALUNOS = 10 };
    double notas[ALUNOS];

    for (int i = 0; i < ALUNOS; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        if (scanf("%lf", &notas[i]) != 1) {
            puts("Nota invalida.");
            return 1;
        }
    }

    double media = calcularMediaTurma(notas, ALUNOS);
    double maior = encontrarMaiorNota(notas, ALUNOS);
    int aprovados = contarAprovados(notas, ALUNOS);
    exibirResultados(media, maior, aprovados);
    return 0;
}
