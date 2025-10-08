#include <stdio.h>

int main()  {
    int numero;

    printf("Entre com um numero inteiro: ");
    scanf("%i", &numero);

    int resto_da_divisao_por_2 = numero % 2;
    int resto_da_divisao_por_2_eh_zero = resto_da_divisao_por_2 == 0;

    // if (numero % 2 == 0)  {
    if (resto_da_divisao_por_2_eh_zero)  {
        printf("O numero %i eh par!\n", numero);
    
    } else {
        printf("O numero %i eh impar!\n", numero);
    }

    // int resto_da_divisao_por_2_nao_eh_zero = !resto_da_divisao_por_2_eh_zero;

    // // if (numero % 2 != 0)  {
    // if (resto_da_divisao_por_2_nao_eh_zero) {
    //     printf("O numero %i eh impar!\n", numero);
    // }
    
    return 0;
}