/*
 * Aula 06 — Questão 4 — Matriz de notas e médias
 * Material da Profa. Joanacelle Caldas, páginas 25–26.
 *
 * Leia três notas de cada um de três alunos e calcule a média de cada aluno.
 * Armazene os dados em uma matriz bidimensional. As três primeiras colunas
 * devem conter as notas e a quarta deve conter a média. Ao final, exiba a
 * tabela.
 */

#include <stdio.h>

int main(void) {
    double notas[3][4];

    for (int aluno = 0; aluno < 3; aluno++) {
        double soma = 0;
        for (int nota = 0; nota < 3; nota++) {
            printf("Digite a nota %d do aluno %d: ", nota + 1, aluno + 1);
            if (scanf("%lf", &notas[aluno][nota]) != 1) {
                puts("Nota invalida.");
                return 1;
            }
            soma += notas[aluno][nota];
        }
        notas[aluno][3] = soma / 3;
    }

    puts("\n           Nota 1  Nota 2  Nota 3   Media");
    for (int aluno = 0; aluno < 3; aluno++) {
        printf("Aluno %d ", aluno + 1);
        for (int coluna = 0; coluna < 4; coluna++) {
            printf("%8.2f", notas[aluno][coluna]);
        }
        putchar('\n');
    }

    return 0;
}
