#include <stdio.h>

int main() {
    float consumo[5];
    float soma = 0.0;
    float media;
    int i;

    // Leitura do consumo dos 5 moradores
    for (i = 0; i < 5; i++) {
        printf("Digite o consumo de agua do morador %d (em m3): ", i + 1);
        scanf("%f", &consumo[i]);

        // Soma dos consumos para calcular a media geral
        soma += consumo[i];

        // Verifica se o consumo esta dentro ou acima da media
        if (consumo[i] <= 20) {
            printf("Morador %d: consumo dentro da media.\n", i + 1);
        } else {
            printf("Morador %d: consumo acima da media.\n", i + 1);
        }
    }

    // Calcula o consumo medio geral
    media = soma / 5;

    printf("\nConsumo medio geral: %.2f m3\n", media);

    return 0;
}
