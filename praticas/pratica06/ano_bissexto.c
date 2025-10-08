#include <stdio.h>

int main()  {
    int ano;
    printf("Entre com um ano: ");
    scanf("%i", &ano);
   int ano_multiplo_4_e_ano_nao_multiplo_100_ou_ano_multiplo_400 = ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0;


    if (ano_multiplo_4_e_ano_nao_multiplo_100_ou_ano_multiplo_400) {
        printf("O ano %d eh bissexto!\n", ano);
    } else {
        printf("O ano %d naum e bissexto!\n", ano);
    }
    return 0;
}