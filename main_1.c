#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int ex01();
int ex02();
int ex03();
int ex04();
int ex05();
int ex06();
int ex07();
int ex08();
int ex09();
int ex10();


int main()
{
    setlocale(LC_ALL, "portuguese");
    int exercicio;
    printf(" 1- Exercicio 1 \n 2- Exercicio 2 \n 3- Exercicio 3 \n 4- Exercicio 4 \n 5- Exercicio 5 \n 6- Exercicio 6 \n 7- Exercicio 7 \n 8- Exercicio 8 \n 9- Exercicio 9 \n10- Exercicio 10");

    printf ("\nEscolha o exercício que deseja visualizar:\n");
    scanf("%d", &exercicio);
    switch(exercicio)
    {
    case 1:
        ex01();
        break;
    case 02:
        ex02();

        break;
    case 03:
        ex03();
        break;
    case 04:
        ex04();
        break;
    case 05:
        ex05();
        break;
    case 06:
        ex06();
        break;
    case 07:
        ex07();
        break;
    case 8:
        ex08();
        break;
    case 9:
        ex09();
        break;
    case 10:
        ex10();
        break;
    default:
        printf("Código inválido\n");

    }
}

int ex01()
{
    setlocale (LC_ALL, "portuguese");
    char palavra [50], primeirapalavralexic [50], ultimapalavralexic [50], maiorpalavra [50], menorpalavra [50];
    int i, menortam, maiortam, aux;
    fflush (stdin);


    printf("Digite algumas palavras. Para parar, escreva PARE:\n");
    gets (palavra);

    menortam=strlen(palavra);
    maiortam=strlen(palavra);
    strcpy (menorpalavra,palavra);
    strcpy (maiorpalavra,palavra);
    strcpy (ultimapalavralexic,palavra);
    strcpy (primeirapalavralexic,palavra);

    while (strcasecmp (palavra, "PARE") != 0)
    {
        aux=strlen(palavra);
        if (aux<menortam)
        {
            menortam=aux;
            strcpy(menorpalavra,palavra);
        }

        if (aux>maiortam)
        {
            maiortam=aux;
            strcpy (maiorpalavra,palavra);
        }

        if (strcasecmp (palavra,primeirapalavralexic) <0)
        {
            strcpy (primeirapalavralexic,palavra);
        }


        if (strcasecmp (palavra, ultimapalavralexic) >0)
        {
            strcpy (primeirapalavralexic,palavra);
        }


        printf("Escreva algumas palavras:\n");
        gets (palavra);

    }

    printf (" A maior palavra é %s e o seu tamanho é de %d letras\n", maiorpalavra,maiortam);
    printf (" A menor palavra é %s e o seu tamanho é de %d letras\n", menorpalavra,menortam);


    printf (" A primeira palavra lexicograficamente é %s \n", ultimapalavralexic,ultimapalavralexic);
    printf (" A última palavra lexicograficamente é %s \n", primeirapalavralexic,primeirapalavralexic);


    return 0;

}

/*
2 – Ler um string de no máximo 50 caracteres e contar quantas letras A essa palavra possui.
Autor: Nathan Gonçalves de Oliveira
*/

int ex02()
{
    setlocale (LC_ALL, "portuguese");
    char palavra[50];
    int i,aux;
    aux=0;

    printf("Escreva uma palavra ou frase de no máximo 50 caracteres: \n");
    gets(palavra);
    fflush (stdin);
    while (strcasecmp (palavra, "PARE") != 0){

    for(i=0; i<50; i++)
    {
        if(palavra[i] == 'a')
        {
            aux++;
        }

    }


    printf("A letra A apareceu %d vezes\n ",aux);

    printf("Escreva algumas palavras:\n");
        gets (palavra);
    }
    return 0;
}

/*
3 – Ler uma string de no máximo 50 caracteres e indicar quais as posições da letra A nessa palavra.
Autor: Nathan Gonçalves de Oliveira
*/

