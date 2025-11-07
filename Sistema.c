#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100
#define ARQUIVO "cadastro.txt"
void incluir_aluno() {
    FILE *fp = fopen(ARQUIVO, "a"); 
    if (fp == NULL) {
        printf("ERRO: Não foi possível abrir o arquivo para escrita.\n");
        return;
    }
    char nome[TAM_NOME];
    int idade;
    getchar();
    printf("Digite o nome do aluno: ");
    fgets(nome, TAM_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite a idade do aluno: ");
    scanf("%d", &idade);

    fprintf(fp, "%s, %d\n", nome, idade);
    fclose(fp);

    printf("\nAluno cadastrado com sucesso!\n");
}
void listar_alunos() {
    FILE *fp = fopen(ARQUIVO, "r");
    if (fp == NULL) {
        printf("\nNenhum cadastro encontrado (arquivo inexistente).\n");
        return;
    }

    char linha[200];
    printf("\n--- LISTA DE ALUNOS CADASTRADOS ---\n");

    while (fgets(linha, sizeof(linha), fp) != NULL) {
        printf("%s", linha);
    }

    printf("-----------------------------------\n");
    fclose(fp);
}
int main() {
    int opcao;

    do {
        printf("\n===== MENU DO SISTEMA =====\n");
        printf("1. Incluir novo aluno\n");
        printf("2. Listar alunos cadastrados\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                incluir_aluno();
                break;
            case 2:
                listar_alunos();
                break;
            case 3:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
