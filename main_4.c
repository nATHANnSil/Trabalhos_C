#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include <locale.h>

/**
Faça um sistema de cadastro de Alunos.O cadastro deve possuir pelo menos os seguintes campos:
Nome, matricula, nota1, nota2, nota3.
Deverá ter as seguintes opções:
1 –incluir
2 –alterar
3 –excluir ( logicamente) obs. Crie na estrutura um campo para dizer se o registro está excluído ou não!
4 –listar todos os alunos e suas respectivas notas
5 –Listar todas os alunos cuja média das notas seja acima de 6.
Autor: Nathan Gonçalves de Oliveira
**/

struct Tcadastro
{
    char nome[30];
    char matricula[6];
    float nota_1;
    float nota_2;
    float nota_3;
    float media;
};

typedef struct Tcadastro aluno;

int main()
{
    FILE *f;
    char op;
    setlocale(LC_ALL,"portuguese");
    if((f = fopen("teste.txt", "r+b"))==NULL)
    {
        printf("Criando arquivo...");
        if((f = fopen("teste.txt", "w+b"))==NULL)
        {
            printf("Erro na criação do arquivo!");
            exit(1);
        }
        system("pause");
    }
    do
    {
        printf("Escolha a questão que deseja:\n");
        printf("a- Incluir aluno\n");
        printf("b- Alterar Aluno\n");
        printf("c- Excluir Aluno\n");
        printf("d- Listar Alunos\n");
        printf("e- Listar Alunos com média maior que 6\n");
        printf("f-sair do sistema\n");
        op=getch();
        switch (op)
        {
        case 'a':
            printf("Incluir aluno\n");
            inserir(f);
            break;
        case 'b':
            printf("Alterar aluno\n");
            alterar (f);
            break;
        case 'c':
            printf("Excluir Alunos\n");
            excluir(f);
            system("pause");
            break;
        case 'd':
            printf("Listar Alunos\n");
            mostrar(f);
            system("pause");
            break;
        case 'e':
            printf("Listar Alunos com média maior que 6\n");
            media(f);
            system("pause");
            break;
        }
    }
    while(op!='f');
    fclose(f);
    return 0;
}

int mostrar (FILE *f,int matricula)
{
    int posicao=-1,achou=0;
    aluno m;
    fseek(f,0,SEEK_SET);
    fread(&m, sizeof(m),1, f);
    while(!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao= posicao+1;
        if(m.matricula==matricula)
        {
            achou=1;
        }
        fread(&m, sizeof(m),1, f);
    }
    if(achou)
    {
        return posicao;
    }
    else
    {
        return-1;
    }
}

void inserir (FILE *f)
{
    aluno m;
    int posicao;
    int media;

    printf("Digite a matrícula do aluno:\n");
    fflush(stdin);
    scanf("%d",&m.matricula);

    posicao=mostrar(f,m.matricula);
    if(posicao==-1) //não tinha codigono arquivo
    {
        printf("Digite o nome do aluno:\n");
        fflush(stdin);
        gets(m.nome);

        printf("Digite a nota 1 do aluno:\n:");
        fflush(stdin);
        scanf("%f",&m.nota_1);

        printf("Digite a nota 2 do aluno:\n");
        fflush(stdin);
        scanf("%f",&m.nota_2);

        printf("Digite a nota 3 do aluno:\n");
        fflush(stdin);
        scanf("%f",&m.nota_3);

        m.media==(m.nota_1+m.nota_2+m.nota_3/3);

        fseek(f,0,SEEK_END);// posicionado o arquivo no final
        fwrite(&m, sizeof(m),1,f);//gravando os dados
        fflush(f);
    }
    else
    {
        printf("Código %d já existe no arquivo. Inclusão não realizada!\n");
    }
}
void alterar(FILE *f)
{
    int matricula,posicao;
    aluno m;

    printf("Digite o código de matrícula do aluno que deseja alterar:\n");
    scanf("%d",&matricula);

    posicao=mostrar(f,matricula);
    if(posicao!=-1) // localizou a mercadoria
    {
        fseek(f,sizeof(m)*(posicao),SEEK_SET);
        fread(&m, sizeof(m),1, f);

        printf("Matrícula atual: %d \n Nome atual: %c\n Nota 1: %3.2f Nota 2: %3.2f Nota 3: %3.2f ",m.matricula,m.nome,m.nota_1,m.nota_2,m.nota_3);
        printf("Digite o novo nome do aluno:\n");
        fflush(stdin);
        gets(m.nome);

        printf("Digite a nova nota 1:\n");
        scanf("%f",&m.nota_1);

        printf("Digite a nova nota 1:\n");
        scanf("%f",&m.nota_2);

        printf("Digite a nova nota 1:\n");
        scanf("%f",&m.nota_3);

        fseek(f,sizeof(m)*(posicao),SEEK_SET);
        fwrite(&m, sizeof(m),1, f);
        fflush(f);
    }
}

void excluir(FILE *f)
{
    int matricula,posicao,nome,nota_1,nota_2,nota_3,media;
    aluno m;

    printf("Digite o código de matrícula do aluno que deseja excluir:\n");
    scanf("%d",&matricula);

    posicao=mostrar(f,matricula);
    if(posicao!=-1) // localizou a mercadoria
    {
        fseek(f,sizeof(m)*(posicao),SEEK_SET);
        fread(&m, sizeof(m),1, f);

        printf("Matrícula atual: %d \n Nome atual: %c\n Nota 1: %3.2f Nota 2: %3.2f Nota 3: %3.2f ",m.matricula,m.nome,m.nota_1,m.nota_2,m.nota_3);

        matricula=NULL;
        nome=NULL;
        nota_1=NULL;
        nota_2=NULL;
        nota_3=NULL;
        media=NULL;

        printf ("Registro apagado!");

        fseek(f,sizeof(m)*(posicao),SEEK_SET);
        fwrite(&m, sizeof(m),1, f);
        fflush(f);
    }
}

void media (FILE *f)
{
    aluno m;
    int posicao;
    int media;

    if (m.media>6)
    {
        posicao=mostrar(f,m.matricula);
        if(posicao!=-1) // localizou a mercadoria
        {
            fseek(f,sizeof(m)*(posicao),SEEK_SET);
            fread(&m, sizeof(m),1, f);

            printf("Matrícula atual: %d \n Nome atual: %c\n Nota 1: %3.2f Nota 2: %3.2f Nota 3: %3.2f Média: %3.2f",m.matricula,m.nome,m.nota_1,m.nota_2,m.nota_3,m.media);

        }

    }
}
