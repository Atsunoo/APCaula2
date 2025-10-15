#include <stdio.h>

int main ()  {
    // Até de 100.00 se aplica 1%; de 100.01 a 500.00 se aplica 5%; acima dos 500.00 aplica 10%

    float valor_bruto;

    printf("Entre com o valor da bruto: ");
    scanf("%f", &valor_bruto);

    float valor_desconto;

    if (valor_bruto <= 100.0f) {
        valor_desconto = valor_bruto * 0.01f;
    } else if (valor_bruto <= 500.0f) {
        valor_desconto = valor_bruto * 0.05f;
    } else {
        valor_desconto = valor_bruto * 0.1f;
    }

    printf("Seu valor foi de %7.2f com um desconto de %5.2f.\n", valor_bruto, valor_desconto);
    return 0;
}