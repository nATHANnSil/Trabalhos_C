#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int ex1();
int ex2();
int ex3();
int ex4();
int ex5();
int ex6();
int ex7();
int ex8();
int ex9();
int ex10();


int main()
{
    setlocale(LC_ALL, "portuguese");
    int exercicio;
    printf(" 1- Exercicio 1 \n 2- Exercicio 2 \n 3- Exercicio 3 \n 4- Exercicio 4 \n 5- Exercicio 5 \n 6- Exercicio 6 \n 7- Exercicio 7 \n 8- Exercicio 8 \n 9- Exercicio 9 \n10- Exercicio 10");

    printf ("\nEscolha o exercício que deseja visualizar:");
    scanf("%d", &exercicio);
    switch(exercicio)
    {
    case 1:
        ex1();
        break;
    case 2:
        ex2();
        break;
    case 3:
        ex3();
        break;
    case 4:
        ex4();
        break;
    case 5:
        ex5();
        break;
    case 6:
        ex6();
        break;
    case 7:
        ex7();
        break;
    case 8:
        ex8();
        break;
    case 9:
        ex9();
        break;
    case 10:
        ex10();
        break;
    default:
        printf("Código inválido\n");

    }
}


// 1. Fazer um algoritmo que leia um numero inteiro e mostre uma mensagem indicando se este numero e par ou impar
/* portugol: algoritmo "ex1"
var
num : inteiro
inicio
leia (num)
se (num % 2 == 0) então
     escreva ( num, “é par”)
senao
    escreva (num, “é ímpar”)
fimse
fimalgorimto */

int ex1 ()

{
    printf("\n1- Exercicio 1\n");
    int num;
    printf("Digite um número inteiro: ");
    scanf("%d", &num);
    if (num % 2 == 0)
    {
        printf("Este número é par\n ");
    }
    else
    {
        printf("Este número é ímpar\n");
    }
    return 0;
}

/* 2. Fazer um algoritmo peça o nome e as 3 notas de um aluno e mostre, além do nome e do valor da media do aluno,
uma mensagem de "Aprovado", caso a media seja igual ou superior a 6, ou a mensagem "reprovado", caso
contrario.
portugol:algoritmo "ex2"
var
nome:caracter
n1,n2,n3,media:real
   inicio
leia (nome)
leia(n1,n2,n2)
media <-- n1+n2+n3
escreva(nome,media)
se (media >= 6)
   escreva ("aprovado")
senao
   escreva ("reprovado"
fimse
fimalgoritmo*/


int ex2 ()
{
    printf("\n2- Exercicio 2\n");
    float n1, n2, n3, media;
    char nome[21];
    printf("Digite o nome:");
    fgets(nome, 21, stdin);
    printf("Digite a primeira nota:");
    scanf("%f", &n1);
    printf("Digite a segunda nota:");
    scanf("%f", &n2);
    printf("Digite a terceira nota:");
    scanf("%f", &n3);

    media= (n1+n2+n2)/3;
    printf("\n%sMédia=%5.2f\n", nome, media);

    if (media>= 6)
    {
        printf("Aprovado!\n");

    }
    else
    {
        printf("Reprovado\n");

    }
    return 0;

}

/* 3. Fazer um algoritmo que leia a temperatura da água e mostre se está no estado solido, líquido ou gasoso
portugol: algoritmo "ex3"
var
temp: int
inicio
   leia (temp)
se(temp<=0)
   escreva ("Está no estado sólido")
senao
se(temp>= 100)
   escreva ("Está no estado gasoso")
senao
   escreva ("Está no estado líquido")
fimse
fimalgoritmo*/

int ex3()
{
    printf("\n3- Exercicio 3\n");
    int temp;
    printf("Digite a temperatura da água:");
    scanf("%d", &temp);
    if (temp<=0)
    {
        printf ("Está no estado sólido\n");
    }
    else
    {
        if (temp>= 100)
        {
            printf("Está no estado gasoso\n");
        }
        else
        {
            printf("Está no estado líquido\n");
        }
    }
    return 0;
}

