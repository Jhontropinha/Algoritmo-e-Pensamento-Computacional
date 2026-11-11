/*
 * Aula 06 — Questão 1 — Nome e média de um aluno
 * Material da Profa. Joanacelle Caldas, página 14.
 *
 * Crie uma aplicação para ler o nome e a média de um aluno. Em seguida, exiba
 * os valores lidos.
 */

#include <stdio.h>

int main(void) {
    char nome[80];
    double media;

    printf("Digite o nome do aluno: ");
    if (scanf(" %79[^\n]", nome) != 1) {
        puts("Nome invalido.");
        return 1;
    }

    printf("Digite a media do aluno: ");
    if (scanf("%lf", &media) != 1) {
        puts("Media invalida.");
        return 1;
    }

    printf("\nAluno: %s\nMedia: %.2f\n", nome, media);
    return 0;
}
