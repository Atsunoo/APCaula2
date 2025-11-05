#include <stdio.h>

int main () {
    int nota;
    printf("Insira um numero: ");
    scanf("%i", &nota);

    while(nota < 1 || nota > 10) {
        printf("Nota invalida, tente novamente.\n");
        scanf("%i", &nota);
    }
    return 0;
}