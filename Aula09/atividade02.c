/*
 * Aula 09 - Registros e Arquivos
 * Atividade 2 - Sistema de RH: malloc, memcpy e arquivo binario de backup.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char cargo[30];
    float salario;
} Funcionario;

int main() {
    Funcionario *original, *backup;
    Funcionario conferencia;
    FILE *arquivo;

    /* a) Aloca e preenche o registro original */
    original = (Funcionario *) malloc(sizeof(Funcionario));
    if (original == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("ID do funcionario: ");
    scanf("%d", &original->id);
    printf("Cargo: ");
    scanf(" %29[^\n]", original->cargo);
    printf("Salario: R$ ");
    scanf("%f", &original->salario);

    /* b) Aloca o buffer de backup */
    backup = (Funcionario *) malloc(sizeof(Funcionario));
    if (backup == NULL) {
        printf("Erro ao alocar memoria.\n");
        free(original);
        return 1;
    }

    /* c) Copia byte a byte o registro original para o backup */
    memcpy(backup, original, sizeof(Funcionario));

    /* d) Salva o conteudo do backup no arquivo binario */
    arquivo = fopen("backup_rh.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar backup_rh.bin\n");
        free(original);
        free(backup);
        return 1;
    }
    fwrite(backup, sizeof(Funcionario), 1, arquivo);
    fclose(arquivo);
    printf("\nBackup salvo em backup_rh.bin\n");

    /* Conferencia: le o arquivo para mostrar que o backup foi gravado corretamente */
    arquivo = fopen("backup_rh.bin", "rb");
    if (arquivo != NULL && fread(&conferencia, sizeof(Funcionario), 1, arquivo) == 1) {
        printf("\nConteudo do backup:\n");
        printf("ID: %d\nCargo: %s\nSalario: R$ %.2f\n",
               conferencia.id, conferencia.cargo, conferencia.salario);
    }
    if (arquivo != NULL) {
        fclose(arquivo);
    }

    free(original);
    free(backup);
    return 0;
}
