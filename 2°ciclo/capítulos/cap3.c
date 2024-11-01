
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex1
//BS.: Todos os programa devem ser finalizados pelo usuario.

#ifdef ex1
/*1 - Escreva um programa que receba um numero N via teclado. Escreva uma funcao
    que retorne a soma dos algarismos do resultado de N!. O resultado deve ser
    mostrado na funcao main().
    Ex: se N = 4, N! = 24. Logo, a soma de seus algarismos e´ 2 + 4 = 6.*/
int main() {
    int x, N, Nf, metrica, Soma, suporte;
    char Resposta;
    setlocale(LC_ALL,"");

    do {
        metrica = 1;
        Soma = 0;
        Nf = 1;
        system("cls");
        do {
            printf("\nDigite um número maior que 0 e menor que 17: ");
            scanf("%d",&N);
            getchar();
            if(N<0 || N>16)
                printf("Digite um valor válido!!!\n\n");
        }while(N<0 || N>16);

        for(x=1;x<N+1;x++) //fatoriando
            Nf = Nf*x;

        printf("\nO falor do fatorial do número digitado é: %d", Nf);
        for(x=0;;x++){ // determinando o tamanho
            if(Nf/metrica > 0)
                metrica = metrica*10;
            else {
                metrica = metrica/10;
                break;
            }
        }
        if(metrica==1)
                Soma = Nf;

        else{
            for(x=0;;x++) { //fazendo a soma
                if(metrica==1){
                    suporte = (Nf/metrica);
                    Soma = Soma + suporte;
                    Nf = Nf - (suporte*metrica);
                    metrica = metrica/10;
                    break;
                }

                else {
                    suporte = (Nf/metrica);
                    Soma = Soma + suporte;
                    Nf = Nf - (suporte*metrica);
                    metrica = metrica/10;
                }
            }
        }
        printf("\n\nA soma dos algarismos do fatorial do número digitado é: %d", Soma);
        printf("\n\nDigite S caso queira inserir um novo valor:");
        scanf(" %c",&Resposta);
    }while(Resposta == 'S'|| Resposta == 's');


    return 0;
}
#endif // ex1
#ifdef ex2
/*2 - Escreva um programa que receba dois numeros inteiros e execute as seguintes
    funçoes:
    - Verificar se o numero digitado e' positivo ou negativo. Sendo que o valor de
      retorno sera' 1 se positivo, 0 se negativo ou -1 se for igual a 0.
    - Se os 2 numeros sao positivos, retorne a soma dos N numeros existentes entre
      eles.
    - Se os 2 numeros sao negativos, retorne a multiplicacao dos N numeros existente
      entre eles.
    - Se 1. numero for positivo e o 2. negativo faca a divisao entre eles.*/
int verificar(numeroII) {
    int valor;
    if(numeroII%2 == 0)
	    valor=1;
    else
	    valor=0;
return valor;
}

int main() {
	float numeroI, numeroII;
	int verificadoI, verificadoII;
	char Resposta;
	setlocale(LC_ALL,"");

	do{
        printf("Digite o valor do número 1: ");
        scanf("%f",&numeroII);
        verificadoI = verificar(numeroII);
        numeroI = numeroII;

        printf("Digite o valor do número 2: ");
        scanf("%f",&numeroII);
        verificadoII = verificar(numeroII);

        if(verificadoI==0 && verificadoII == 0)
            printf("A multiplicação dos número é: %d",numeroI*numeroII);
        else
            printf("a divisão dos números é %f",numeroI/numeroII);
        printf("\n\nDigite S caso queira tentar com novos valores: ");
        scanf("%c",&Resposta);
	}while(Resposta == 's' || Resposta == 'S');
	return 0;
}
#endif //ex2

#ifdef ex3
/*3 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima os 4 resultados no video na funcao main().*/
int Soma(int valorI, int valorII) {
    return valorI + valorII;
}
int Subtracao(int valorI, int valorII) {
    return valorI - valorII;
}
float Divisao(float valorI,float valorII) {
    return valorI/valorII;
}
int Multiplicacao(int valorI, int valorII) {
    return valorI*valorII;
}

