#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex4
/****************************************************************************

			EXERCICIOS

*****************************************************************************
OBS.: Todos os programa devem ser finalizados pelo usuario.

1 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char

2 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las usando ponteiros e retorne como resultado se
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main().
    Imprima o resultado na funcao main(). Declare os vetores como variavel global

3 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel global.

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y

4 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.

5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop.
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep

6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano
*/

#ifdef ex1
int main() {
    setlocale(LC_ALL, "Portuguese");

    int i;
    long int ld;
    unsigned u;
    float f;
    double lf;
    char c;
    unsigned long lu;
    unsigned char hhu;

    char resposta;

    int *pi = &i;
    long int *pld = &ld;
    unsigned *pu = &u;
    float *pf = &f;
    double *plf = &lf;
    char *pc = &c;
    unsigned long *plu = &lu;
    unsigned char *phhu = &hhu;

    do {

        printf("Digite o valor da variável do tipo int: ");
        scanf("%i", pi);

        printf("Digite o valor da variável do tipo long: ");
        scanf("%ld", pld);

        printf("Digite o valor da variável do tipo unsigned: ");
        scanf("%u", pu);


        printf("Digite o valor da variável do tipo float: ");
        scanf("%f", pf);


        printf("Digite o valor da variável do tipo double: ");
        scanf("%lf", plf);


        printf("Digite o valor da variável do tipo char: ");
        scanf(" %c", pc);


        printf("Digite o valor da variável do tipo unsigned long: ");
        scanf("%lu", plu);


        printf("Digite o valor da variável do tipo unsigned char: ");
        scanf("%hhu", phhu);


        printf("\n        10        20        30        40        50        60        70\n");
        printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
        printf("    %-19i %-19ld %-16u\n",*pi, *pld, *pu);
        printf("              %-19.2f %-19.2lf %-6c\n", *pf, *plf, *pc);
        printf("         %-19lu %-31hhu", *plu, *phhu);

        printf("\nDigite s se deseja inserir novos dados: ");
        scanf(" %c", &resposta);


    } while (resposta == 's' || resposta == 'S');

    return 0;
}
#endif // ex1

#ifdef ex2
char nome1[11],nome2[11];

int comparar(char *pont1, char *pont2){
    int resultado,x;
        for(x=0;pont1[x]!='\0';x++){
            if(pont1[x]!= pont2[x])
            break;
        }
        if(pont1[x]=='\0' && pont2[x]=='\0')
            resultado=1;
        else {resultado=0;}

return resultado;
}

main()
{   char resposta;
    int diferenca;

    setlocale(LC_ALL,"Portuguese");
    do{
    printf("Digite a primeira string (máx 10 caracteres): ");
    scanf("%[^\n]",&nome1);
    getchar();
    nome1[11]='\0';

    printf("\nDigite a segunda string (máx 10 caracteres): ");
    scanf("%[^\n]",&nome2);
    getchar();
    nome2[11]='\0';

    comparar (nome1,nome2);

    diferenca=comparar(nome1,nome2);
    if (diferenca == 1)
        printf("\nAs strings são iguais!");
    else printf("\nAs strings são diferentes!");

    printf("\n\nDigite s se deseja inserir novos dados: ");
    scanf("%c",&resposta);
    getchar();

    }while(resposta=='s'||resposta=='S');
}
#endif // ex2

