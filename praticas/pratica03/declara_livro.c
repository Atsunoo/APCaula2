#include <stdio.h>
#include <locale.h>
int main()  {
    setlocale(LC_ALL, "");
    long long int ISBN = 9783161484100;
    int numero_de_paginas = 264;
    float preco_livro = 49.99f;
    int ano_de_publicacao = 2005;
    printf("ISBN: %lli\n", ISBN);
    printf("Número de Páginas: %i\n", numero_de_paginas);
    printf("Preço: %.2f\n", preco_livro);
    printf("Publicado em: %i\n", ano_de_publicacao);
    return 0;
}