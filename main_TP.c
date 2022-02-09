/** Locadora LocaMais **/
/** Grupo: Nathan Gonçalves de Oliveira **/
/** Trabalho Prático realizado para a disciplina Algoritmos e Estrutura de Dados I. Basicamente é um programa para uma locadora de veículos. **/

//INÍCIO PROGRAMA

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

//INÍCIO ESTRUTURA DE CADASTRO DE CLIENTES//

struct cli
{
    int CodCli[6]; //6 espaços para o código
    char NomCli[20];
    char EndCli[30];
    int TelCli[9]; //telefone celular sem DDD
};

typedef struct cli cliente;

//FIM ESTRUTURA DE CADASTRO DE CLIENTES//

//INÍCIO ESTRUTURA DE CADASTRO DE FUNCIONÁRIOS//

struct func
{
    int CodFun[6]; //6 espaços para o código
    char NomFun[20];
    int TelFun[9]; //telefone celular sem DDD
    char CarFun[10];
    float SalFun;
};

typedef struct func funcionario;

//FIM ESTRUTURA DE CADASTRO DE FUNCIONÁRIOS//

//INÍCIO ESTRUTURA DE CADASTRO DE LOCAÇÃO//

struct loca
{
    int CodLoc[6]; //6 espaços para o código
    int dia_de_retirada_locacao;
    int mes_de_retirada_locacao;
    int ano_de_retirada_locacao;

    int dia_de_entrega_locacao;
    int mes_de_entrega_locacao;
    int ano_de_entrega_locacao;

    int seguro;
    float preco_sem_seguro;
    float preco_com_seguro;
    int DiaLoc;
};

typedef struct loca locacao;

//FIM ESTRUTURA DE CADASTRO DE LOCAÇÃO//

//INÍCIO ESTRUTURA DE CADASTRO DE VEÍCULO//

struct veic
{
    int CodVei[6]; //6 espaços para o código
    char DesVei[20];//20 espacos para descrição do veículo
    char ModVei[10];//Modelo do veículo
    char CorVei[8];
    char PlaVei[7]; //placa antiga e não as novas do Mercosul
    float val_diaria_veiculo;
    int OcuVei;//Ocupantes do veículo
    int StaVei; //Status do veículo

};

typedef struct veic veiculo;
//FIM ESTRUTURA DE CADASTRO DE VEÍCULO//

//INÍCIO MENU//

int main()
{
    FILE *f;
    char op;

    setlocale(LC_ALL,"portuguese");

    if((f = fopen("LocaMais.txt", "r+b"))==NULL)
    {
        printf("Criando arquivo...");
        if((f = fopen("LocaMais.txt", "w+b"))==NULL)
        {
            printf("Erro na criação do arquivo!");
            exit(1);
        }
        system("pause");
    }
    do
    {
        printf("--------------------------------------------------------------------------------\n");
        printf("                              BEM VINDO À LOCADORA LOCAMAIS\n");
        printf("--------------------------------------------------------------------------------\n");
        printf("                         Unidade: Aeroporto Internacional de Confins/MG \n");
        printf("--------------------------------------------------------------------------------\n");
        printf("Escolha a opção que deseja:\n");
        printf("a - CLIENTES\n");
        printf("b - FUNCIONÁRIOS\n");
        printf("c - LOCAÇÕES\n");
        printf("d - VEÍCULOS\n");
        printf("e - SAIR DO SISTEMA\n");
        op=getch();
        switch (op)
        {
        case 'a':
            printf("CLIENTES\n");
            clientes(f);
            break;
        case 'b':
            printf("FUNCIONÁRIOS\n");
            funcionarios(f);
            break;
        case 'c':
            printf("LOCAÇÕES\n");
            locacoes(f);
            system("pause");
            break;
        case 'd':
            printf("VEÍCULOS\n");
            automoveis(f);
            system("pause");
            break;
        }
    }
    while(op!='e');
    fclose(f);
    return 0;
}

