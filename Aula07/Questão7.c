/*
 * Aula 07 — Questão 7 — Média e situação do aluno
 * Material da Profa. Joanacelle Caldas, página 27.
 *
 * Crie a função calcularMedia, que recebe três notas e retorna a média
 * aritmética, e a função verificarSituacao, que recebe a média e exibe a
 * situação do aluno. Uma média de pelo menos 7,0 indica aprovação. Abaixo de
 * 7,0, o aluno está reprovado. Na main, leia as três notas, calcule a média e
 * apresente a situação.
 */

#include <stdio.h>

double calcularMedia(double nota1, double nota2, double nota3) {
    return (nota1 + nota2 + nota3) / 3;
}

void verificarSituacao(double media) {
    if (media >= 7.0) {
        puts("Situacao: Aprovado");
    } else {
        puts("Situacao: Reprovado");
    }
}

int main(void) {
    double nota1;
    double nota2;
    double nota3;

    printf("Digite as tres notas: ");
    if (scanf("%lf %lf %lf", &nota1, &nota2, &nota3) != 3) {
        puts("Nota invalida.");
        return 1;
    }

    double media = calcularMedia(nota1, nota2, nota3);
    printf("Media: %.2f\n", media);
    verificarSituacao(media);
    return 0;
}
