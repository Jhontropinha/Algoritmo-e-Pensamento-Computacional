/*
 * Aula 08 - Ponteiros e Vetores Dinamicos
 * Questao 03 - Numeros repetidos, primos e correspondencia com nomes de animais.
 *
 * Interpretacao seguida (de acordo com o exemplo de saida do enunciado):
 *  - Numero que aparece 1 vez ............................ "Nao repetido"
 *  - Repetido, primo e com quantidade impar de ocorrencias  "Primo - impar"
 *  - Repetido, primo e com quantidade par de ocorrencias .. "Primo - par"
 *  - Repetido, nao primo, quantidade par .................. "Par"
 *  - Repetido, nao primo, quantidade impar ................ "Impar"
 *
 *  b) Para cada numero "Primo - impar", soma-se a quantidade de ocorrencias dele
 *     e o usuario cadastra essa quantidade de nomes de animais.
 *     (No exemplo: 3 aparece 3x e 7 aparece 3x -> 3 + 3 = 6 animais cadastrados.)
 *  c) Para cada numero "Par", usa-se a posicao que ele ocupa no vetor
 *     (primeira ocorrencia, contando a partir de 1) como indice na lista de animais.
 *     Se nao houver animal naquela posicao: "Nao existe correspondencia".
 *  d) Ao final sao exibidos os animais correspondentes.
 *
 * Os nomes dos animais ficam num vetor dinamico de ponteiros (char **) que cresce
 * com realloc a medida que os nomes sao cadastrados.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 15
#define TAM_NOME 50

int ehPrimo(int n) {
    int d;
    if (n < 2) return 0;
    if (n % 2 == 0) return n == 2;
    for (d = 3; d * d <= n; d += 2) {
        if (n % d == 0) return 0;
    }
    return 1;
}

int buscar(int *vetor, int quantidade, int valor) {
    int i;
    for (i = 0; i < quantidade; i++) {
        if (vetor[i] == valor) return i;
    }
    return -1;
}

/* Define a classificacao do numero conforme as regras acima */
const char *classificar(int numero, int ocorrencias) {
    if (ocorrencias == 1) return "Nao repetido";
    if (ehPrimo(numero)) {
        if (ocorrencias % 2 != 0) return "Primo - impar";
        return "Primo - par";
    }
    if (ocorrencias % 2 == 0) return "Par";
    return "Impar";
}

int main() {
    int numeros[TAM];
    int *distintos, *ocorrencias, *primeiraPosicao;
    char **animais = NULL, **novo;
    int qtdDistintos = 0, qtdAnimais = 0, totalAnimais = 0;
    int i, j, pos, posicao, contadorSaida;

    printf("Digite 15 numeros inteiros:\n");
    for (i = 0; i < TAM; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    distintos = (int *) malloc(TAM * sizeof(int));
    ocorrencias = (int *) malloc(TAM * sizeof(int));
    primeiraPosicao = (int *) malloc(TAM * sizeof(int));
    if (distintos == NULL || ocorrencias == NULL || primeiraPosicao == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    /* a) Conta as ocorrencias e guarda a posicao da primeira aparicao */
    for (i = 0; i < TAM; i++) {
        pos = buscar(distintos, qtdDistintos, numeros[i]);
        if (pos == -1) {
            distintos[qtdDistintos] = numeros[i];
            ocorrencias[qtdDistintos] = 1;
            primeiraPosicao[qtdDistintos] = i + 1;
            qtdDistintos++;
        } else {
            ocorrencias[pos]++;
        }
    }

    printf("\n%-10s %-12s %s\n", "Numero", "Ocorrencias", "Classificacao");
    printf("------------------------------------------\n");
    for (i = 0; i < qtdDistintos; i++) {
        printf("%-10d %-12d %s\n", distintos[i], ocorrencias[i],
               classificar(distintos[i], ocorrencias[i]));
    }

    /* b) Cadastro dos animais para os numeros primos com ocorrencia impar */
    for (i = 0; i < qtdDistintos; i++) {
        if (strcmp(classificar(distintos[i], ocorrencias[i]), "Primo - impar") == 0) {
            totalAnimais += ocorrencias[i];
            printf("\nO numero %d e primo e apareceu %d vezes: cadastre %d animal(is).\n",
                   distintos[i], ocorrencias[i], ocorrencias[i]);

            for (j = 0; j < ocorrencias[i]; j++) {
                novo = (char **) realloc(animais, (qtdAnimais + 1) * sizeof(char *));
                if (novo == NULL) {
                    printf("Erro ao alocar memoria.\n");
                    return 1;
                }
                animais = novo;
                animais[qtdAnimais] = (char *) malloc(TAM_NOME * sizeof(char));
                printf("Nome do animal %d: ", qtdAnimais + 1);
                scanf(" %49[^\n]", animais[qtdAnimais]);
                qtdAnimais++;
            }
        }
    }

    printf("\nSoma das ocorrencias dos primos com quantidade impar: %d\n", totalAnimais);
    printf("\nAnimais cadastrados:\n");
    if (qtdAnimais == 0) {
        printf("   Nenhum animal cadastrado.\n");
    }
    for (i = 0; i < qtdAnimais; i++) {
        printf("   %d. %s\n", i + 1, animais[i]);
    }

    /* c) e d) Correspondencia dos numeros "Par" com a posicao no vetor */
    printf("\nSaida:\n");
    contadorSaida = 0;
    for (i = 0; i < qtdDistintos; i++) {
        if (strcmp(classificar(distintos[i], ocorrencias[i]), "Par") == 0) {
            contadorSaida++;
            posicao = primeiraPosicao[i];
            if (posicao <= qtdAnimais) {
                printf("%d. %s.\n", contadorSaida, animais[posicao - 1]);
            } else {
                printf("%d. Nao existe correspondencia.\n", contadorSaida);
            }
        }
    }
    if (contadorSaida == 0) {
        printf("Nenhum numero com quantidade par de ocorrencias para correspondencia.\n");
    }

    for (i = 0; i < qtdAnimais; i++) {
        free(animais[i]);
    }
    free(animais);
    free(distintos);
    free(ocorrencias);
    free(primeiraPosicao);

    return 0;
}
