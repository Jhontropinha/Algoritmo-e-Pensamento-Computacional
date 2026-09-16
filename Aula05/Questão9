#include <stdio.h>

int main() {
    int numero;

    int somaPositivos = 0;
    int somaNegativos = 0;

    int quantidadePositivos = 0;
    int quantidadeNegativos = 0;

    // Leitura continua ate o usuario digitar 0
    printf("Digite um numero inteiro (0 para encerrar): ");
    scanf("%d", &numero);

    while (numero != 0) {

        // Verifica se o numero e positivo
        if (numero > 0) {
            somaPositivos += numero;
            quantidadePositivos++;
        }

        // Verifica se o numero e negativo
        else {
            somaNegativos += numero;
            quantidadeNegativos++;
        }

        printf("Digite outro numero inteiro (0 para encerrar): ");
        scanf("%d", &numero);
    }

    // Exibe os resultados
    printf("\n============================\n");
    printf("RESULTADO FINAL\n");
    printf("============================\n");

    printf("Soma dos positivos: %d\n", somaPositivos);
    printf("Soma dos negativos: %d\n", somaNegativos);
    printf("Quantidade de positivos: %d\n", quantidadePositivos);
    printf("Quantidade de negativos: %d\n", quantidadeNegativos);

    return 0;
}
