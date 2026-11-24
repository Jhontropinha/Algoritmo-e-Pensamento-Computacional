/*
 * Aula 07 - Funcoes
 * Questao 07 - Media de tres notas e situacao do aluno (aprovado se media >= 7,0).
 */
#include <stdio.h>

float calcularMedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

void verificarSituacao(float media) {
    if (media >= 7.0) {
        printf("Situacao: APROVADO\n");
    } else {
        printf("Situacao: REPROVADO\n");
    }
}

int main() {
    float n1, n2, n3, media;

    printf("Digite a primeira nota: ");
    scanf("%f", &n1);
    printf("Digite a segunda nota: ");
    scanf("%f", &n2);
    printf("Digite a terceira nota: ");
    scanf("%f", &n3);

    media = calcularMedia(n1, n2, n3);
    printf("Media: %.2f\n", media);
    verificarSituacao(media);

    return 0;
}
