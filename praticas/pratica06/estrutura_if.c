#include <stdio.h>

int main()  {
    int numero;
    int eh_um_numero = scanf("%i", &numero);

    if (eh_um_numero) {
        printf("Voce digitou o numero: %d\n", numero);
    }

    int numero_eh_divisivel_por_2 = numero % 2 == 0;
    if (numero_eh_divisivel_por_2) {
        printf("O numero %i eh par!\n", numero);
    } else {
        printf("O numero %i eh impar!\n", numero);
    }

    if (numero < 0) {
        printf("O numero %i eh negativo!\n", numero);
    } else if (numero > 0) {
        printf("O numero %i eh positivo!\n", numero);
    } else {
        printf("O numero %i eh zero!\n", numero);
    }

    return 0;
}