/*
 * Aula 09 - Registros e Arquivos
 * Atividade 3 - Atualizacao do saldo de um cliente no arquivo binario clientes.bin.
 *
 * Valor positivo = deposito; valor negativo = saque.
 * Se o arquivo clientes.bin ainda nao existir, o programa cria um com alguns
 * clientes de exemplo, apenas para que seja possivel testar a atualizacao.
 */
#include <stdio.h>

typedef struct {
    int conta_corrente;
    char nome[50];
    float saldo;
} Cliente;

void criarArquivoExemplo() {
    Cliente exemplos[3] = {
        {1001, "Ana Souza", 1500.00f},
        {1002, "Bruno Lima", 320.50f},
        {1003, "Carla Mendes", 7800.00f}
    };
    FILE *arquivo = fopen("clientes.bin", "wb");
    if (arquivo != NULL) {
        fwrite(exemplos, sizeof(Cliente), 3, arquivo);
        fclose(arquivo);
        printf("Arquivo clientes.bin nao existia: criado com 3 clientes de exemplo.\n\n");
    }
}

void listarClientes() {
    Cliente c;
    FILE *arquivo = fopen("clientes.bin", "rb");
    if (arquivo == NULL) return;

    printf("%-8s %-25s %12s\n", "Conta", "Nome", "Saldo");
    while (fread(&c, sizeof(Cliente), 1, arquivo) == 1) {
        printf("%-8d %-25s R$ %9.2f\n", c.conta_corrente, c.nome, c.saldo);
    }
    fclose(arquivo);
}

int main() {
    FILE *arquivo;
    Cliente cliente;
    int conta, encontrado = 0;
    float valor;

    /* b) Abre em modo leitura/escrita */
    arquivo = fopen("clientes.bin", "rb+");
    if (arquivo == NULL) {
        criarArquivoExemplo();
        arquivo = fopen("clientes.bin", "rb+");
        if (arquivo == NULL) {
            printf("Erro ao abrir clientes.bin\n");
            return 1;
        }
    }

    printf("Clientes cadastrados:\n");
    listarClientes();

    /* a) Dados da operacao */
    printf("\nNumero da conta corrente: ");
    scanf("%d", &conta);
    printf("Valor (positivo para deposito, negativo para saque): R$ ");
    scanf("%f", &valor);

    /* c) Le registro por registro */
    while (fread(&cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (cliente.conta_corrente == conta) {
            encontrado = 1;

            if (cliente.saldo + valor < 0) {
                printf("Saldo insuficiente. Saldo atual: R$ %.2f\n", cliente.saldo);
                break;
            }

            printf("\nSaldo anterior: R$ %.2f\n", cliente.saldo);
            cliente.saldo += valor;

            /* d) Volta exatamente um registro e sobrescreve */
            fseek(arquivo, -(long) sizeof(Cliente), SEEK_CUR);
            fwrite(&cliente, sizeof(Cliente), 1, arquivo);
            printf("Saldo atualizado: R$ %.2f\n", cliente.saldo);
            break;
        }
    }
    fclose(arquivo);

    if (!encontrado) {
        printf("Conta %d nao encontrada.\n", conta);
    }

    printf("\nSituacao atual do arquivo:\n");
    listarClientes();

    return 0;
}
