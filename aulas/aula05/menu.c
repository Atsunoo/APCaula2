#include <stdio.h>

int main()  {
    int opcao;

    printf("------------------------\n");
    printf("     MENU PRINCIPAL     \n");
    printf("------------------------\n");
    printf("   1-Consultar saldo\n");
    printf("   2-Fazer recarga\n");
    printf("   3-Ouvir recados\n");
    printf("   4-Ultima chamada\n");
    printf("   5-Encerrar chat\n");
    printf("------------------------\n");

    printf("Escolha uma opcao: ");
    scanf("%i", &opcao);

    switch(opcao) {
        case 1: printf("Seu saldo eh de R$ 10,00\n"); break;
        case 2: printf("Escolha um valor de recarga\n"); break;
        case 3: printf("Voce naum tem recados\n"); break;
        case 4: printf("A ultima chamada foi 99999-9999\n"); break;
        case 5: printf("Obrigado pelo seu contato\n"); break;
        default: printf("Opcao invalida. Tente novamente.\n"); break;
    }

    return 0;
}