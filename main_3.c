#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void main()
{
    setlocale(LC_ALL, "portuguese");


    int escolha=1;

    while (escolha!=5)
    {

        printf("\n\n ----------------------- ");

        printf("\n 1 - Opcao 1 ");
        printf("\n 2 - Opcao 2 ");
        printf("\n 3 - Opcao 3 ");
        printf("\n 4 - Opcao 4 ");
        printf("\n 5 - Fechar Programa ");
        printf("\n\n Escolha uma opcão: ");
        scanf("%d",&escolha);

        switch (escolha)
        {

        case 1:
        {
            questao1 ();
            printf("\n\n Opcão escolhida: 1 ");

            break;
        }

        case 2:
        {
            questao2 ();
            printf("\n\n Opcão escolhida: 2 ");
            break;
        }

        case 3:
        {
            questao3 ();
            printf("\n\n Opcão escolhida: 3 ");
            break;
        }

        case 4:
        {
            questao4 ();
            printf("\n\n Opcão escolhida: 4 ");
            break;
        }

        }

        default:
        {

            if( escolha==7)
            {
                continue;
            }
            printf("\n\n Nenhuma opcão foi escolhida ");
            break;
        }

        }

    }

    if( escolha==5)
        printf("\n\n O Programa foi fechado");

    getch();

}
void questao1 ()
{
    /* a) - Gravar em um arquivo os 64 primeiros valores da série: 1 1 2 3 5 8 13 21 34 . . . */

    FILE * ex1 = fopen("ex1.txt","w");
    if( ex1 == NULL)
    {
        printf("Erro de abertura! \n");
        return 0;
    }

    unsigned long long a = 1;
    unsigned long long  b = 0;

    for(int i = 0; i < 64; i++)
    {
        unsigned long long aux = a + b;
        a = b;
        b = aux;
        printf("%4i%15llu\n", 1+i,aux);
        fprintf(ex1, "%15llu\n", aux);
    };
    printf ("\n Para consultar o arquivo com essa sequência de Fibonacci, abra o arquivo 'ex1' na pasta do programa \n ");
    fclose(ex1);
    return 0;
}

void questao2 ()
{
    /* b)-ler o arquivo letra a e armazenar os dados em uma matriz 8 x 8 imprima essa matriz na tela */

    {
        char buffer[128];
        FILE *ex1;
        if((ex1 = fopen("ex1.txt","r")) == NULL)
        {
            printf("Erro de abertura! \n");
        }
        else
        {
            fgets(buffer, 80, ex1);
            while(!feof(ex1))
            {
                printf("%s", buffer);
                fgets(buffer, 80, ex1);
            }
            fclose(ex1);
        }
        system("pause");

    }
    return 0;

}
void questao3 ()
{
    /*c)-ler o arquivo letra a e armazenar os dados em uma matriz 8 x 8 armazene essa matriz em um arquivo.*/

    {
        char buffer[128];
        FILE *ex1;
        if((ex1 = fopen("ex1.txt","r")) == NULL)
        {
            printf("Erro de abertura! \n");
        }
        else
        {
            fgets(buffer, 80, ex1);
            while(!feof(ex1))
            {
                printf("%s", buffer);
                fgets(buffer, 80, ex1);
            }
            fclose(ex1);
        }
        system("pause");

    }

    return 0;
}

void questao4 ()
{
    /*d)-ler o arquivo letra ae armazenar os valores pares em um arquivo e os impares em outro arquivo*/

    int i,j;
    char buffer[128];
    FILE *ex1;
    if((ex1 = fopen("ex1.txt","r")) == NULL)
    {
        printf("Erro de abertura! \n");
    }
    else
    {
        fgets(buffer, 80, ex1);
        while(!feof(ex1))
        {
            printf("%s", buffer);
            fgets(buffer, 80, ex1);
            if ex1%2==0{
            FILE * ex1 = fopen("pares.txt","w");
                fprintf(pares, "%15llu\n", aux);
                fclose(pares);
            }
            else ex1%2==0{
            FILE * ex1 = fopen("impares.txt","w");
                fprintf(impares, "%15llu\n", aux);
                fclose(impares);
            }
        }
        }
        fclose(ex1);
    }
    system("pause");

    return 0;

}