/* 4. Leia um valor X e se ele for menor que 0 avalie Y = x2 + 4. Se ele for maior que 0 avalie x3-3
e se ele for igual a 0 de uma mensagem de erro.
portugol: algoritmo "ex4"
var
valor, menor, maior: inteiro
inicio
   leia (valor)
se (valor<0)
   menor <- (valor^2) + 4
   escreva("O resultado da equação é %d", menor);
senao
se (valor > 0)
   maior <- (valor^3)-3
   escreva("O resultado da equação é %d", maior);
senao
   escreva("Ocorreu um erro. Aperte ENTER para tentar novamente digitando um número diferente de 0")
fimse
fimalgoritmo*/

int ex4()
{
    printf("\n4- Exercicio 4\n");
    setlocale(LC_ALL, "portuguese");
    int valor, menor, maior;
    printf("Digite um valor para a X:");
    scanf("%d", &valor);
    if (valor < 0)
    {
        menor= pow (valor, 2) + 4;
        printf("O resultado da equação é %d\n", menor);
    }
    else
    {
        if ( valor > 0 )
        {
            maior= pow (valor,3)-3;
            printf("O resultado da equação é %d\n", maior);
        }
        else
        {
            printf("Ocorreu um erro. Aperte ENTER para tentar novamente digitando um número diferente de 0");
        }
    }
    return ;
}

/* 5. Construa um algoritmo que receba como entrada três valores (A,B e C). Após o processamento o menor valor
deverá estar em A e o maior valor em C, e o valor intermediário em B. Imprima A,B e C.
portugol: algoritmo "ex5"
var
   a,b,c, maior, menor, inter:inteiro
inicio
   leia(a,b,c)
   menor==a
   menor==a;
   maior==c;
   inter==b;
se (a<b && a<c)
   menor= a;
senao
se (b<a && b<c)
   menor= b;
senao
   menor=c;
se (c>a && c>b)
   maior= c;
senao
se (b>a && b>c)
   maior= b;
senao
maior=a;
se (b>menor && b<maior)
   inter=b;
senao
se (a>menor && a<maior)
   inter=a;
senao
   inter=c;
escreva("menor", "inter", e,"maior")
fimse
fimalgoritmo*/

int ex5()
{
    printf("\n5- Exercicio 5\n");
    int a,b,c, maior, menor, inter;
    printf("Digite um valor para a A:");
    scanf("%d", &a);
    printf("Digite um valor para a B:");
    scanf("%d", &b);
    printf("Digite um valor para a C:");
    scanf("%d", &c);
    menor==a;
    maior==c;
    inter==b;
    if (a<b && a<c)
    {
        menor= a;
    }
    else
    {
        if (b<a && b<c)
        {
            menor= b;
        }
        else
        {
            menor=c;
        }
    }
    if (c>a && c>b)
    {
        maior= c;
    }
    else
    {
        if (b>a && b>c)
        {
            maior= b;
        }
        else
        {
            maior=a;
        }
    }
    if(b>menor && b<maior)
    {
        inter=b;
    }
    else
    {
        if (a>menor && a<maior)
        {
            inter=a;
        }
        else
        {
            inter=c;
        }
    }
    printf("A=%d, B=%d e C=%d\n", menor,inter, maior);
    return 0 ;
}

/* 6. Desenvolver um algoritmo que leia três números inteiros: X, Y, Z e verifique se o número X é divisível por Y e por Z.
O algoritmo deverá mostrar as possíveis mensagens:
- o número é divisível por Y e Z.
- o número é divisível por Y mas não por Z.
- o número é divisível por Z mas não por Y.
- o número não é divisível nem Y nem por Z.
portugol: algoritmo "ex6"
var
  x,y,z:inteiro
inicio
   leia (x,y,z)
se (x% y == 0 && x%z==0)
   escreva("O número é divisível por Y e Z.");
senao
se(x%y==0)
   escreva("O número é divisível por Y mas não por Z.");
senao
se(x%z==0)
   escreva("O número é divisível por Z mas não por Y.");
sennao
   escreva ("O número não é divisível nem Y nem por Z");
fimse
fimalgoritmo*/

