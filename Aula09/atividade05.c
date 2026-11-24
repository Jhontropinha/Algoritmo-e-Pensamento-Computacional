/*
 * Aula 09 - Registros e Arquivos
 * Atividade 5 - Sistema eleitoral com struct aninhada, realloc e arquivo binario.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char titulo[12];
    int zona;
} Eleitor;

typedef struct {
    Eleitor eleitor;     /* struct aninhada */
    int numero_voto;
} Cedula;

/* a) Acrescenta um voto, aumentando o vetor com realloc. Retorna 1 se deu certo. */
int adicionarVoto(Cedula **lista, int *quantidade, Cedula nova) {
    Cedula *aux = (Cedula *) realloc(*lista, (*quantidade + 1) * sizeof(Cedula));
    if (aux == NULL) {
        return 0;
    }
    *lista = aux;
    (*lista)[*quantidade] = nova;
    (*quantidade)++;
    return 1;
}

/* b) Salva a lista completa no arquivo binario */
int salvarUrna(const char *nomeArquivo, Cedula *lista, int quantidade) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        return 0;
    }
    fwrite(lista, sizeof(Cedula), quantidade, arquivo);
    fclose(arquivo);
    return 1;
}

/* c) Recuperacao rapida: descobre o tamanho com fseek/ftell, aloca tudo de uma vez
   e le todos os registros diretamente para o bloco alocado. */
Cedula *recuperarUrna(const char *nomeArquivo, int *quantidade) {
    FILE *arquivo;
    long tamanho;
    Cedula *bloco;

    *quantidade = 0;
    arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        return NULL;
    }

    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    if (tamanho <= 0) {
        fclose(arquivo);
        return NULL;
    }

    bloco = (Cedula *) malloc(tamanho);
    if (bloco == NULL) {
        fclose(arquivo);
        return NULL;
    }

    *quantidade = fread(bloco, sizeof(Cedula), tamanho / sizeof(Cedula), arquivo);
    fclose(arquivo);
    return bloco;
}

int main() {
    Cedula *votos = NULL, *recuperados;
    Cedula nova;
    int quantidade = 0, qtdRecuperados, i, continuar;

    do {
        printf("\n--- Novo voto ---\n");
        printf("Titulo de eleitor (ate 11 caracteres): ");
        /* %*[^ \n] descarta o que passar de 11 caracteres (o campo tem 12 com o '\0') */
        scanf("%11s%*[^ \n]", nova.eleitor.titulo);
        printf("Zona: ");
        scanf("%d", &nova.eleitor.zona);
        printf("Numero do voto: ");
        scanf("%d", &nova.numero_voto);

        if (!adicionarVoto(&votos, &quantidade, nova)) {
            printf("Erro ao alocar memoria para o voto.\n");
            break;
        }
        printf("Voto registrado. Total na memoria: %d\n", quantidade);

        printf("Registrar outro voto? (1 - Sim / 0 - Nao): ");
        scanf("%d", &continuar);
    } while (continuar == 1);

    if (quantidade > 0 && salvarUrna("urnas.bin", votos, quantidade)) {
        printf("\n%d voto(s) salvo(s) em urnas.bin\n", quantidade);
    }
    free(votos);

    recuperados = recuperarUrna("urnas.bin", &qtdRecuperados);
    if (recuperados == NULL) {
        printf("Nao foi possivel recuperar os votos.\n");
        return 1;
    }

    printf("\n===== VOTOS RECUPERADOS DO ARQUIVO =====\n");
    printf("%-14s %-6s %s\n", "Titulo", "Zona", "Voto");
    for (i = 0; i < qtdRecuperados; i++) {
        printf("%-14s %-6d %d\n", recuperados[i].eleitor.titulo,
               recuperados[i].eleitor.zona, recuperados[i].numero_voto);
    }

    free(recuperados);
    return 0;
}
