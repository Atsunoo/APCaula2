#include <stdio.h>

int main () {
    char operacao;
    float numero1, numero2;

    printf("Digite a operacao desejada (+, -, * ou /): ");
    scanf("%c", &operacao); 
    printf("Digite dois numeros (separados por espaco): ");
    scanf("%f %f", &numero1, &numero2);
    

    if (operacao == '+') {
        printf("O resultado %.2f\n", numero1 + numero2);
    }
    else if (operacao == '-') {
        printf("O resultado %.2f\n", numero1 - numero2);
    }
    else if (operacao == '*') {
        printf("O resultado %.2f\n", numero1 * numero2);
    }
    else if (operacao == '/') {
        printf("O resultado %.2f\n", numero1 / numero2);
    }
    else {
        printf("Operacao invalida.\n");
    }

    return 0;
}