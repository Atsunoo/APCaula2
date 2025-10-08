#include <stdio.h>
#include <locale.h>
int main()  {
    setlocale(LC_ALL, "");
    long long int matricula_aluno = 20251927;
    int idade_aluno = 20;
    float altura_aluno = 1.80f;
    double peso_aluno = 83.4;
    const char sexo_masculino = 'M';
    printf("Matricula: %lli\n", matricula_aluno);
    printf("Idade: %i anos\n", idade_aluno);
    printf("Altura: %.2fm\n", altura_aluno);
    printf("Peso: %.1fkg\n", peso_aluno);
    printf("Sexo: %c\n", sexo_masculino);

    return 0;
}