/*
 * Aula 06 — Questão 2 — Nome e média de 30 alunos
 * Material da Profa. Joanacelle Caldas, páginas 20–21.
 *
 * Crie uma aplicação que use vetores para ler o nome e a média de 30 alunos.
 * Em seguida, exiba a lista com os nomes e as médias.
 */

#include <stdio.h>

int main(void) {
    char nomes[30][80];
    double medias[30];

    for (int i = 0; i < 30; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        if (scanf(" %79[^\n]", nomes[i]) != 1) {
            puts("Nome invalido.");
            return 1;
        }

        printf("Digite a media do aluno %d: ", i + 1);
        if (scanf("%lf", &medias[i]) != 1) {
            puts("Media invalida.");
            return 1;
        }
    }

    puts("\nLista de alunos e medias");
    for (int i = 0; i < 30; i++) {
        printf("%d. %s - %.2f\n", i + 1, nomes[i], medias[i]);
    }

    return 0;
}
