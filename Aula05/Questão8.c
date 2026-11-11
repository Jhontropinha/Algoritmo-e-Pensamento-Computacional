#include <stdio.h>

int main() {
    int numero;
    int maior;
    int menor;
    int diferenca;
    int i;

    // Leitura do primeiro numero
    printf("Digite o 1 numero inteiro: ");
    scanf("%d", &numero);

    // O primeiro numero inicia como maior e menor
    maior = numero;
    menor = numero;

    // Leitura dos outros 9 numeros
    for (i = 2; i <= 10; i++) {
        printf("Digite o %d numero inteiro: ", i);
        scanf("%d", &numero);

        // Verifica se encontrou um numero maior
        if (numero > maior) {
            maior = numero;
        }

        // Verifica se encontrou um numero menor
        if (numero < menor) {
            menor = numero;
        }
    }

    // Calcula a diferenca entre o maior e o menor
    diferenca = maior - menor;

    // Exibe os resultados
    printf("\n============================\n");
    printf("Maior numero: %d\n", maior);
    printf("Menor numero: %d\n", menor);
    printf("Diferenca: %d\n", diferenca);
    printf("============================\n");

    return 0;
}
