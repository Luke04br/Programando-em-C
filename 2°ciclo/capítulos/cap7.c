#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
//OBS.: Todos os programa devem ser finalizados pelo usuario.
#define ex3

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
struct info{
	char nome[10], end[50], cidade[15], estado[3], cep[9];
};

void entrada(){
}

void impressao(struct info dados[4]){
}
int main() {
	struct info dados[4];
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
struct Calendario{
        int dia, mes, ano;
};

int meses(int ano, int mes){
	if(mes == 1) return 0;
	if(mes == 2) {
		if(bissexto(ano) == 366)
			return 29
		else return 28
	}
	if (mes == 4 || mes == 6 || mes == 9 ||mes == 11 ) return 30;
	if(mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) return 31;
}

int bissexto(int ano){
	if((ano % 4 == 0 && ano % 100 != 0) || ano % 400)
            return 366;
        else
            return 365;
}

unsigned int Calculo(struct Calendario DataI, struct Calendario DataII) {
    int ano, mes, SomaI = 0, SomaII = 0;
	
//calcula os dias totais da DataI
	for(ano = 0; ano < DataI.ano; ano++) 
        	SomaI += bissexto(ano);
	for(mes = 1; mes < DataI.mes; mes++)
		SomaI += meses(ano, mes);
	Soma += DataI.dia;
	
//calcula os dias totais da DataII
	for(ano = 0; ano < DataII.ano; ano++) 
        	SomaII += bissexto(ano);
	for(mes = 1; mes < DataII.mes; mes++)
		SomaII += meses(ano, mes);
	SomaII += DataII.dia;
	
	return SomaI - SomaII
}

int main(){
    char Resposta;
    struct Calendario DataI, DataII;
    do {
        printf("Insira o ano da 1ª data: ");
        scanf("%d",&DataI.ano);
	printf("Insira o mes da 1ª data: ");
	do{
        	scanf("%d",&DataI.mes);
		if(DataI.mes>12 || DataI.mes<1)
			printf("O mês deve ser um valor entre 1 e 12: ");
	}while(DataI.mes>12 || DataI.mes<1);
	do{
        printf("Insira o dia da 1ª data: ");
        scanf("%d",&DataI.dia);
	}while();

        printf("Insira o ano da 2ª data: ");
        scanf(" %d",&DataII.ano);
        printf("Insira o mes da 2ª data: ");
        scanf(" %d",&DataII.mes);
        printf("Insira o dia da 2ª data: ");
        scanf(" %d",&DataII.dia);

	printf("As datas tem %u dias de diferença", Calculo(DataI, DataII));

	printf("Deseja inserir novos valores? (s/n)");
	scanf("%c",&Resposta);
	getchar();
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
struct dados{
	char nome[10];
	float peso, altura;
};

int Menu() {
	int Resposta;
	system("cls");
	printf("*-------------Menu-------------*\n);
	printf("1 - receber todos os dados"\n);
	printf("2 - imprime todos os dados"\n);
	printf("3 - calcula o IMC de todas as pessoas\n");
	printf("4 - sair\n");
	printf("Escolha a opção que deseja: ");
	scanf("%d".&Resposta);
	getchar();
	system("cls");
	return Resposta;
}

int main(){
	struct dados pessoas[4];
	int x;
	setlocale(LC_ALL,"");
	
	for(;;){
		switch(Menu()){
			case 1:
				printf("*-------------Entrada-------------*");
				for(x = 0; x < 4; x++) {
					printf("\nDigite o nome da xª pessoa: ", x + 1);
					gets(pessoas[x].nome);
					printf("\nDigite o peso de %s: ", pessoas[x].nome);
					scanf("%f",&pessoas[x].peso);
					printf("\nDigite a altura de %s: ", pessoas[x].nome);
					scanf("%f",&pessoas[x].altura);
				}
				system("pause");
			break;

			case 2:
				printf("*-------------Listagem-------------*");
				for(x = 0; x < 4; x++) {
					printf("xº:\n")
					printf("\nNome: %s", pessoas[x].nome);
					printf("\nPeso: %f", pessoas[x].peso);
					printf("\nAltura: %f\n", pessoas[x].peso);
					}
			break;

			case 3:
				printf("*-------------Cálculo-------------*");
			break;

			case 4:
				printf("*-------------Saindo-------------*");
				exit(0);
			break;
		}
	}
}
	

    printf("Deseja inserir novos valores? ");
    scanf(%c,&Resposta);
    }while(Resposta!='s' && Resposta!='S');
    return 0;
}
#endif//ex4
