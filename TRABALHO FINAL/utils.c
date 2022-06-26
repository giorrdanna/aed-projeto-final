//
// Created by felipe on 5/1/2021.
//
#include "utils.h"

void copyBuffer(char **atributo,char *buffer);
void lancaExcecao(int quantidade);
bool naoExisteLivro(Livro *livro);
bool verificaID(int id);
Livro * novaLista(int quantidadeDeLivros);
Livro* criaListaDeLivros(int);


Livro *criaListaDeLivros(int quantidadeDeLivros) {
    Livro *lista = novaLista(quantidadeDeLivros);
    if (naoExisteLivro(lista)) {
        lancaExcecao(quantidadeDeLivros);
        return NULL;
    }
    printf("Aloquei %d livro(s)\n", quantidadeDeLivros);

    return lista;
}

Livro *novaLista(int quantidadeDeLivros) {
    Livro *livro = (Livro *) malloc(sizeof(Livro) * quantidadeDeLivros);
    return livro;
}

bool naoExisteLivro(Livro *livro) {
    if (!livro) {
        return true;
    }
    return false;

}

void liberaListaDeLivros(Livro **l) {
    free(*l);
}

void lancaExcecao(int quantidade) {

    fprintf(stderr, "Erro de alocacao com %d livros\n", quantidade);
}


void adicionarLivro() {
    int quantidadeDeLivrosNaLista;
    int index;
    int tamanho;
    Livro *lista = NULL;
    FILE *file;
    file = fopen(FILELIVROS, "ab");

    printf("Quantos livros deseja cadastrar?\n");
    scanf("%d", &quantidadeDeLivrosNaLista);
    lista = criaListaDeLivros(quantidadeDeLivrosNaLista);

    for (index = 0; index < quantidadeDeLivrosNaLista; index++) {
        char BUFFER[1000];
        char BUFFER2[1000];

        fflush(stdin);

        printf("Digite o nome do livro:\n");
        scanf(" %[^\n]", BUFFER);
        copyBuffer(&lista[index].nome,BUFFER);


        printf("Digite o genero do livro:\n"); //
        scanf(" %[^\n]", BUFFER);
        copyBuffer(&lista[index].genero,BUFFER);



        printf("Digite o autor do livro:\n");
        scanf(" %[^\n]", BUFFER);
        copyBuffer(&lista[index].autor,BUFFER);


        printf("Digite a editora do livro:\n");
        tamanho = scanf(" %[^\n]", BUFFER);
        copyBuffer(&lista[index].editora,BUFFER);

        printf("Digite o codigo do livro:\n");
        scanf("%d", &lista[index].codigo);

        mostrarLivro(&lista[index]);
        fwrite(&lista[index], sizeof(lista[index]), 1, file);

        //liberar aqui?
    }

    liberaListaDeLivros(&lista);
    fclose(file);
    printf("Tecle alguma tecla para sair!\n");
    getch();

}


void copyBuffer(char **atributo, char *buffer) {
    *atributo = malloc(strlen(buffer) + 1);
    memcpy(*atributo, buffer, strlen(buffer) + 1);

}

void mostrarLivro(Livro *livro) {

    printf("\nNome: %s\n", livro->nome);
    printf("Genero: %s\n", livro->genero);
    printf("Editora: %s\n", livro->editora);
    printf("Autor: %s\n", livro->autor);
    printf("Codigo: %d\n\n", livro->codigo);

}
