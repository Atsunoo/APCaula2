#include <stdio.h>

int main()  {
    int idade;

    printf("informe sua idade: ");
    scanf("%i", &idade);

    if (idade < 16) {
        printf("Voce nao pode votar!\n");
    } else {
        if (idade < 18 || idade > 70) {
            printf("Voce pode votar!\n");
        } else {
            printf("Voce deve votar!\n");
        }
    }
    
    return 0;
}