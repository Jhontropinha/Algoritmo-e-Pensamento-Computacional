/*
 * Aula 07 — Questão 1 — Saudação
 * Material da Profa. Joanacelle Caldas, página 26.
 *
 * Crie a função mostrarSaudacao() para exibir a mensagem “Bem-vindo ao mundo
 * das funções em C!”. Chame a função três vezes na main.
 */

#include <stdio.h>

void mostrarSaudacao(void) {
    puts("Bem-vindo ao mundo das funções em C!");
}

int main(void) {
    for (int i = 0; i < 3; i++) {
        mostrarSaudacao();
    }

    return 0;
}
