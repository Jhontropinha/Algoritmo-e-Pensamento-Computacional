/*
 * Aula 08 — Questão 4 — Competição de Fibonacci
 * Material da Profa. Joanacelle Caldas, página 25.
 *
 * Cadastre o nome e um inteiro positivo de cada um de cinco apostadores. Crie
 * uma função para somar a quantidade indicada de termos da sequência de
 * Fibonacci, iniciando em 0, 1, 1, 2, …, e armazene os cinco resultados em um
 * vetor. Crie uma função para verificar a primalidade e distribua as
 * premiações na ordem abaixo.
 *
 * 1. Maior resultado primo.
 * 2. Maior resultado par entre os apostadores ainda sem prêmio.
 * 3. Maior resultado estritamente acima da média dos cinco resultados entre os
 *    apostadores ainda sem prêmio.
 *
 * Cada apostador pode ganhar uma vez. Uma colocação sem candidato elegível
 * fica sem vencedor. Ao final, exiba apenas os vencedores e suas colocações,
 * da primeira à terceira. Em caso de empate, a solução dá preferência a quem
 * foi cadastrado primeiro.
 */

#include <limits.h>
#include <stdio.h>

static int somarFibonacci(int termos, unsigned long long *resultado) {
    unsigned long long anterior = 0;
    unsigned long long atual = 1;
    unsigned long long soma = 0;

    // O primeiro termo e 0, ja incluido na soma inicial.
    for (int i = 1; i < termos; i++) {
        if (atual > ULLONG_MAX - soma) {
            return 0;
        }
        soma += atual;
        unsigned long long proximo = anterior + atual;
        anterior = atual;
        atual = proximo;
    }

    *resultado = soma;
    return 1;
}

static int ehPrimo(unsigned long long numero) {
    if (numero < 2) {
        return 0;
    }
    if (numero % 2 == 0) {
        return numero == 2;
    }
    for (unsigned long long divisor = 3; divisor <= numero / divisor; divisor += 2) {
        if (numero % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    enum { APOSTADORES = 5, PREMIOS = 3 };
    char nomes[APOSTADORES][80];
    unsigned long long resultados[APOSTADORES];
    int premiados[APOSTADORES] = {0};
    unsigned long long media = 0;
    unsigned long long restos = 0;

    for (int i = 0; i < APOSTADORES; i++) {
        int termos;

        printf("Digite o nome do apostador %d: ", i + 1);
        if (scanf(" %79[^\n]", nomes[i]) != 1) {
            puts("Nome invalido.");
            return 1;
        }
        printf("Digite a quantidade positiva de termos: ");
        if (scanf("%d", &termos) != 1 || termos <= 0) {
            puts("Quantidade invalida.");
            return 1;
        }
        if (!somarFibonacci(termos, &resultados[i])) {
            puts("A soma de Fibonacci ultrapassa o limite numerico.");
            return 1;
        }

        // Divide antes de somar para evitar estouro no total dos cinco resultados.
        media += resultados[i] / APOSTADORES;
        restos += resultados[i] % APOSTADORES;
    }
    // Para resultados inteiros, basta comparar com a parte inteira da media.
    media += restos / APOSTADORES;

    putchar('\n');
    for (int lugar = 1; lugar <= PREMIOS; lugar++) {
        int vencedor = -1;
        for (int i = 0; i < APOSTADORES; i++) {
            unsigned long long resultado = resultados[i];
            if (premiados[i] || (vencedor != -1 && resultado <= resultados[vencedor])) {
                continue;
            }
            if ((lugar == 1 && ehPrimo(resultado)) ||
                (lugar == 2 && resultado % 2 == 0) ||
                (lugar == 3 && resultado > media)) {
                vencedor = i;
            }
        }

        if (vencedor != -1) {
            premiados[vencedor] = 1;
            printf("%do lugar - %s\n", lugar, nomes[vencedor]);
        }
    }

    return 0;
}
