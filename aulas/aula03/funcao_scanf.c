#include <stdio.h>
#include <locale.h>

int main()  {
    setlocale(LC_ALL, "");
    // 1) Tipos de dados
    // char - caracter
    // int - inteiro
    // float - flutuante até 6 casas
    // double - flutuante até 12 casas
    // void - sem tipo

    // 2) Variáveis e constantes
    int idade = 19;
    char tecla = 'n';
    float nota = 8.5f;
    const double PI = 3.1415169226;

    printf("Os valores das variáveis:\n");
    printf("idade = %i\n", idade);
    printf("tecla = %c\n", tecla);
    printf("nota = %.2f\n", nota);
    printf("pi = %.12f\n", PI);

    printf("\nInforme os novos valores:\n");
    scanf("%i", &idade);
    getchar(); // Ler uma tecla limpa \n
    scanf("%c", &tecla);
    getchar(); // Ler uma tecla limpa \n
    scanf("%f", &nota);
    // scanf("%f", pi); Não pode!!

    printf("Os NOVOS valores são:\n");
    printf("idade = %i\n", idade);
    printf("tecla = %c\n", tecla);
    printf("nota = %.2f\n", nota);


    return 0;
}