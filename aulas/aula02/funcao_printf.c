#include <stdio.h>
#include <locale.h> // biblioteca de idiomas

int main() {
    setlocale(LC_ALL, ""); // usa o idioma portuguÃªs
    printf("-------------\n");
    printf("Olá, bom dia!\n");
    printf("-------------\n");

    printf("-------------------------\n");
    printf("  N O T A    L E G A L\n");
    printf("-------------------------\n");
    printf("Caderno    1   10.00\n");
    printf("Lápis      2   5.00\n");
    printf("Borracha   1   7.50\n");
    printf("-------------------------\n");
    printf("Total.......:  22.50\n");

    // Especificador de formato
    // %c  -  Imprime um caracter
    // %s  -  Imprime um texto (string)
    // %i  -  Imprime um inteiro
    // %f  -  Imprime um flutuante (Fracioario)

    printf("\nCaderno    001   10.00\n");
    printf("%-15s %03i   %.2f\n", "Caderno", 1, 10.0);
    printf("%-15s %03i   %5.2f\n", "Lápis", 2, 5.0);

    return 0;
}