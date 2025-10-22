#include <stdio.h>
#include <locale.h>

int main ()  {
    setlocale(LC_ALL, "");
    int dia;
    printf("Entre com um numero de 1 a 7: ");
    scanf("%i", &dia);

    switch (dia) {
        case 1: printf("Domingo!\n", dia); break;
        case 2: printf("Segunda!\n", dia); break;
        case 3: printf("Terça!\n", dia); break;
        case 4: printf("Quarta!\n", dia); break;
        case 5: printf("Quinta!\n", dia); break;
        case 6: printf("Sexta!\n", dia); break;
        case 7: printf("Sábado!\n", dia); break;
        default: printf("Número inválido, burro.");
    }

    return 0;
}