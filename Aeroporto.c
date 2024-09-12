#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX_VOOS 50
#define MAX_PASSAGEIROS 100
#define MAX_PASSAGENS 100

typedef struct {
    int id_voo;
    int numero_aeronave;
    char empresa[50];
    char origem[50];
    char destino[50];
    char data_partida[11];
    char horario_partida[6];
    int quantidade_passageiros;
} Voo;

typedef struct {
    int id_passageiro;
    char nome[50];
    char identidade[15];
    char endereco[100];
    char telefone[15];
    char sexo;
} Passageiro;

typedef struct {
    int numero_passagem;
    int id_passageiro;
    int id_voo;
    float valor;
    char data_venda[11];
} Passagem;

Voo voos[MAX_VOOS];
Passageiro passageiros[MAX_PASSAGEIROS];
Passagem passagens[MAX_PASSAGENS];

int total_voos = 0;
int total_passageiros = 0;
int total_passagens = 0;

void menu_principal();
void menu_voos();
void incluir_voo();
void alterar_voo();
void excluir_voo();
void consultar_voo();
void menu_passageiros();
void incluir_passageiro();
void alterar_passageiro();
void excluir_passageiro();
void consultar_passageiro();
void menu_passagens();
void incluir_passagem();
void alterar_passagem();
void excluir_passagem();
void consultar_passagem();
void menu_relatorios();
void relatorio_passagens_por_voo();
void relatorio_voos_por_empresa();
void lista_passageiros_por_voo();

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    do {
        menu_principal();
        scanf("%d", &opcao);
        switch (opcao) {
        case 1:
            menu_voos();
            break;
        case 2:
            menu_passagens();
            break;
        case 3:
            menu_passageiros();
            break;
        case 4:
            menu_relatorios();
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}

void menu_principal() {
    printf("\n1 – Vôos\n");
    printf("2 – Passagens\n");
    printf("3 – Passageiros\n");
    printf("4 – Relatórios\n");
    printf("5 – Sair\n");
    printf("Escolha uma opção: ");
}

void menu_voos() {
    int opcao;
    printf("\n1 – Incluir Vôo\n");
    printf("2 – Alterar Vôo\n");
    printf("3 – Excluir Vôo\n");
    printf("4 – Consultar Vôo\n");
    printf("5 – Voltar ao menu principal\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
        incluir_voo();
        break;
    case 2:
        alterar_voo();
        break;
    case 3:
        excluir_voo();
        break;
    case 4:
        consultar_voo();
        break;
    }
}

void incluir_voo() {
    if (total_voos < MAX_VOOS) {
        Voo novo_voo;
        novo_voo.id_voo = total_voos + 1;
        printf("Número da aeronave: ");
        scanf("%d", &novo_voo.numero_aeronave);
        printf("Empresa: ");
        scanf("%s", novo_voo.empresa);
        printf("Origem: ");
        scanf("%s", novo_voo.origem);
        printf("Destino: ");
        scanf("%s", novo_voo.destino);
        printf("Data da partida (dd/mm/aaaa): ");
        scanf("%s", novo_voo.data_partida);
        printf("Horário da partida (hh:mm): ");
        scanf("%s", novo_voo.horario_partida);
        printf("Quantidade de passageiros: ");
        scanf("%d", &novo_voo.quantidade_passageiros);
        voos[total_voos] = novo_voo;
        total_voos++;
        printf("Vôo incluído com sucesso!\n");
    } else {
        printf("Limite de vôos atingido.\n");
    }
}

void alterar_voo() {
    int id;
    printf("Informe o ID do vôo a alterar: ");
    scanf("%d", &id);
    for (int i = 0; i < total_voos; i++) {
        if (voos[i].id_voo == id) {
            printf("Novo destino: ");
            scanf("%s", voos[i].destino);
            printf("Vôo alterado com sucesso!\n");
            return;
        }
    }
    printf("Vôo não encontrado.\n");
}

void excluir_voo() {
    int id;
    printf("Informe o ID do vôo a excluir: ");
    scanf("%d", &id);
    for (int i = 0; i < total_voos; i++) {
        if (voos[i].id_voo == id) {
            printf("Vôo %d excluído: %s para %s\n", voos[i].id_voo, voos[i].origem, voos[i].destino);
            for (int j = i; j < total_voos - 1; j++) {
                voos[j] = voos[j + 1];
            }
            total_voos--;
            return;
        }
    }
    printf("Vôo não encontrado.\n");
}

void consultar_voo() {
    int id;
    printf("Informe o ID do vôo: ");
    scanf("%d", &id);
    for (int i = 0; i < total_voos; i++) {
        if (voos[i].id_voo == id) {
            printf("Vôo %d: %s para %s, Partida: %s %s\n", voos[i].id_voo, voos[i].origem, voos[i].destino, voos[i].data_partida, voos[i].horario_partida);
            return;
        }
    }
    printf("Vôo não encontrado.\n");
}

void menu_passageiros() {
    int opcao;
    printf("\n1 – Incluir Passageiro\n");
    printf("2 – Alterar Passageiro\n");
    printf("3 – Excluir Passageiro\n");
    printf("4 – Consultar Passageiro\n");
    printf("5 – Voltar ao menu principal\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
        incluir_passageiro();
        break;
    case 2:
        alterar_passageiro();
        break;
    case 3:
        excluir_passageiro();
        break;
    case 4:
        consultar_passageiro();
        break;
    }
}

void incluir_passageiro() {
    if (total_passageiros < MAX_PASSAGEIROS) {
        Passageiro novo_passageiro;
        novo_passageiro.id_passageiro = total_passageiros + 1;
        printf("Nome: ");
        scanf("%s", novo_passageiro.nome);
        printf("Identidade: ");
        scanf("%s", novo_passageiro.identidade);
        printf("Endereço: ");
        scanf("%s", novo_passageiro.endereco);
        printf("Telefone: ");
        scanf("%s", novo_passageiro.telefone);
        printf("Sexo (M/F): ");
        scanf(" %c", &novo_passageiro.sexo);
        passageiros[total_passageiros] = novo_passageiro;
        total_passageiros++;
        printf("Passageiro incluído com sucesso!\n");
    } else {
        printf("Limite de passageiros atingido.\n");
    }
}

void alterar_passageiro() {
    int id;
    printf("Informe o ID do passageiro a alterar: ");
    scanf("%d", &id);
    for (int i = 0; i < total_passageiros; i++) {
        if (passageiros[i].id_passageiro == id) {
            printf("Novo telefone: ");
            scanf("%s", passageiros[i].telefone);
            printf("Passageiro alterado com sucesso!\n");
            return;
        }
    }
    printf("Passageiro não encontrado.\n");
}

void excluir_passageiro() {
    int id;
    printf("Informe o ID do passageiro a excluir: ");
    scanf("%d", &id);
    for (int i = 0; i < total_passageiros; i++) {
        if (passageiros[i].id_passageiro == id) {
            printf("Passageiro %d excluído: %s\n", passageiros[i].id_passageiro, passageiros[i].nome);
            for (int j = i; j < total_passageiros - 1; j++) {
                passageiros[j] = passageiros[j + 1];
            }
            total_passageiros--;
            return;
        }
    }
    printf("Passageiro não encontrado.\n");
}

void consultar_passageiro() {
    int id;
    printf("Informe o ID do passageiro: ");
    scanf("%d", &id);
    for (int i = 0; i < total_passageiros; i++) {
        if (passageiros[i].id_passageiro == id) {
            printf("Passageiro %d: %s, Identidade: %s, Endereço: %s, Telefone: %s\n", passageiros[i].id_passageiro, passageiros[i].nome, passageiros[i].identidade, passageiros[i].endereco, passageiros[i].telefone);
            return;
        }
    }
    printf("Passageiro não encontrado.\n");
}

void menu_passagens() {
    int opcao;
    printf("\n1 – Incluir Passagem\n");
    printf("2 – Alterar Passagem\n");
    printf("3 – Excluir Passagem\n");
    printf("4 – Consultar Passagem\n");
    printf("5 – Voltar ao menu principal\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
        incluir_passagem();
        break;
    case 2:
        alterar_passagem();
        break;
    case 3:
        excluir_passagem();
        break;
    case 4:
        consultar_passagem();
        break;
    }
}

void incluir_passagem() {
    if (total_passagens < MAX_PASSAGENS) {
        Passagem nova_passagem;
        nova_passagem.numero_passagem = total_passagens + 1;
        printf("ID do Passageiro: ");
        scanf("%d", &nova_passagem.id_passageiro);
        printf("ID do Vôo: ");
        scanf("%d", &nova_passagem.id_voo);
        printf("Valor da passagem: ");
        scanf("%f", &nova_passagem.valor);
        printf("Data da venda (dd/mm/aaaa): ");
        scanf("%s", nova_passagem.data_venda);
        passagens[total_passagens] = nova_passagem;
        total_passagens++;
        printf("Passagem incluída com sucesso!\n");
    } else {
        printf("Limite de passagens atingido.\n");
    }
}

void alterar_passagem() {
    int numero;
    printf("Informe o número da passagem a alterar: ");
    scanf("%d", &numero);
    for (int i = 0; i < total_passagens; i++) {
        if (passagens[i].numero_passagem == numero) {
            printf("Novo valor da passagem: ");
            scanf("%f", &passagens[i].valor);
            printf("Passagem alterada com sucesso!\n");
            return;
        }
    }
    printf("Passagem não encontrada.\n");
}

void excluir_passagem() {
    int numero;
    printf("Informe o número da passagem a excluir: ");
    scanf("%d", &numero);
    for (int i = 0; i < total_passagens; i++) {
        if (passagens[i].numero_passagem == numero) {
            printf("Passagem %d excluída.\n", passagens[i].numero_passagem);
            for (int j = i; j < total_passagens - 1; j++) {
                passagens[j] = passagens[j + 1];
            }
            total_passagens--;
            return;
        }
    }
    printf("Passagem não encontrada.\n");
}

void consultar_passagem() {
    int numero;
    printf("Informe o número da passagem: ");
    scanf("%d", &numero);
    for (int i = 0; i < total_passagens; i++) {
        if (passagens[i].numero_passagem == numero) {
            printf("Passagem %d: Passageiro %d, Vôo %d, Valor: %.2f, Data da venda: %s\n", passagens[i].numero_passagem, passagens[i].id_passageiro, passagens[i].id_voo, passagens[i].valor, passagens[i].data_venda);
            return;
        }
    }
    printf("Passagem não encontrada.\n");
}

void menu_relatorios() {
    int opcao;
    printf("\n1 – Quantidade de Passagens Vendidas por Vôo\n");
    printf("2 – Quantidade de Vôos por Empresa\n");
    printf("3 – Lista de Passageiros por Vôo\n");
    printf("4 – Voltar ao menu principal\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
        relatorio_passagens_por_voo();
        break;
    case 2:
        relatorio_voos_por_empresa();
        break;
    case 3:
        lista_passageiros_por_voo();
        break;
    }
}

void relatorio_passagens_por_voo() {
    for (int i = 0; i < total_voos; i++) {
        int quantidade = 0;
        for (int j = 0; j < total_passagens; j++) {
            if (passagens[j].id_voo == voos[i].id_voo) {
                quantidade++;
            }
        }
        printf("Vôo %d: %d passagens vendidas.\n", voos[i].id_voo, quantidade);
    }
}

void relatorio_voos_por_empresa() {
    char empresas[MAX_VOOS][50];
    int contador[MAX_VOOS] = {0};
    int total_empresas = 0;

    for (int i = 0; i < total_voos; i++) {
        int encontrou = 0;
        for (int j = 0; j < total_empresas; j++) {
            if (strcmp(voos[i].empresa, empresas[j]) == 0) {
                contador[j]++;
                encontrou = 1;
                break;
            }
        }
        if (!encontrou) {
            strcpy(empresas[total_empresas], voos[i].empresa);
            contador[total_empresas]++;
            total_empresas++;
        }
    }

    for (int i = 0; i < total_empresas; i++) {
        printf("Empresa %s: %d vôos.\n", empresas[i], contador[i]);
    }
}

void lista_passageiros_por_voo() {
    int id;
    printf("Informe o ID do vôo: ");
    scanf("%d", &id);
    printf("Passageiros do Vôo %d:\n", id);
    for (int i = 0; i < total_passagens; i++) {
        if (passagens[i].id_voo == id) {
            for (int j = 0; j < total_passageiros; j++) {
                if (passageiros[j].id_passageiro == passagens[i].id_passageiro) {
                    printf("%s\n", passageiros[j].nome);
                }
            }
        }
    }
}
