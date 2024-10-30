#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
//OBS.: Todos os programa devem ser finalizados pelo usuario.
#define ex1

#ifdef ex1
/*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        int                 long                float     double
              unsigned int        unsigned long       char      unsigned char
*/
struct variaveis {
    int I;
    unsigned int Ui;
    long L;
    unsigned long Ul;
    float F;
    char C;
    double D;
    unsigned char Uc;
};
int main() {
    struct variaveis A;
    char Resposta;
    setlocale(LC_ALL,"");
    do {
    system("cls");
    printf("Digite o valor da variável int: ");
    scanf("%d",&A.I);
    getchar();

    printf("Digite o valor da variável unsigned int: ");
    scanf("%u",&A.Ui);
    getchar();

    printf("Digite o valor da variável long: ");
    scanf("%ld",&A.L);
    getchar();

    printf("Digite o valor da variável unsigned long: ");
    scanf("%lu",&A.Ul);
    getchar();

    printf("Digite o valor da variável float: ");
    scanf("%f",&A.F);
    getchar();

    printf("Digite o valor da variável char: ");
    scanf("%c",&A.C);
    getchar();

    printf("Digite o valor da variável double: ");
    scanf("%f",&A.D);
    getchar();

    printf("Digite o valor da variável unsigned char: ");
    scanf("%c",&A.Uc);
    getchar();

    printf("         10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-6d             %-11ld             %-45f%f", A.I, A.L, A.F, A.D);
    printf("\n%u%lu%c%c", A.Ui, A.Ul, A.C, A.Uc);

    printf("Deseja inserir novos valores? ");
    scanf("%uc",&Resposta);
    getchar();
    }while(Resposta!='s' && Resposta!='S');
    return 0;
}
#endif//ex1

#ifdef ex2
/*2 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Fa a um menu com uma opcao para saida do programa.
		estrutura: nome, end, cidade, estado, cep
*/
int main() {
    char Resposta;
    do {

    printf("Deseja inserir novos valores? ");
    scanf(%c,&Resposta);
    }while(Resposta!='s' && Resposta!='S');
    return 0;
}
#endif//ex2

#ifdef ex3
/*3 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias
    entre elas e mostre o resultado no video na funcao main().
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano
*/
int main(){
    char Resposta;
    do {

    printf("Deseja inserir novos valores? ");
    scanf(%c,&Resposta);
    }while(Resposta!='s' && Resposta!='S');
    return 0;
}
#endif//ex3

#ifdef ex4
/*4 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faca um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura
*/
int main(){
    char Resposta;
    do {

    printf("Deseja inserir novos valores? ");
    scanf(%c,&Resposta);
    }while(Resposta!='s' && Resposta!='S');
    return 0;
}
#endif//ex4