int ex6 ()
{
    printf("\n6- Exercicio 6\n");
    int x,y,z;
    printf("Digite um valor para a X:");
    scanf("%d", &x);
    printf("Digite um valor para a Y:");
    scanf("%d", &y);
    printf("Digite um valor para a Z:");
    scanf("%d", &z);
    if (x% y == 0 && x%z==0)
    {
        printf("O número é divisível por Y e Z.\n");
    }
    else
    {
        if (x%y==0)
        {
            printf("O número é divisível por Y mas não por Z.\n");
        }
        else
        {
            if (x%z==0)
            {
                printf("O número é divisível por Z mas não por Y.\n");
            }
            else
            {
                printf("O número não é divisível nem Y nem por Z\n");
            }
        }
    }
    return 0 ;
}

/* 7. O numero 3025 possui a seguinte característica:
30 + 25 = 55
55² = 3025
Fazer um algoritmo que dado um numero de 4 dígitos (verifique se o número pertence a faixa) calcule e escreva se ele
possui ou não esta característica.
portugol: algoritmo "ex7"
var
   num, soma, n1,n2,n3,n4,aux1, aux2:inteiro
leia(num)
aux1==n1;
n1<- num/100;
aux1<-num%100;
n2<-n1/100;
aux2<-n1%100;
soma<- aux1+aux2;
se (!(num>= 1000 && num<=9999))
   escreva ("esse número não pertence a faixa, tente novamente com um número de 4 dígitos.");
senao
se (soma^2)==num
   escreva ("%d possui essa característica!", num);
senao
   escreva("%d não possui essa característica.", num);
fimse
fimalgoritmo
*/

int ex7()
{
    printf("\n7- Exercicio 7\n");
    int num, soma, n1,n2,n3,n4,aux1, aux2;
    printf("Digite um número:");
    scanf("%d", &num);
    aux1==n1;
    n1=num/100;
    aux1=num%100;
    n2=n1/100;
    aux2=n1%100;
    soma= aux1+aux2;

    if (!(num>= 1000 && num<=9999))
    {
        printf("esse número não pertence a faixa, tente novamente com um número de 4 dígitos.");
    }
    else
    {
        if (pow(soma,2)==num)
        {
            printf("%d possui essa característica!\n", num);
        }
        else
        {
            printf("%d não possui essa característica.\n", num);
        }
    }
    return 0 ;
}

/* 8. - ler um código do teclado e mostrar o nome correspondente, de acordo com a lista :
221 Bernardo
211 Eustáquio
311 Luiz
312 Mário
332 Artur
portugol: algoritmo "ex8"
var
  cod:inteiro
inicio
   leia(cod)
se(cod==221)
   escreva ("Bernardo")
senao
se(cod == 211)
   escreva("Eustáquio")
senao
se(cod==311)
   escreva("Luiz")
senao
se(cod==312)
   escreva("Mário")
senao
se(cod==332)
   escreva("Artur")
senao
   escreva("Código inválido")
fimse
fimalgoritmo*/

int ex8()
{
    printf("\n8- Exercicio 8");
    int cod;
    printf("221\n211\n311\n312\n332\nDigite um dos códigos acima que o programa mostrará o seu nome correpondente:\n");
    scanf("%d", &cod);
    if (cod==221)
    {
        printf("Bernardo\n");
    }
    else
    {
        if (cod == 211)
        {
            printf("Eustáquio\n");
        }
        else
        {
            if (cod==311)
            {
                printf("Luiz\n");
            }
            else
            {
                if (cod==312)
                {
                    printf("Mário\n");
                }
                else
                {
                    if (cod==332)
                    {
                        printf("Artur\n");
                    }
                    else
                    {
                        printf("Código inválido\n");
                    }
                }
            }
        }
    }

    return 0 ;
}


/*9. Números palíndromos são aqueles que escritos da direita para esquerda ou da esquerda para direita tem o mesmo valor.
Exemplo:929, 44, 97379. Fazer um algoritmo que dado um numero de 5 dígitos; calcule e escreva se este e ou não palíndromo.
portugol: algortimo "ex9"
var
   num, n1,n2,n3,n4,n5, aux1, aux2, aux4, aux5:inteiro
inicio
   leiia(num)
n1<- num/10;
aux1<-num%10;
n2<-n1/10;
aux2<-n1%10;
n3<-n2/10;
n4<-n3/10;
aux4<-n3%10;
n5<-n4/10;
aux5<-n4%10;
se (!(num>= 10000 && num<=99999)){
   escreva ("Digite um número de 5 dígitos.")
senao
se (aux1== aux5 && aux2==aux4){
   escreva("%d é um número palíndromo", num)
senao
   escreva("%d não é um número palíndromo", num)
fimse
fimalgoritmo
*/

