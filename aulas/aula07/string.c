#include <stdio.h>
#include <string.h> // manipulacao de string

int main() {
    char nome[30] = "Jose"; // inicializar uma string

    printf("Seu nome: %s\n", nome);

    for (int i = 0; i < 30; i++)
    {
        nome[i] = 'A';
    }

    printf("Seu nome: %s\n", nome);

    nome[0] = 'J';
    nome[1] = 'o';
    nome[2] = 's';
    nome[3] = 'e';
    nome[4] = '\0';

    printf("Seu nome: %s\n", nome);

    // naum pode
    // nome = "Reginaldo";

    printf("Entre com seu nome completo: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Seu nome: %s\n", nome);

    // funcoes do string.h
    // preenche um string com um caracter
    memset(nome, 'A', sizeof(nome));
    printf("Seu nome: %s\n", nome);
    memset(nome, 'B', 10);
    nome[10] = '\0';
    printf("Seu nome: %s\n", nome);

    // copia uma string
    strcpy(nome, "Reginaldo");
    printf("Seu nome: %s\n", nome);

    // concatena duas strings
    strcat(nome, " Jose");
    printf("Seu nome: %s\n", nome);

    // tamanho da string
    printf("Seu nome tem %i caracteres", strlen(nome));

    // compara strings
    printf("As strings '%s' e '%s' são iguais? %i\n", nome, "Jose", strcmp(nome, "Jose"));
    printf("As strings '%s' e '%s' são iguais? %i\n", "Jose", nome, strcmp("Jose", nome));
    printf("As strings '%s' e '%s' são iguais? %i\n", "Reginaldo Jose", nome, strcmp("Reginaldo Jose", nome));

    // procurar um caracter em uma string
    printf("A string '%s' possui a letra 'o'? %i\n", nome, strchr(nome, 'o'));
    printf("A string '%s' possui a letra 'u'? %i\n", nome, strchr(nome, 'u'));

    // procurar uma string em uma string
    printf("A string '%s' possui a letra 'ose'? %s\n", nome, strstr(nome, "ose"));
    printf("A string '%s' possui a letra 'Silva'? %s\n", nome, strstr(nome, "Silva"));


    return 0;
}