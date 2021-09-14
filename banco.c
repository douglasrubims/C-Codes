#include <stdio.h>
#include <stdlib.h>

#define MAX_CLIENTES 15

typedef struct {
    char nome[50];
    int numero_conta;
    float saldo;
} Cliente;

typedef struct {
    Cliente clientes[MAX_CLIENTES];
    int numeroClientes;
} Banco;

void cadastrarCliente(Banco *banco) {
    Cliente cliente;
    printf("Digite o nome do cliente: ");
    scanf("%s", cliente.nome);
    printf("Digite o numero da conta: ");
    scanf("%d", &cliente.numero_conta);
    printf("Digite o saldo da conta: ");
    scanf("%f", &cliente.saldo);
    banco->clientes[banco->numeroClientes] = cliente;
    banco->numeroClientes++;
    printf("\n[+] Cliente cadastrado com sucesso!\n\n");
}

void consultarTodosClientes(Banco banco) {
    int i;
    printf("\n[+] Lista de clientes cadastrados:\n");
    for (i = 0; i < banco.numeroClientes; i++) printf("\nNome: %s\nNumero da conta: %d\nSaldo: %.2f\n\n", banco.clientes[i].nome, banco.clientes[i].numero_conta, banco.clientes[i].saldo);
}

void mostrarDadosMenorSaldo(Banco banco) {
    int i, menorSaldo = 0;
    for(i = 0; i < banco.numeroClientes; i++) if(banco.clientes[i].saldo < banco.clientes[menorSaldo].saldo) menorSaldo = i;
    printf("\n[+] Cliente com menor saldo:\n");
    printf("\nNome: %s\nNumero da conta: %d\nSaldo: %.2f\n\n", banco.clientes[menorSaldo].nome, banco.clientes[menorSaldo].numero_conta, banco.clientes[menorSaldo].saldo);
}

int main() {
    Banco banco;
    int opcao = -1;
    while(opcao != 0) {
        printf("++++++++++++++++++++++++++++++++++++++++++++++++\n\t\tBANCO CEFET\n\n1 - Cadastrar novo Cliente\n2 - Consultar todos os clientes\n3 - Mostrar dados do cliente com menor saldo em conta corrente\n4 - Sair\nOpcao>");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                printf("Cadastrar novo Cliente\n");
                if(banco.numeroClientes < MAX_CLIENTES) cadastrarCliente(&banco);
                else printf("\n[-] Nao foi possivel cadastrar o cliente, limite de clientes atingido!\n\n");
            break;
            case 2:
                printf("Consultar todos os clientes\n");
                consultarTodosClientes(banco);
            break;
            case 3:
                printf("Mostrar dados do cliente com menor saldo em conta corrente\n");
                mostrarDadosMenorSaldo(banco);
            break;
            case 4:
                printf("Sair\n");
                return 0;
            break;
            default:
                printf("Opcao invalida\n");
            break;
        }
    }
    return 0;
}