int ex03()
{
    setlocale (LC_ALL, "portuguese");
    char palavra[50];
    int i,posicao;
    posicao=0;

    printf("Escreva uma palavra ou frase de no máximo 50 caracteres: \n");
    gets(palavra);
    fflush (stdin);
    while (strcasecmp (palavra, "PARE") != 0){



    printf ("A palavra %s possui a letra A na\n", palavra);
    for(i=0; i<= strlen(palavra); i++)
    {
        if(palavra[i] == 'a')
        {
            i++;
            posicao=i;
            printf ("posição %d\n", posicao);
        }
    }
    printf("Escreva algumas palavras:\n");
        gets (palavra);
    }

    return 0;
}

/*
4 – Ler uma string de no máximo 50 caracteres e em seguida um caractere, mostrar quais as posições esse caractere
aparece na string lida e quantas vezes ele apareceu.
Autor: Nathan Gonçalves de Oliveira
*/

int ex04()
{
    setlocale (LC_ALL, "portuguese");
    char palavra[50], letra;
    int i,posicao,aux,i2;
    posicao=0;
    i=0;
    aux=0;

    printf("Escreva uma palavra ou frase de no máximo 50 caracteres: \n");
    gets(palavra);
    fflush (stdin);

    printf("Escreva um caractere para ser encontrado na palava:\n");
    scanf ("%c", &letra);
    while (strcasecmp (palavra, "PARE") != 0){

    for(i=0; i<= strlen(palavra); i++)
    {
        if(palavra[i] == letra)
        {
            aux++;
        }

    }

    printf("A letra %c apareceu %d vezes\n ", letra,aux);

    printf("A posição da letra '%c' na palavra é\n",letra);
    for(i=0; i<=strlen(palavra); i++)
    {
        if(palavra[i]==letra)
        {
            i++;
            posicao=i;
            printf ("na posição %d\n", posicao);
        }
    }
    printf("Escreva algumas palavras:\n");
        gets (palavra);
    }
    return 0;
}

/*
5 - Ler uma string de no máximo 50 caracteres e em seguida um caractere (entre A e Z - consista se o caracter esta nesse
intervalo), mostrar quais as posições esse caractere (maiúscula ou minúscula) na string lida e quantas vezes ele apareceu.
Autor: Nathan Gonçalves de Oliveira
*/

int ex05()
{
    setlocale (LC_ALL, "portuguese");
    char palavra[50], letra;
    int i,posicao,aux;
    posicao=0;
    i=0;
    aux=0;

    printf("Escreva uma palavra ou frase de no máximo 50 caracteres: \n");
    gets(palavra);
    fflush (stdin);


    printf("Escreva um caractere para ser encontrado na palava:\n");
    scanf ("%c", &letra);
    while (strcasecmp (palavra, "PARE") != 0){

    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z'))
        printf ("");


    else
        printf("%c não é letra!.", letra);


    for(i=0; i<= strlen(palavra); i++)
    {
        if(palavra[i] == letra)
        {
            aux++;
        }

    }

    printf("A letra %c apareceu %d vezes\n ", letra,aux);

    printf("A posição da letra %c na palavra é\n",letra);
    for(i=0; i<=strlen(palavra); i++)
    {
        if(palavra[i]==letra)
        {
            i++;
            posicao=i;
            printf ("na posição %d\n", posicao);
        }
    }
    printf("Escreva algumas palavras:\n");
        gets (palavra);
    }

    return 0;
}

/*
5 - Ler uma string de no máximo 50 caracteres e em seguida um caractere (entre A e Z - consista se o caracter esta nesse
intervalo), mostrar quais as posições esse caractere (maiúscula ou minúscula) na string lida e quantas vezes ele apareceu.
Autor: Nathan Gonçalves de Oliveira
*/

int ex06()
{
    setlocale (LC_ALL, "portuguese");
    char palavra[50], letra;
    int i,posicao,aux;
    posicao=0;
    i=0;
    aux=0;

    printf("Escreva uma palavra ou frase de no máximo 50 caracteres: \n");
    gets(palavra);
    fflush (stdin);


    printf("Escreva um caractere para ser encontrado na palava:\n");
    scanf ("%c", &letra);
    while (strcasecmp (palavra, "PARE") != 0){

    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z'))
        printf ("");


    else
        printf("%c não é letra!.", letra);



    for(i=0; i<= strlen(palavra); i++)
    {
        if(palavra[i] == letra)
        {
            aux++;
        }

    }

    printf("A letra %c apareceu %d vezes\n ", letra,aux);


    printf("A posição da letra %c na palavra é\n",letra);
    for(i=0; i<=strlen(palavra); i++)
    {
        if(palavra[i]==letra)
        {
            i++;
            posicao=i;
            printf ("na posição %d\n", posicao);
        }
    }
    printf("Escreva algumas palavras:\n");
        gets (palavra);
    }

    return 0;
}

