/*
 * Aula 07 - Funcoes
 * Questao 06 - Calculadora com uma funcao para cada operacao basica.
 */
#include <stdio.h>

float somar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    return a / b;
}

int main() {
    float n1, n2;
    int opcao;

    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);

    printf("\nEscolha a operacao:\n");
    printf("1 - Adicao\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("%.2f + %.2f = %.2f\n", n1, n2, somar(n1, n2));
            break;
        case 2:
            printf("%.2f - %.2f = %.2f\n", n1, n2, subtrair(n1, n2));
            break;
        case 3:
            printf("%.2f x %.2f = %.2f\n", n1, n2, multiplicar(n1, n2));
            break;
        case 4:
            /* Verifica o divisor antes de chamar a funcao */
            if (n2 != 0) {
                printf("%.2f / %.2f = %.2f\n", n1, n2, dividir(n1, n2));
            } else {
                printf("Erro: nao e possivel dividir por zero.\n");
            }
            break;
        default:
            printf("Opcao invalida.\n");
    }

    return 0;
}