//FIM MENU
//INÍCIO CLIENTES
int clientes ()
{
    int escolha=0;

    printf("--------------------------------------------------------------------------------\n");
    printf("                                  BEM VINDO AO SISTEMA DE CLIENTES\n");
    printf("--------------------------------------------------------------------------------\n");

    printf("  Digite o número referente a opção desejada:\n");
    printf("  1- Cadastrar Cliente\n");
    printf("  2- Alterar Cliente\n");
    printf("  3- Consultar Clientes\n");

    printf("Opção:");
    scanf("%i", &escolha);
    fflush(stdin);

    switch(escolha)
    {
    case 1:
        cadastro_clientes();
        break;
    case 2:
        altera_clientes();
        break;
    case 3:
        relatorio_clientes();
        break;
    default:
        printf("Opção inválida, digite a opção novamente:\n ");
    }
}
int cadastro_clientes (FILE *f, int CodCli)
{

    cliente c;
    int posicao;

    printf("--------------------------------------------------------------------------------\n");
    printf ("                      CADASTRO DE CLIENTES \n");
    printf("--------------------------------------------------------------------------------\n");

    printf("Digite a matícula do cliente:\n");
    fflush(stdin);
    scanf ("%d",&c.CodCli);

    posicao=(c,c.CodCli);
    if(posicao==-1) //não tinha codigono arquivo
    {
        printf("Digite o nome do cliente:\n");
        fflush(stdin);
        fgets(c.NomCli,20,stdin);

        printf("Digite o endereço do cliente:\n");
        fflush(stdin);
        fgets(c.EndCli,30,stdin);

        printf("Digite o telefone do cliente\n");
        fflush(stdin);
        scanf("%d",&c.TelCli);

        fseek(f,0,SEEK_END);// posicionado o arquivo no final
        fwrite(&c, sizeof(c),1,f);//gravando os dados
        fflush(f);
    }
    else
    {
        printf("Código %d já existe no arquivo. Inclusão não realizada!\n");
    }


}
int altera_clientes (FILE *f, int CodCli)
{
    cliente c;
    int posicao,Cod_Cli;

    printf("--------------------------------------------------------------------------------\n");
    printf ("                      ALTERAÇÃO DE CLIENTES \n");
    printf("--------------------------------------------------------------------------------\n");

    printf("Digite o nome do cliente que deseja alterar:\n");
    fgets(c.NomCli,20,f);

    posicao=(f,Cod_Cli);
    if(posicao!=-1) // localizou a mercadoria
    {
        fseek(f,sizeof(c)*(posicao),SEEK_SET);
        fread(&c, sizeof(c),1, f);

        printf("Matrícula atual: %d \n Nome atual: %c\n Endereço atual: %c\n Telefone atual: %d",c.CodCli,c.NomCli,c.EndCli,c.TelCli);

        printf("Digite o novo nome do cliente:\n");
        fflush(stdin);
        fgets(c.NomCli,20,stdin);

        printf ("Digite o novo endereço do cliente:\n");
        fflush (stdin);
        fgets (c.EndCli,30,stdin);

        printf ("Digite o novo telefone do cliente:\n");
        fflush (stdin);
        scanf ("%d", &c.TelCli);

        fseek(f,sizeof(c)*(posicao),SEEK_SET);
        fwrite(&c, sizeof(c),1, f);
        fflush(f);
    }
}

