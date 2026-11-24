/*
 * Aula 09 - Registros e Arquivos
 * Atividade 4 - Gravacao de uma lista inteira de professores com um unico fwrite().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int registro;
    int horas_aula;
} Professor;

/* Le 'n' professores de uma vez so do arquivo para um novo array dinamico */
Professor *carregarFolha(const char *nomeArquivo, int n) {
    Professor *lista;
    FILE *arquivo = fopen(nomeArquivo, "rb");

    if (arquivo == NULL) {
        return NULL;
    }

    lista = (Professor *) malloc(n * sizeof(Professor));
    if (lista == NULL) {
        fclose(arquivo);
        return NULL;
    }

    if (fread(lista, sizeof(Professor), n, arquivo) != (size_t) n) {
        printf("Aviso: o arquivo tem menos registros do que o esperado.\n");
    }
    fclose(arquivo);
    return lista;
}

int main() {
    Professor *professores, *carregados;
    unsigned char *buffer;
    FILE *arquivo;
    int n, i;

    do {
        printf("Quantos professores deseja cadastrar? ");
        scanf("%d", &n);
    } while (n < 1);

    /* Array dinamico de N professores */
    professores = (Professor *) malloc(n * sizeof(Professor));
    if (professores == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nProfessor %d\n", i + 1);
        printf("Registro: ");
        scanf("%d", &professores[i].registro);
        printf("Horas-aula: ");
        scanf("%d", &professores[i].horas_aula);
    }

    /* Buffer bruto de bytes com N * sizeof(Professor) */
    buffer = (unsigned char *) malloc(n * sizeof(Professor));
    if (buffer == NULL) {
        printf("Erro ao alocar memoria.\n");
        free(professores);
        return 1;
    }

    /* Copia o array inteiro para o buffer */
    memcpy(buffer, professores, n * sizeof(Professor));

    /* Grava o buffer completo com uma unica chamada de fwrite() */
    arquivo = fopen("folha.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar folha.dat\n");
        free(professores);
        free(buffer);
        return 1;
    }
    fwrite(buffer, n * sizeof(Professor), 1, arquivo);
    fclose(arquivo);
    printf("\n%d professor(es) gravado(s) em folha.dat\n", n);

    /* Leitura de volta para um novo array */
    carregados = carregarFolha("folha.dat", n);
    if (carregados == NULL) {
        printf("Erro ao carregar folha.dat\n");
    } else {
        printf("\n===== FOLHA CARREGADA DO ARQUIVO =====\n");
        printf("%-12s %s\n", "Registro", "Horas-aula");
        for (i = 0; i < n; i++) {
            printf("%-12d %d\n", carregados[i].registro, carregados[i].horas_aula);
        }
        free(carregados);
    }

    free(professores);
    free(buffer);
    return 0;
}