/*
7 – Ler uma string de no máximo 50 caracteres e criar uma nova string com seu inverso, isso é a ultima letra da primeira
string será a primeira na nova string e assim sucessivamente.
Autor: Nathan Gonçalves de Oliveira
*/

int ex07()

{
    setlocale (LC_ALL, "portuguese");
    char palavra[51];
    int i,tamanho;

    printf("Escreva uma palavra ou frase de no máximo 50 caracteres: \n");
    gets(palavra);
    fflush (stdin);
    tamanho = strlen(palavra);
    while (strcasecmp (palavra, "PARE") != 0){

    printf("A sua frase invertida é:\n");
    for ( i = tamanho; i >= 0; i--)
    {
    printf ("%c",palavra[i]);
    }

    printf("Escreva algumas palavras:\n");
        gets (palavra);
    }
    return 0;
}

/*
8 – Ler uma string de no máximo 50 caracteres e retire dessa string todos os espaços em branco. Utilize uma string
auxiliar.
Autor: Nathan Gonçalves de Oliveira
*/

int ex08()

{
    setlocale (LC_ALL, "portuguese");
    char palavra[50], semespaco[50];
    int i,aux;
    while (strcasecmp (palavra, "PARE") != 0){


    printf("Escreva uma palavra ou frase de no máximo 50 caracteres: \n");
    gets(palavra);
    fflush (stdin);

    aux=0;
    for (i=0; i<=strlen(palavra); i++)
    {

        if (palavra[i]!=' ')
        {
            semespaco[aux]=palavra[i];
            aux++;
        }

    }
    printf ("A sua palavra sem espaços é: %s \n",semespaco);

    printf("Escreva algumas palavras:\n");
        gets (palavra);
    }

    return 0;

}

/*
9 – Ler uma string de no máximo 50 caracteres e retire dessa string todos os espaços em branco. Sem utilize string auxiliar.
Autor: Nathan Gonçalves de Oliveira
*/

int ex09()
{
    setlocale (LC_ALL, "portuguese");
    char palavra[50], semespaco[50];
    int i,aux;
    i=0;
    aux=0;

    printf("Escreva uma palavra ou frase de no máximo 50 caracteres: \n");
    gets(palavra);
    while (strcasecmp (palavra, "PARE") != 0){

    while (palavra[i] != '\0')
    {
        if (!(palavra[i] == ' ' && palavra[i+1] == ' '))
        {
            semespaco[aux] = palavra[i];
            aux++;
        }
        i++;
    }

    semespaco[aux] = '\0';

    printf("A palavra sem espaços é %s \n", semespaco);

    printf("Escreva algumas palavras:\n");
        gets (palavra);
    }

    return 0;
}

/*
10 - Ler uma string de no máximo 50 caracteres em seguida leia outra string de no máximo 3 caracteres, informe quantas
vezes a segunda string aparece na primeira string, e diga as posições iniciais em que ela aparece.
Autor: Nathan Gonçalves de Oliveira
*/

int ex10()
{
    setlocale (LC_ALL, "portuguese");
    char palavra[50], frase[3];
    int i,posicao,aux;
    posicao=0;
    i=0;
    aux=0;

    printf("Escreva uma palavra ou frase de no máximo 50 caracteres: \n");
    gets(palavra);

    printf("Escreva um caractere para ser encontrado na palava:\n");
    gets(frase);
    while (strcasecmp (palavra, "PARE") != 0){

    for(i=0; i<= strlen(palavra); i++)
    {
        if(palavra[i] == frase)
        {
            aux++;
        }

    }

    printf("A letra %c apareceu %d vezes\n ", frase,aux);


    printf("A posição da letra %c na palavra é\n",frase);
    for(i=0; i<=strlen(palavra); i++)
    {
        if(palavra[i]==frase)
        {
            i++;
            posicao=i;
            printf ("na posição %d\n", posicao);
        }
    }

    printf("Escreva algumas palavras:\n");
        gets (palavra);
    }

    return 0;
}

