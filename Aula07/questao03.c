/*
 * Aula 07 - Funcoes
 * Questao 03 - Funcao que retorna o maior entre dois inteiros.
 * Se forem iguais, retorna qualquer um deles (no caso, o primeiro).
 */
#include <stdio.h>

int maiorNumero(int a, int b) {
    if (a >= b) {
        return a;
    }
    return b;
}

int main() {
    int n1, n2;

    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("Digite o segundo numero: ");
    scanf("%d", &n2);

    printf("O maior numero e: %d\n", maiorNumero(n1, n2));

    return 0;
}
