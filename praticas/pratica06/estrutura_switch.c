#include <stdio.h>

int main()  {
    int nota;
    printf("Entre com uma nota de 1 a 5: ");
    scanf("%i", &nota);

    switch (nota) {
        case 1: printf("Voce ganhou '*'!\n", nota); break;
        case 2: printf("Voce ganhou '**'!\n", nota); break;
        case 3: printf("Voce ganhou '***'!\n", nota); break;
        case 4: printf("Voce ganhou '****'!\n", nota); break;
        case 5: printf("Voce ganhou '*****'!\n", nota); break;
        default: printf("Nota invalida! Tente novamente.\n");
    }

    return 0;
}