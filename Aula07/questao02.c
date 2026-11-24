/*
 * Aula 07 - Funcoes
 * Questao 02 - Funcao que recebe um inteiro e retorna o seu dobro.
 */
#include <stdio.h>

int calcularDobro(int numero) {
    return numero * 2;
}

int main() {
    int numero, resultado;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    resultado = calcularDobro(numero);
    printf("O dobro de %d e %d\n", numero, resultado);

    return 0;
}
