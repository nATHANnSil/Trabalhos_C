#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

/*Faça as funções para incluir, excluir, alterar e imprimir dados de uma turma de X alunos*/


typedef struct Aluno
{
    int codigo;
    char nome[200];
    float nota;
    char aluno_cod.codigo;
} Aluno;

 Aluno aluno_especial;

void menu();
void inicializar();
void imprimir();
void cadastrar();

int main()
{
    setlocale(LC_ALL,"portuguese");
    menu();
    return 0;
}

void menu()
{
    int opcao;
    do
    {
        printf(" \n Opções: ");
        printf(" \n 1. Inicializar a Estrutura" );
        printf(" \n 2. Imprimir a Estrutura" );
        printf(" \n 3. Cadastrar Aluno Especial" );
        printf(" \n 4. Para sair. \n " );
        printf(" \n Digite a opção desejada: ");
        scanf("%d%*c", &opcao);
        switch(opcao)
        {
            case 1:
                inicializar();
            break;
            case 2:
                imprimir();
            break;
            case 3:
                cadastrar();
            break;
            default:
                 printf(" \n Opção não existente. ");
            break;
        }
    }
    while(opcao!=4);
}

void inicializar()
{
    aluno_cod.codigo = 0;
    strcpy(aluno_nom.nome, "NULL");
   aluno_no.nota = 0.0;
}

void cadastrar()
{
    printf(" Digite o código do aluno: ");
    scanf("%d", &aluno_cod.codigo);
    printf(" Digite o nome do aluno: ");
    scanf("%s", &aluno_nom.nome);
    printf(" Digite a nota do aluno: ");
    scanf("%f", &aluno_especial.nota);
}

void imprimir()
{
    printf(" \n O código do aluno é: %d ", aluno_cod.codigo);
    printf(" \n O nome do aluno é: %s ", aluno_nom.nome);
    printf(" \n A nota do aluno é: %.2f ",aluno_no.nota);
    p
