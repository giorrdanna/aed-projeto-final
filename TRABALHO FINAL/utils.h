//
// Created by felipe on 5/1/2021.
//

#ifndef PROJETOFINAL_UTILS_H
#define PROJETOFINAL_UTILS_H
#define FILELIVROS "arquivolivros.dat"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#endif //PROJETOFINAL_UTILS_H

//DESCRICAO A MOSTRAR PARA O MUNDO;
typedef struct livro {
    char *nome;
    char *genero;
    char *autor;
    char *editora;
    int codigo;
}Livro;

typedef struct aluno{
    char* nome;
    long int cpf;
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    long int numeroCelular;
}Aluno;

/*TODO
 * vericar por nome do livro disponibilidade;
bool verificarDisponibilidade();*/



void adicionarLivro();
void liberaListaDeLivros(Livro**);
void mostrarLivro(Livro *livro);
//void buscarLivroPorNome();


/*TODO
 * cadastrar um novo livro
 * Parametros (endereco do livro);
 * buscar dados com input do usuario;
entradaDeLivros(Livro*);
 */