int ex9()
{
    printf("\n9- Exercicio 9\n");
    int num, n1,n2,n3,n4,n5, aux1, aux2, aux4, aux5;
    printf("Digite um número:");
    scanf("%d", &num);
    n1= num/10;
    aux1=num%10;
    n2=n1/10;
    aux2=n1%10;
    n3=n2/10;
    n4=n3/10;
    aux4=n3%10;
    n5=n4/10;
    aux5=n4%10;

    if (!(num>= 10000 && num<=99999))
    {
        printf("Digite um número de 5 dígitos.\n");
    }
    else
    {
        if (aux1== aux5 && aux2==aux4)
        {
            printf("%d é um número palíndromo\n", num);
        }
        else
        {
            printf("%d não é um número palíndromo\n", num);
        }
    }
    return 0 ;
}

/* 10. Desenvolver um algoritmo para calcular a conta de água para a SANEAGO. O custo da água varia dependendo do tipo do
consumidor - residencial, comercial ou industrial. A regra para calcular a conta e:
• Residencial: R$ 75,00 de taxa mais R$ 3,50 por m3 gastos;
• Comercial: R$ 500,00 para os primeiros 80 m3 gastos mais R$ 5,50 por m3 gastos acima dos 80 m3
;
• Industrial: R$ 800,00 para os primeiros 100 m3 gastos mas R$ 8,00 por m3 gastos acima dos 100 m3
;
O algoritmo devera ler a conta do cliente, seu tipo (residencial, comercial e industrial) e o seu consumo de água em metros cubos.
Como resultado imprimir o valor a ser pago pelo mesmo.
portugol: algortimo "ex10"
var
   consumo, valor:real
   contaconsumidor : inteiro
inicio
   leia(contaconsumidor)
   leia(consumo)
escolha contaconsumidor
caso 1:
   valor=75+(3.50*consumo)
   escreva("Total a ser pago pela conta R$%.2f",valor)
caso 2:
   valor= 500;
   escreva("Total a ser pago pela conta R$%.2f",valor)
se (consumo>80)
   valor= 500+((consumo-80)*5.5);
   escreva ("Total a ser pago pela conta R$%.2f",valor)
caso 3:
se
(consumo<100)
   valor=800
   escreva ("Total a ser pago pela conta R$%.2f",valor)
senao
se(consumo>100)
   valor= 800+((consumo-100)*8);
   escreva("Total a ser pago pela conta R$%.2f",valor)
senao
   escreva(" \n Você digitou uma opção inválida!")
fimescolha
fimalgoritmo*/

int ex10()
{
    printf("\n10- Exercicio 10\n");
    float consumo, valor;
    int contaconsumidor;
    printf("1-Residencial\n2-Comercial\n3-Industrial\n");
    printf("Digite o número da opção desejada para calcular:");
    scanf("%d", &contaconsumidor);
    printf("Digite o seu consumo de água em metros cubicos:");
    scanf("%f", &consumo);
    switch (contaconsumidor)
    {
    case 1:
        valor=75+(3.50*consumo);
        printf("Total a ser pago pela conta R$%.2f\n",valor);
        break;
    case 2:
        if (consumo<=80)
        {
            valor= 500;
            printf("Total a ser pago pela conta R$%.2f\n",valor);
        }
        else
        {
            valor= 500+((consumo-80)*5.5);
            printf("Total a ser pago pela conta R$%.2f\n",valor);
        }
        break;
    case 3:
        if (consumo<=100)
        {
            valor=800;
            printf("Total a ser pago pela conta R$%.2f\n",valor);
        }
        else
        {
            valor= 800+((consumo-100)*8);
            printf("Total a ser pago pela conta R$%.2f\n",valor);
        }
        break;
    default:
        printf(" \n Você digitou uma opção inválida!\n");
    }
    return 0 ;
}
