#include <stdio.h>

int main ()  {  // > 40.0 muito quente. > 30.0 e < 40.0 quente. > 20.0 e < 30.0 agradável. < 20.0 frio.
    float temperatura;
    printf("Quantos graus ta fazendo na caminhada?\n");
    scanf("%f", &temperatura);

    if (temperatura > 40.0f) {
        printf("Ta pegando fogo bicho!\n");
    } else if (temperatura >= 30.0f && temperatura <= 40.0f) {
        printf("Ta quente...\n");
    } if (temperatura >= 20.0f && temperatura < 30.0f) {
        printf("Bem agradavel!\n");
    } if (temperatura < 20.0f) {
        printf("Ta um frio danado.\n");
    }

    return 0;
}