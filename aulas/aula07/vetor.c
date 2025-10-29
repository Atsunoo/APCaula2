#include <stdio.h>

int main() {

    int numeros[10]; // uma matriz com uma dimensao chamados de vetor 

    //numeros[0] = 1;
    //numeros[1] = 2;
    //numeros[2] = 3;
    //numeros[3] = 4;
    //numeros[4] = 5;
    //numeros[5] = 6;
    //numeros[6] = 7;
    //numeros[7] = 8;
    //numeros[8] = 9;
    //numeros[9] = 10;

    for(int i = 0; i < 10; i++){
        numeros[i] = i + 1;
    }

    for(int i= 0; i < 10; i++){
        printf("Entre com o %i numero: /n", i + 1);
        scanf("%i", &numeros[i]);
    }
    printf("Os numeros digitados foram: ");

    for(int i = 0; i < 10; i++) {
        if (i < 9){
            printf("%i, ", numeros[i]);
        }
        else{
            printf("%i", numeros[i]);
        }
    }

    return 0; 
}