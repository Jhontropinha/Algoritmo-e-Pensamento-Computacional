#include <stdio.h>

int main() {
    int numero;
    int pares = 0;
    int impares = 0;
    int i;

    // Leitura de 10 numeros inteiros
    for (i = 1; i <= 10; i++) {
        printf("Digite o %d numero inteiro: ", i);
        scanf("%d", &numero);

        // Verifica se o numero e par ou impar
        if (numero % 2 == 0) {
            printf("%d e par.\n", numero);
            pares++;
        } else {
            printf("%d e impar.\n", numero);
            impares++;
        }
    }

    // Apresenta os resultados finais
    printf("\n============================\n");
    printf("Quantidade de numeros pares: %d\n", pares);
    printf("Quantidade de numeros impares: %d\n", impares);
    printf("============================\n");

    return 0;
}
