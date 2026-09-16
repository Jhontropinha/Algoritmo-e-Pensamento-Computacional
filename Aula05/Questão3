#include <stdio.h>

int main() {
    float nota;
    float soma = 0.0;
    float media;
    int i;

    // Leitura das notas dos 10 clientes
    for (i = 1; i <= 10; i++) {
        do {
            printf("Digite a nota do cliente %d (0 a 10): ", i);
            scanf("%f", &nota);

            // Verifica se a nota esta dentro do intervalo permitido
            if (nota < 0 || nota > 10) {
                printf("Nota invalida! Digite uma nota entre 0 e 10.\n");
            }

        } while (nota < 0 || nota > 10);

        // Soma a nota ao total
        soma += nota;
    }

    // Calcula a media das notas
    media = soma / 10;

    // Exibe a media geral
    printf("\n==============================\n");
    printf("Media geral do atendimento: %.2f\n", media);
    printf("==============================\n");

    // Verifica se a media esta abaixo de 7
    if (media < 7) {
        printf("ALERTA: A media de atendimento esta abaixo de 7!\n");
    } else {
        printf("A media de atendimento esta satisfatoria.\n");
    }

    return 0;
}
