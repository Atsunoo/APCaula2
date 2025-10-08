#include <stdio.h>
#include <locale.h>
int main()  {
    setlocale(LC_ALL, "");
    long long int populacao_mundial = 7800000000L;
    printf("População Mundial: %lli\n", populacao_mundial);
    const short int HORA_EM_SEGUNDOS = 3600;
    printf("1 hora corresponde a %i segundos.\n", HORA_EM_SEGUNDOS);
    long double precisao_extrema = 3.14159265358979323846L;
    printf("Precisão Extrema: %.20Lf\n", precisao_extrema);
    return 0;
}