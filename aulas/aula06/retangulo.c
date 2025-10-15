#include <stdio.h>

int main()  {
    int ladoA;
    int ladoB;

    printf("Entre com o valor do ladoA do retangulo: ");
    scanf("%i", &ladoA);

    printf("Entre com o valor do ladoB do retangulo: ");
    scanf("%i", &ladoB);

    // for (int i = 1; i <= ladoA; i++) {
    //     printf("*");
    // }

    printf("\n");

    for (int i = 1; i <= ladoA; i++) 
    {
        for (int j = 1; j <= ladoB; j++) 
        {
        if (i == 1 || i == ladoA) {  // desenha a primeira e ultima linha
            printf("-");
        }
        else if (j == 1 || j == ladoB)  //desenha a primeira e ultima linha 
        {
            printf("|");
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");
    }
    return 0;
}