int main () {
    float valorI, valorII;
    char Resposta;
    setlocale(LC_ALL,"");

    do{
        system("cls");
        printf("Digite um número: ");
        scanf("%f",&valorI);
        printf("Digite um número: ");
        scanf("%f",&valorII);
        printf("A soma dos números é: %d\nA subtração dos números é: %d\nA multiplicação dos números é: %d\nA divisão dos números é: %.2f\n",Soma(valorI,valorII),Subtracao(valorI,valorII),Multiplicacao(valorI,valorII),Divisao(valorI,valorII));
        printf("\nDigite s caso queira continuar: ");
        scanf("%c",&Resposta);
        getchar();
    }while(Resposta == 's'||Resposta=='S');
}
#endif //ex3

#ifdef ex4
/*4 - Reescreva o programa do exercicio anterior para receber via teclado n
    valores. Os n valores nao sao definidos previamente.*/
float valores[50];
int Soma(int quant) {
    int x, soma = 0;
    for(x=0; x<quant;x++)
        soma += valores[x];
return soma;
}

int Subtracao(int quant) {
    int x, subtracao = valores[0];
    for(x=1; x<quant;x++)
        subtracao = subtracao -(valores[x]);
return subtracao;
}

float Divisao(int quant) {
    int x, divisao = valores[0];
    for(x=1; x<quant;x++)
        divisao = divisao/valores[x];
return divisao;
}

int Multiplicacao(int quant) {
    int x, multiplicacao = valores[0];
    for(x=1; x<quant;x++)
        multiplicacao = multiplicacao*valores[x];
return multiplicacao;
}

int main () {
    int quant = 0, x;
    char Resposta;
    setlocale(LC_ALL,"");

    do{
        for(x = 0;;x++){
            if(Resposta!= '=') {
        	printf("Digite um número: ");
        	scanf("%f",&valores[x]);
        	Resposta = getchar();
        	quant++;
            }
            else break;
        }
        printf("A soma dos números é: %d\nA subtração dos números é: %d\nA multiplicação dos números é: %d\nA divisão dos números é: %.5f\n",Soma(quant),Subtracao(quant),Multiplicacao(quant),Divisao(quant));
        printf("\nDigite s caso queira continuar: ");
        scanf("%c",&Resposta);
        getchar();
    }while(Resposta == 's'||Resposta=='S');
}
#endif //ex4

#ifdef ex5
/*5 - Escreva um programa que receba n valores inteiros via teclado na funcao main().
    Faca uma calculadora com as 4 operacoes aritmeticas.(utilize o comando switch).
    As operacoes aritmeticas devem ser funcoes. O resultado acumulado deve ser
    mostrado na funcao main().*/
    float soma(float acumulado, float numero){
        acumulado = acumulado + numero;
        return acumulado;
    }

    float subtracao(float acumulado, float numero){
        acumulado = acumulado - (numero);
        return acumulado;
    }

    float divisao(float acumulado, float numero){
        acumulado = acumulado/numero;
        return acumulado;
    }

    float multiplicacao(float acumulado, float numero){
        acumulado = acumulado*numero;
        return acumulado;
    }

int main() {
    float acumulado, numero;
    int x;
    char Resposta;

    setlocale(LC_ALL,"");
    do{
        system("cls");
        printf("\nDigite (+) para soma, (-) para subtração,(x) para multiplicação ou (/) para divisão.\n\n");
        scanf("%f",&acumulado);
        for(x = 1;;x++) {
            do {
                scanf(" %c",&Resposta);
                if(Resposta != '+' && Resposta != '-'&& Resposta != 'x' && Resposta != '/' && Resposta != '=')
                        printf("Digite um operdor válido!\n");
            }while(Resposta != '+' && Resposta != '-'&& Resposta != 'x' && Resposta != '/' && Resposta != '=');
            if(Resposta == '=') {
                printf("\nResultado = %.2f",acumulado);
                break;
            }
            scanf("%f",&numero);
            getchar();
            switch(Resposta) {

                case '+':
                    acumulado = soma(acumulado,numero);
                break;

                case '-':
                    acumulado = subtracao(acumulado,numero);
                break;

                case 'x':
                    acumulado = multiplicacao(acumulado,numero);
                break;

                case '/':
                    acumulado = divisao(acumulado,numero);
                break;
            }
        }
        printf("\nDigite s caso queira continuar: ");
        scanf(" %c",&Resposta);
    }while(Resposta == 's'||Resposta=='S');
    return 0;
}
#endif //ex5
