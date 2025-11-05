#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    float delta, x1, x2;

    printf("Digite os valores de a, b e c:\n");
    scanf("%d %d %d", &a, &b, &c);
    delta = b*b - 4*a*c;

    if (delta < 0) {
        printf("A equacao não tem raizes reais.\n");
    } else if (delta > 0) {
        float x1 = (-b + sqrt(delta)) / 2*a;
        float x2 = (-b - sqrt(delta)) / 2*a;

        printf("As raizes da equacao sao:\n");
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }
    return 0;
}