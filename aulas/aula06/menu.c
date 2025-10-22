#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "");
    int opcao = 0;

    while (opcao != 3)
    {
        system("clear");
        printf("----------------------------------------\n");
        printf("               MEU     JOGO             \n");
        printf("----------------------------------------\n");
        printf("          1   -   Novo Jogo             \n");
        printf("          2   -   Ver  Ranking          \n");
        printf("          3   -   Sair                  \n");
        printf("----------------------------------------\n");
        printf("ESCOLHA UMA OPÇÃO => ");
        scanf("%i", &opcao);
        while (getchar() != '\n');
    
    switch (opcao)
    {
    case 1:
    {
        system("clear");
        char nome[30];
        printf("Entre com seu nome: ");
        fgets(nome, sizeof(nome), stdin);
        printf("Olá %s\n!", nome);
        printf("Pressione ENTER para começar o jogo.\n");
    }
    break;
    case 2:
    {
    }
    break;

    case 3:
        printf("Até logo!\n");
        break;

    default:
        printf("Opção inválida! Tente novamente.\n");
        break;
    }
    }
    return 0;
}