#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define ex2
//OBS.:Todos os programa devem ser finalizados pelo usuario.

#ifdef ex1
/*1 - Escreva um programa para determinar a idade de uma pessoa, em anos, meses e
    dias, recebendo via teclado a data (dia, mes e ano) do seu nascimento e a
    data (dia, mes e ano) atual.*/
int main() {
int DataNasc[3],DataAtual[3],Idade[3];
char Resposta;

setlocale(LC_ALL,"");

do{
    printf("\nDigite o dia de hoje:");
    do{
    scanf("%d",&DataAtual[0]);
    if(DataAtual[0]<1 || DataAtual[0]>31)
        printf("Digite um dia válido:");
    }while(DataAtual[0]<1 || DataAtual[0]>31);

    printf("\no mês de hoje:");
    do{
    scanf("%d",&DataAtual[1]);
     if(DataAtual[1]<1 || DataAtual[1]>12)
        printf("Digite um mês válido:");
    }while(DataAtual[1]<1 || DataAtual[1]>12);

    printf("\no ano do hoje:");
    do{
    scanf("%d",&DataAtual[2]);
    if(DataAtual[2]<1)
        printf("Digite um ano válido:");
    }while(DataAtual[2]<1);


    printf("\n\no ano do seu nascimento:");
    do{
    scanf("%d",&DataNasc[0]);
    if(DataNasc[0]<0 || DataNasc[0]>DataAtual[2])
        printf("Digite um ano válido:");
    }while(DataNasc[0]<0 || DataNasc[0]>DataAtual[2]);

    printf("\no mês do seu nascimento:");
    do{
    scanf("%d",&DataNasc[1]);
    if(DataNasc[1]<1 || DataNasc[1]>12 || (DataNasc[0]==DataAtual[2] && DataNasc[1]>DataAtual[1]))
        printf("Digite um mês válido:");
    }while(DataNasc[1]<1 || DataNasc[1]>12 || (DataNasc[0]==DataAtual[2] && DataNasc[1]>DataAtual[1]));

    printf("\nDigite o dia do seu nascimento:");
    do{
    scanf("%d",&DataNasc[2]);
    if(DataNasc[2]<1 || DataNasc[2]>31 || (DataNasc[0]==DataAtual[2] && DataNasc[1]==DataAtual[1] && DataNasc[2]>DataAtual[0]))
        printf("Digite um dia válido:");
    }while(DataNasc[2]<1 || DataNasc[2]>31 || (DataNasc[0]==DataAtual[2] && DataNasc[1]==DataAtual[1] && DataNasc[2]>DataAtual[0]));

    Idade[0]=DataAtual[2]-DataNasc[0];
    Idade[1]=DataAtual[1]-DataNasc[1];
    if (Idade[1]<0)
        Idade[1] = Idade[1]+12;
    Idade[2]=DataAtual[0]-DataNasc[2];
     if (Idade[2]<0)
        Idade[2] = Idade[2]+30;

    printf("\nSua idade é: %d anos,%d meses e %d dias",Idade[0],Idade[1],Idade[2]);

    printf("\n\nDigite s caso queira calcular outra idade:");
    scanf("%c",Resposta);
    getchar();
}while(Resposta=='s'||Resposta=='S');
}
#endif//ex1
#ifdef ex2
/*2 - Escreva um programa que receba via teclado uma data (dia, mes, e ano).
    Determine o dia da semana desta data.*/
