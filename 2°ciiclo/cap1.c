#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex5

#ifdef ex1
/*Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
    variável auxiliar.*/
int main() {
    int a;
    int b;

    setlocale(LC_ALL,"");
    printf("Digite o valor de a: ");
    scanf("%d",&a); //10
    printf("\nDigite o valor de b: "); //6
    scanf("%d",&b);
    a = a + b; //16
    b = a - b; //16 - 6
    a = a - b; // 16 - 10

    printf("\n\no valor de a é: %d e o valor de b é: %d",a,b);

    return 0;
}
#endif //ex1

#ifdef ex2
/*Escreva um programa que receba dados via teclado para variaveis do tipo short,
    long, int, float, double e um char e imprima-os no video no seguinte
    formato:
             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char*/
int main() {

    setlocale(LC_ALL,"");

    short int S;
    long int L;
    int I;
    float F;
    double D;
    char C;

    printf("Digite um valor para a variável tipo short: ");
    scanf("%hd",&S);

    printf("\nDigite um valor para a variável tipo long: ");
    scanf("%ld",&L);

    printf("\nDigite um valor para a variável tipo int: ");
    scanf("%d",&I);

    printf("\nDigite um valor para a variável tipo float: ");
    scanf("%f",&F);

    printf("\nDigite um valor para a variável tipo double: ");
    scanf("%f",&D);
    getchar();

    printf("\nDigite um valor para a variável tipo char: ");
    scanf("%c",&C);
    getchar();

    printf("\n\nimprimindo:\n\n\n12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("    %-6hd              %-11ld         %-45d\n",S,L,I);
    printf("              %-15f     %-15ld     ",F,D);
    putchar(C);

    return 0;

}
#endif //ex2

#ifdef ex3
/*Escreva um programa que receba via teclado um tempo em segundos e converta
    para horas, minutos e segundos.
    Ex.: recebe 3850 segundos que converte para 1h 4min 10s*/
int main() {
    int segundos = 0;
    int minutos = 0;
    int horas = 0;

    do {
        printf("O valor superior a 0 e inferior a 86400. Digite a quantidade de segundos: ");
        scanf("%d",&segundos);
        if(segundos<0)
            printf("\nDigite um valor váludo!!!\n\n");
        if(segundos>86400)
            printf("\nDigite um valor váludo!!!\n\n");
    }while(segundos<0 || segundos>86400);

    if(segundos>59) {
        minutos = segundos/60;
        segundos = segundos%60;
    }
    if(minutos>59) {
        horas = minutos/60;
        minutos = minutos%60;
    }
    printf("\n\n\n%d horas, %d minutos e %d segundos.",horas,minutos,segundos);
    return 0;
}
#endif // ex3

#ifdef ex4
/*faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
outro número formado pelos dígitos invertidos do número lido.
Ex:   NúmeroLido = 123   NúmeroGerado = 321*/
int main() {

    int NumeroLido, centena, dezena, unidade, NumeroGerado;
    setlocale(LC_ALL,"");

    do {
        printf("Digite um número positivo de 3 digitos:");
        scanf("%d",&NumeroLido);
        if(NumeroLido<100||NumeroLido>999)
            printf("Digite um valor válido!!!\n\n");
    }while(NumeroLido<100||NumeroLido>999);

    centena = NumeroLido/100;
    dezena = (NumeroLido-(centena*100))/10;
    unidade = NumeroLido - ((dezena*10) + (centena*100));
    NumeroGerado = (unidade*100) + (dezena*10) + centena;

    printf("\n\nO número lido foi:%d e o número gerado foi:%d", NumeroLido, NumeroGerado);
    return 0;
}
#endif // ex4

#ifdef ex5
/* Escreva um programa que determine o menor multiplo de um numero inteiro. Este
    multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
    teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104.*/
int main() {
    int Numero, LimiteMinimo, Resultado;

    setlocale(LC_ALL,"");
    do{
        printf("Digite um número positivo maior que 0: ");
        scanf("%d",&Numero);
        if(Numero<=0)
            printf("Digite um número válido!!!\n\n");
    }while(Numero<=0);

    do{
        printf("\nDigite o limite mínimo: ");
        scanf("%d",&LimiteMinimo);
        if(LimiteMinimo<0)
            printf("Digite um limite mínimo válido!!!\n\n");
    }while(LimiteMinimo<0);

    for(int x = LimiteMinimo;;x++)
        if(x%Numero==0) {
            Resultado = x;
            break;
        }
    printf("\n\nO mínimo múltiplo comum do número: %d com limite mínimo de: %d é: %d \n",Numero,LimiteMinimo,Resultado);
    return 0;
}


#endif // ex5
