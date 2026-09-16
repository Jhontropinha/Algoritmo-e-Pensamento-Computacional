#include <stdio.h>

int main() {
    float nota1, nota2, nota3;
    float media;

    int aprovados = 0;
    int recuperacao = 0;
    int reprovados = 0;

    char continuar;

    do {
        printf("\n===== NOTAS DO ALUNO =====\n");

        // Leitura das tres notas
        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);

        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);

        printf("Digite a terceira nota: ");
        scanf("%f", &nota3);

        // Calculo da media
        media = (nota1 + nota2 + nota3) / 3;

        printf("Media do aluno: %.2f\n", media);

        // Verifica a situacao do aluno
        if (media >= 7) {
            printf("Situacao: APROVADO\n");
            aprovados++;
        } else if (media >= 5) {
            printf("Situacao: RECUPERACAO\n");
            recuperacao++;
        } else {
            printf("Situacao: REPROVADO\n");
            reprovados++;
        }

        // Pergunta se deseja continuar
        printf("\nDeseja cadastrar outro aluno? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    // Exibe o resultado final
    printf("\n=============================\n");
    printf("        RESULTADO FINAL\n");
    printf("=============================\n");
    printf("Alunos aprovados: %d\n", aprovados);
    printf("Alunos em recuperacao: %d\n", recuperacao);
    printf("Alunos reprovados: %d\n", reprovados);
    printf("=============================\n");

    return 0;
}