int main() {
char Resposta;
int Data[3],a,b,c;
setlocale(LC_ALL,"");

    printf("Digite uma data, começando pelo dia:");
    do{
    scanf("%d",&Data[0]);
    if(Data[0]<0 || Data[0]>31)
        printf("Digite um valor válido:");
    }while(Data[0]<0 || Data[0]>31);

    printf("mes:");
    do{
    scanf("%d",&Data[1]);
    if(Data[1]<0 || Data[1]>12)
        printf("Digite um valor válido:");
    }while(Data[1]<0 || Data[1]>12);

    printf("ano:");
    do{
    scanf("%d",&Data[2]);
    if(Data[2]<0)
        printf("Digite um valor válido:");
    }while(Data[1]<0);

    if (Data[1] < 3) {
        Data[1] += 12;
        Data[2]--;
    }
    a = Data[2] % 100;
    b = Data[2] / 100;
    c = (Data[0] + 13 * (Data[1] + 1) / 5 + a + a / 4 + b / 4 + 5 * b) % 7;

    printf("O dia da semana para a data %d/%d/%d é ", Data[0], Data[1], Data[2]);
    switch (c) {
        case 0:
            printf("Sábado");
            break;
        case 1:
            printf("Domingo");
            break;
        case 2:
            printf("Segunda-feira");
            break;
        case 3:
            printf("Terça-feira");
            break;
        case 4:
            printf("Quarta-feira");
            break;
        case 5:
            printf("Quinta-feira");
            break;
        case 6:
            printf("Sexta-feira");
            break;
    printf(".\n");

    printf("Digite s se deseja inserir outros dois números:");
    scanf("%c",Resposta);
    getchar();
}while(Resposta=='s'||Resposta=='S');
}
#endif//ex2

#ifdef ex3
/*3 - Escreva um programa que receba via teclado 2 numeros inteiros e execute
    as operacoes logicas bit a bit AND, OU, OU EXCLUSIVO e imprima-os no
    video no formato decimal e hexadecimal.*/
int main() {
    setlocale(LC_ALL, "");
    char Resposta;
    int num1, num2, and, or, xor;

    do{
        system("cls");
        printf("Digite o primeiro numero inteiro: ");
        scanf("%d", &num1);
        printf("Digite o segundo numero inteiro: ");
        scanf("%d", &num2);

        and = num1 & num2;
        or = num1 | num2;
        xor = num1 ^ num2;

        printf("\nResultados das operações:\n");
        printf("AND (decimal): %d (hexadecimal): %X\n", and, and);
        printf("OR (decimal): %d (hexadecimal): %X\n", or, or);
        printf("XOR (decimal): %d (hexadecimal): %X\n", xor, xor);

        printf("Digite 's' caso queira inserir outros valores: ");
        Resposta = getchar();
    }while(Resposta=='s'||Resposta=='S');

    return 0;
}

#ifdef ex4
/*4 - Escreva um programa que receba via teclado 2 numeros inteiros e
    imprima-os no video com o resultado das 4 operacoes aritmeticas.*/
int main() {
float A,B,soma,subt,mult,div;
char Resposta;

setlocale(LC_ALL,"");

do{
    printf("Digite o 1° valor:");
    scanf("%f",&A);

    printf("Digite o 2° valor:");
    scanf("%f",&B);

    soma = A+B;
    subt= A-B;
    mult = A*B;
    div = A/B;

    printf("\nsoma= %.0f",soma);
    printf("\nsubtração= %.0f",subt);
    printf("\nmultiplicação= %.0f",mult);
    printf("\ndiv= %.2f",div);

    printf("\n\nDigite s se deseja inserir outros dois números:");
    scanf(" %c",&Resposta);
    getchar();
}while(Resposta=='s'||Resposta=='S');
}
#endif//ex4

#ifdef ex5
/*5 - Reescreva o exercicio anterior utilizando operadores de atribuicao
    composta.*/
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main() {
float B,soma,subt,mult,div;
char Resposta;

setlocale(LC_ALL,"");

do{
    printf("Digite o 1° valor:");
    scanf("%f",&soma);

    subt = soma;
    mult = soma;
    div = soma;

    printf("Digite o 2° valor:");
    scanf("%f",&B);

    soma += B;
    subt -= B;
    mult *= B;
    div /= B;

    printf("\nsoma= %.0f",soma);
    printf("\nsubtração= %.0f",subt);
    printf("\nmultiplicação= %.0f",mult);
    printf("\ndiv= %.2f",div);

    printf("\n\nDigite s se deseja inserir outros dois números:");
    scanf(" %c",&Resposta);
    getchar();
}while(Resposta=='s'||Resposta=='S');
}
#endif//ex5
