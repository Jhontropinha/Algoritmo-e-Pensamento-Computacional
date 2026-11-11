/*
 * Aula 07 — Questão 6 — Calculadora
 * Material da Profa. Joanacelle Caldas, página 26.
 *
 * Implemente uma função para cada operação básica (adição, subtração,
 * multiplicação e divisão). Cada função recebe dois números e retorna o
 * resultado. Leia dois números e uma opção de operação, chame a função
 * correspondente e exiba o resultado. Antes de dividir, verifique se o divisor
 * é diferente de zero.
 */

#include <stdio.h>

double somar(double primeiro, double segundo) {
    return primeiro + segundo;
}

double subtrair(double primeiro, double segundo) {
    return primeiro - segundo;
}

double multiplicar(double primeiro, double segundo) {
    return primeiro * segundo;
}

double dividir(double primeiro, double segundo) {
    return primeiro / segundo;
}

int main(void) {
    double primeiro;
    double segundo;
    double resultado;
    char operacao;

    printf("Digite dois numeros: ");
    if (scanf("%lf %lf", &primeiro, &segundo) != 2) {
        puts("Entrada invalida.");
        return 1;
    }

    printf("Digite a operacao (+, -, *, /): ");
    if (scanf(" %c", &operacao) != 1) {
        puts("Operacao invalida.");
        return 1;
    }

    switch (operacao) {
        case '+':
            resultado = somar(primeiro, segundo);
            break;
        case '-':
            resultado = subtrair(primeiro, segundo);
            break;
        case '*':
            resultado = multiplicar(primeiro, segundo);
            break;
        case '/':
            if (segundo == 0) {
                puts("Divisao por zero.");
                return 1;
            }
            resultado = dividir(primeiro, segundo);
            break;
        default:
            puts("Operacao invalida.");
            return 1;
    }

    printf("Resultado: %.2f\n", resultado);
    return 0;
}
