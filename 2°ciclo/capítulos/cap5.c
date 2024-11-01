#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define ex5
 
//OBS.: Todos os programa devem ser finalizados pelo usuario.
#ifdef ex1
/*1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
    DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
    (Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)*/
char nome1[10],nome2[10];
int compara(){
    int resultado,x;
        for(x=0;nome1[x]!='\0';x++){
            if(nome1[x]!= nome2[x])
            break;
        }
        if(nome1[x]=='\0' && nome2[x]=='\0')
            resultado=1;
            else {resultado=0;}
return resultado;
}
int main() {
setlocale(LC_ALL,"");
int resultado;
char Resposta;
do{
    printf("\nDigite o 1° nome:");
    scanf("%[^\n]",&nome1);
    getchar();
 
    printf("\nDigite o 2° nome:");
    scanf("%[^\n]",&nome2);
    getchar();
 
    resultado = compara();
 
    if(resultado==1)
        printf("\nOs nomes são iguais!\n");
    else
        printf("\nOs nomes são diferentes!\n");
 
    printf("\nDigite s se deseja comparar mais outros dois nomes:");
    scanf("%c",&Resposta);
    getchar();
 
}while(Resposta=='s'||Resposta=='S');
 
}
#endif//ex1
 
#ifdef ex2
/*2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
    globais)
 
            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3
*/
char nome1[7],nome2[7],nome3[7],nome4[7],nome5[7];
int main() {
char Resposta;
do{
    printf("Digite o nome 1:");
    scanf("%[^\n]",&nome1);
    getchar();
 
    printf("Digite o nome 2:");
    scanf("%[^\n]",&nome2);
    getchar();
 
    printf("Digite o nome 3:");
    scanf("%[^\n]",&nome3);
    getchar();
 
    printf("Digite o nome 4:");
    scanf("%[^\n]",&nome4);
    getchar();
 
    printf("Digite o nome 5:");
    scanf("%[^\n]",&nome5);
    getchar();
 
    printf("\n\nImprimindo os nomes:\n        10        20        30        40        50\n12345678901234567890123456789012345678901234567890\n");
    printf("  %-7s                                 %-7s\n",nome1,nome5);
    printf("            %-7s             %-7s\n",nome2,nome4);
    printf("                      %-7s\n",nome3);
 
    printf("\nDigite s se deseja repetir:");
    scanf("%c",&Resposta);
    getchar();
 
}while(Resposta=='s'||Resposta=='S');
 
}
#endif//ex2
 
#ifdef ex3
/*3 - Escreva um programa que receba uma string na funcao main(). Faca uma funcao que
    calcula o comprimento de uma string recebida via teclado. Mostre o valor do
    comprimento na funcao main().
    (Declare o vetor como variavel global) (nao pode usar funcao de biblioteca)*/
#define max 1000
char str[max];
int CalculaComprimento(){
int cont=0,x;
 
    for(x = 0; str[x] != '\0'; x++){
    cont++;
    }
 
return cont;
}
int main() {
char Resposta;
int tamanho;
 
setlocale(LC_ALL,"");
    do{ str[0]='\0';
        printf("Digite um nome:");
        scanf("%[^\n]",&str);
        getchar();
 
        tamanho=CalculaComprimento();
 
        if (str[0] == '\0')
        printf("\nO tamanho do vetor é: nulo");
        else
        printf("\nO tamanho do vetor é:%d",tamanho);
 
        printf("\n\nDigite s se deseja repetir:");
        scanf(" %c",&Resposta);
        getchar();
 
    }while(Resposta=='s'||Resposta=='S');
}
#endif//ex3
 
#ifdef ex4
/*4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras maiusculas. (nao pode usar funcao de biblioteca)*/
int main() {
char A[10],Resposta;
int x;
 
setlocale(LC_ALL,"");
 
do{
    printf("Digite uma palavra ou uma frase(max 10 caracteres):");
    scanf("%[^\n]",A);
    getchar();
 
    for (x=0;A[x]!='\0';x++) {
        if (A[x]>='a' && A[x]<='z') {
            A[x] = A[x] - 32;
        }
    }
 
    printf("Conversão de todos os caracteres para maiusculo: %s",A);
 
    printf("\nDigite s se deseja repetir:");
    scanf("%c",&Resposta);
    getchar();
 
}while(Resposta=='s'||Resposta=='S');
}
#endif//ex4
 
#ifdef ex5
/*5 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas. (nao pode usar funcao de biblioteca)*/
int main() {
char A[10],Resposta;
int x;
 
setlocale(LC_ALL,"");
 
do{
    printf("Digite uma palavra ou uma frase(max 10 caracteres):");
    scanf("%[^\n]",A);
    getchar();
 
    for (x=0;A[x]!='\0';x++) {
        if (A[x]>='A' && A[x]<='Z') {
            A[x] = A[x] + 32;
        }
    }
 
    printf("Conversão de todos os caracteres para minúsculo: %s",A);
 
    printf("\nDigite s se deseja repetir:");
    scanf("%c",&Resposta);
    getchar();
 
}while(Resposta=='s'||Resposta=='S');
}
#endif//ex5
