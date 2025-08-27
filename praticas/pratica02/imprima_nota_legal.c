#include <stdio.h>

int main()  {
    printf("\n===============================\n");
    printf("      N O T A   L E G A L\n");
    printf("===============================\n");
    printf("Produto      Qtd     Valor unit\n");
    printf("%-12s %02i %14.2f\n", "Camiseta", 2, 39.99);
    printf("%-12s %02i %14.2f\n", "Calca", 1, 89.90);
    printf("%-12s %02i %14.2f\n", "Meia social", 3, 19.99);
    printf("===============================\n");
    printf("%-15s %14.2f\n", "Total:", 229.85);
    return 0;
}