int relatorio_clientes (FILE *f,int CodCli)
{
    int posicao=-1,achou=0;
    cliente c;

    fseek(f,0,SEEK_SET);
    fread(&c, sizeof(c),1, f);

    while(!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao= posicao+1;
        if(c.CodCli==CodCli)
        {
            achou=1;
        }
        fread(&c, sizeof(c),1, f);
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
//FIM CLIENTES
//INÍCIO FUNCIONÁRIOS
int funcionarios ()
{
    {
        int escolha=0;

        printf("--------------------------------------------------------------------------------\n");
        printf("                                  BEM VINDO AO SISTEMA DE FUNCIONÁRIOS\n");
        printf("--------------------------------------------------------------------------------\n");

        printf("  Digite o número referente a opção desejada:\n");
        printf("  1- Cadastrar Funcionário\n");
        printf("  2- Consultar Funcionário\n");

        printf("Opção:");
        scanf("%i", &escolha);
        fflush(stdin);

        switch(escolha)
        {
        case 1:
            cadastro_funcionarios();
            break;
        case 2:
            relatorio_funcionarios();
            break;
        default:
            printf("Opção inválida, digite a opção novamente:\n ");
        }
    }
}
int cadastro_funcionarios (FILE *f, int CodFun)
{
    funcionario u;
    int posicao;

    printf("--------------------------------------------------------------------------------\n");
    printf ("                      CADASTRO DE FUNCIONÁRIOS \n");
    printf("--------------------------------------------------------------------------------\n");

    printf("Digite a matícula do funcionário:\n");
    fflush(stdin);
    scanf ("%d",&u.CodFun);

    posicao=(u,u.CodFun);
    if(posicao==1) //não tinha codigono arquivo
    {
        printf("Digite o nome do funcionário:\n");
        fflush(stdin);
        fgets(u.NomFun,20,stdin);

        printf("Digite o cargo do funcionário:\n");
        fflush(stdin);
        fgets(u.CarFun,30,stdin);

        printf("Digite o telefone do funcionário\n");
        fflush(stdin);
        scanf("%d",&u.TelFun);

        printf("Digite o salário do funcionário\n");
        fflush(stdin);
        scanf("%f",&u.SalFun);

        fseek(f,0,SEEK_END);// posicionado o arquivo no final
        fwrite(&u, sizeof(u),1,f);//gravando os dados
        fflush(f);
    }
    else
    {
        printf("Código %d já existe no arquivo. Inclusão não realizada!\n");
    }
}

int relatorio_funcionarios (FILE *f, int CodFun)
{
    int posicao=-1,achou=0;
    funcionario u;

    fseek(f,0,SEEK_SET);
    fread(&u, sizeof(u),1, f);

    while(!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao= posicao+1;
        if(u.CodFun==CodFun)
        {
            achou=1;
        }
        fread(&u, sizeof(u),1, f);
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
//FIM FUNCIONARIOS
//INÍCIO AUTOMÓVEIS
int automoveis ()
{
    int escolha=0;

    printf("--------------------------------------------------------------------------------\n");
    printf("                                  BEM VINDO AO SISTEMA DE VEÍCULOS\n");
    printf("--------------------------------------------------------------------------------\n");

    printf("  Digite o número referente a opção desejada:\n");
    printf("  1- Cadastrar Veículo\n");
    printf("  2- Consultar Veículos\n");

    printf("Opção:");
    scanf("%i", &escolha);
    fflush(stdin);

    switch(escolha)
    {
    case 1:
        cadastro_veiculo();
        break;
    case 2:
        consulta_veiculo();
        break;
    default:
        printf("Opção inválida, digite a opção novamente:\n ");
    }
}
int cadastro_veiculo (FILE *f, int CodVei)
{
    veiculo v;
    int posicao;

    printf("--------------------------------------------------------------------------------\n");
    printf ("                      CADASTRO DE VEÍCULOS \n");
    printf("--------------------------------------------------------------------------------\n");

    printf("Digite a matícula do veiculo:\n");
    fflush(stdin);
    scanf ("%d",&v.CodVei);

    posicao=(v,v.CodVei);
    if(posicao==-1) //não tinha codigono arquivo
    {
        printf("Digite o modelo do veículo:\n");
        fflush(stdin);
        fgets(v.ModVei,10,stdin);

        printf("Digite a descrição do veículo:\n");
        fflush(stdin);
        fgets(v.DesVei,20,stdin);

        printf ("Digite a cor do veículo:\n");
        fflush(stdin);
        fgets(v.CorVei,8,stdin);

        printf ("Digite a placa do veículo:\n");
        fflush(stdin);
        fgets(v.PlaVei,7,stdin);

        printf ("Digite o valor da diária deste veículo:\n");
        fflush(stdin);
        scanf("%d",&v.val_diaria_veiculo);

        printf ("Digite a quantidade dos ocupantes desse veículo:\n");
        fflush(stdin);
        scanf("%d",&v.OcuVei);

        fseek(f,0,SEEK_END);// posicionado o arquivo no final
        fwrite(&v, sizeof(v),1,f);//gravando os dados
        fflush(f);
    }
    else
    {
        printf("Código %d já existe no arquivo. Inclusão não realizada!\n");
    }


}

int consulta_veiculo (FILE *f, int CodVei)
{
    int posicao=-1,achou=0;
    veiculo v;

    fseek(f,0,SEEK_SET);
    fread(&v, sizeof(v),1, f);

    while(!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao= posicao+1;
        if(v.CodVei==CodVei)
        {
            achou=1;
        }
        fread(&v, sizeof(v),1, f);
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
//FIM AUTOMÓVEIS

//INÍCIO LOCAÇÕES
int locacoes ()
{
    int escolha=0;

    printf("--------------------------------------------------------------------------------\n");
    printf("                                  BEM VINDO AO SISTEMA DE LOCAÇÕES\n");
    printf("--------------------------------------------------------------------------------\n");

    printf("  Digite o número referente a opção desejada:\n");
    printf("  1- Cadastrar Locação\n");
    printf("  2- Consultar Locação\n");

    printf("Opção:");
    scanf("%i", &escolha);
    fflush(stdin);

    switch(escolha)
    {
    case 1:
        cadastro_locacao();
        break;
    case 2:
        relatorio_locacao();
        break;

    default:
        printf("Opção inválida, digite a opção novamente:\n ");
    }
}
int cadastro_locacao (FILE *f, int CodLoc)
{
    locacao l;
    cliente c;
    veiculo v;
    int posicao;
    int resp;

    printf("--------------------------------------------------------------------------------\n");
    printf ("                      CADASTRO DE LOCAÇÃO \n");
    printf("--------------------------------------------------------------------------------\n");

    printf("Digite a matícula da locação:\n");
    fflush(stdin);
    scanf ("%d",&l.CodLoc);

    posicao=(l,l.CodLoc);
    if(posicao==-1) //não tinha codigono arquivo
    {
        printf("Digite a matícula do cliente:\n");
        fflush(stdin);
        scanf ("%d",&c.CodCli);

        printf("Digite a matícula do veiculo:\n");
        fflush(stdin);
        scanf ("%d",&v.CodVei);

        {
            printf("Digite a data de retirada do veículo\n");
            scanf("%d",&l.dia_de_retirada_locacao);

            printf("Digite a data de entrega do veículo\n");
            scanf("%d",&l.dia_de_entrega_locacao);

            l.DiaLoc=l.dia_de_retirada_locacao-l.dia_de_entrega_locacao;

            printf("Os dias do veículo alugado será de: %d", l.DiaLoc);

            printf("O cliente deseja seguro?Digite 0 para SIM ou 1 NÃO\n");
            scanf("%d",&resp);

            if(resp==1)
            {
                printf("O preço do seguro é de R$50,00 por dia");
                l.preco_com_seguro=l.DiaLoc*(50+v.val_diaria_veiculo);
                printf ("O preço final é de R$ %f", l.preco_com_seguro);
            }

            else if(resp==0)
            {
                l.preco_sem_seguro=l.DiaLoc*(v.val_diaria_veiculo);
                printf("O preço final é de R$ %f", l.preco_sem_seguro);

            }

        }

        fseek(f,0,SEEK_END);// posicionado o arquivo no final
        fwrite(&c, sizeof(c),1,f);//gravando os dados
        fflush(f);

    }

}
int relatorio_locacao (FILE *f, int CodLoc)
{
    int posicao=-1,achou=0;
    locacao l;

    fseek(f,0,SEEK_SET);
    fread(&l, sizeof(l),1, f);

    while(!feof(f) && !achou)
    {
        posicao++; // semelhante a posicao= posicao+1;
        if(l.CodLoc==CodLoc)
        {
            achou=1;
        }
        fread(&l, sizeof(l),1, f);
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
//FIM LOCAÇÕES

//FIM PROGRAMA