#ifdef ex3
char vet[13]= {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

pesquisa(char *pletra,char *pvet){
int x,cont=0;

for(x=0;x<13;x++){
    if (pletra == pvet[x])
        cont++;
}
return cont;
}

main()
{   char letrapesquisada,resposta;
    int resultado;

    char *pc = &letrapesquisada;

    setlocale(LC_ALL,"Portuguese");

    do{

    printf("Digite a letra que deseja pesquisar no vetor:");
    scanf("%c", pc);


    resultado = pesquisa(*pc,vet);

    if(resultado == 0)
        printf("\nNão há a letra '%c' no vetor!",*pc);
    else printf("\nA letra '%c' está no vetor!",*pc);


    printf("\nDigite s se deseja realizar uma nova pesquisa: ");
    scanf(" %c",&resposta);
    getchar();

    }while(resposta=='s'||resposta=='S');
}
#endif // ex3

#ifdef ex4
main()
{   char resposta;
    int x,numeros[100],cont;
    float media;
    int *pont[100];

    setlocale(LC_ALL,"Portuguese");

    do{
    cont=0;
    media=0;
    for(x=0;x<100;x++){
        pont[x] = &numeros[x];

        printf("Digite o número %d:",x+1);
        scanf("%d", pont[x]);

        cont++;

        if (*pont[x]<0)
            break;

    }
    if (cont > 1) {
    for(x=0;x<cont;x++){
        media += *pont[x];
    } media = media/cont;
    }else media=*pont[0];

    printf("\n A média dos números digitados é: %.2f",media);

    printf("\nDigite s se deseja realizar uma novo cálculo:");
    scanf(" %c",&resposta);
    getchar();
 }while(resposta=='s'||resposta=='S');
}
#endif // ex4

#ifdef ex5
struct registro{
char nome[20];
char end[30];
char cidade[20];
char estado [2];
int cep;
};
struct registro dados[4];

void entrada(){
struct registro *pont = &dados[0];
int x;

    for(x=0;x<4;x++){
    printf("\nDigite o nome %d:",x+1);
    scanf("%[^\n]",&(pont+x) -> nome);
    getchar();
    printf("\nDigite o endereço %d:",x+1);
    scanf("%[^\n]",&(pont+x) -> end);
    getchar();
    printf("\nDigite a cidade %d:",x+1);
    scanf("%[^\n]",&(pont+x) -> cidade);
    getchar();
    printf("\nDigite o estado %d(abreviado, exemplo 'SP'):",x+1);
    scanf("%[^\n]",&(pont+x) -> estado);
    getchar();
    printf("\nDigite o CEP %d(somente números):",x+1);
    scanf("%d",&(pont+x) -> cep);
    getchar();
    }
}

void imprimir(){
int x;
char resposta;
struct registro *pont = &dados[0];
system("cls");

        for(x=0;x<4;x++){
        printf("\n\no nome %d é:%s",x+1,(pont+x) -> nome);
        printf("\no endereço %d é: %s",x+1,(pont+x) -> end);
        printf("\na cidade %d é: %s",x+1,(pont+x) -> cidade);
        printf("\no estado %d é: %s",x+1,(pont+x) -> estado);
        printf("\no cep %d é: %d",x+1,(pont+x) -> cep);
        }
}

main()
{   char resposta;

    setlocale(LC_ALL,"Portuguese");

    do{
    entrada();
    imprimir();

    printf("\nDigite s se deseja realizar novos registros:");
    scanf(" %c",&resposta);
    getchar();

 }while(resposta=='s'||resposta=='S');
}

#endif // ex5

#ifdef ex6
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>  // Necessário para o uso de malloc e free

struct Calendario {
    int dia, mes, ano;
};

int bissexto(int ano) {

    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
        return 366;
    return 365;
}

int meses(int mes, int ano) {

    if (mes == 2) {
        return bissexto(ano) == 366 ? 29 : 28;
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        return 30;
    return 31;
}

int Calculo(struct Calendario *Data1, struct Calendario *Data2) {
    int ano, mes, Soma = 0;


    if (Data1->ano != Data2->ano || Data1->mes <= Data2->mes) {
        for (ano = Data1->ano; ano < Data2->ano; ano++) {
            Soma += bissexto(ano);
        }
    }


    if (Data1->mes != Data2->mes || Data2->mes > Data1->mes) {
        ano = Data2->ano;
        for (mes = Data1->mes; mes < Data2->mes; mes++) {
            Soma += meses(mes, ano);
        }
    }


    if (Data1->mes == Data2->mes && Data1->dia < Data2->dia) {
        Soma += Data2->dia - Data1->dia;
    }

    return Soma;
}

int main() {
    char resposta;
    struct Calendario Data[2];
    int ano, mes, TotalDias;

    setlocale(LC_ALL, "");

    do {
        system("cls");

        printf("Insira a data inicial\n");
        printf("Ano: ");
        do {
            scanf("%d", &Data[0].ano);
            if (Data[0].ano < 0)
                printf("O ano deve ser superior a 0: ");
        } while (Data[0].ano < 0);
        ano = Data[0].ano;

        printf("Mês: ");
        do {
            scanf("%d", &Data[0].mes);
            if (Data[0].mes < 1 || Data[0].mes > 12)
                printf("O mês deve ser um valor entre 1 e 12: ");
        } while (Data[0].mes < 1 || Data[0].mes > 12);
        mes = Data[0].mes;

        do {
            printf("Dia: ");
            scanf("%d", &Data[0].dia);
            TotalDias = meses(mes, ano);
            if (Data[0].dia < 1 || Data[0].dia > TotalDias)
                printf("O dia deve ser um valor entre 1 e %d: ", TotalDias);
        } while (Data[0].dia < 1 || Data[0].dia > TotalDias);

        printf("\nData inicial: %d/%d/%d\n", Data[0].dia, Data[0].mes, Data[0].ano);


        printf("\nInsira a data final\n");
        printf("Ano: ");
        do {
            scanf("%d", &Data[1].ano);
            if (Data[1].ano < Data[0].ano)
                printf("O ano da data final deve ser superior ou igual ao ano da data inicial: ");
        } while (Data[1].ano < Data[0].ano);
        ano = Data[1].ano;

        printf("Mês: ");
        do {
            scanf("%d", &Data[1].mes);
            if (Data[1].mes < 1 || Data[1].mes > 12)
                printf("O mês da data final deve estar entre 1 e 12: ");
            else if (Data[1].ano == Data[0].ano && Data[1].mes < Data[0].mes)
                printf("O mês da data final deve ser maior ou igual ao mês da data inicial se os anos forem iguais: ");
        } while (Data[1].mes < 1 || Data[1].mes > 12 || (Data[1].ano == Data[0].ano && Data[1].mes < Data[0].mes));

        printf("Dia: ");
        do {
            scanf("%d", &Data[1].dia);
            TotalDias = meses(Data[1].mes, ano);
            if (Data[1].dia < 1 || Data[1].dia > TotalDias)
                printf("O dia deve ser um valor entre 1 e %d: ", TotalDias);
        } while (Data[1].dia < 1 || Data[1].dia > TotalDias);


        int TotalDiasDiferenca = Calculo(&Data[0], &Data[1]);
        printf("\nA data inicial %d/%d/%d tem %d dias de diferença da data final %d/%d/%d\n",
               Data[0].dia, Data[0].mes, Data[0].ano, TotalDiasDiferenca,
               Data[1].dia, Data[1].mes, Data[1].ano);

        printf("\n\nDeseja inserir novos valores? (s/n): ");
        scanf(" %c", &resposta);
    } while (resposta == 's' || resposta == 'S');

    return 0;
}

#endif // ex6

