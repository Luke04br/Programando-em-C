#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
//OBS.: Todos os programa devem ser finalizados pelo usuario.
#define ex2

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
    Faça um menu com uma opcao para saida do programa.
		estrutura: nome, end, cidade, estado, cep
*/
struct dados{
	char nome[10], end[50], cidade[15], estado[3], cep[9];
};
int Menu() {
	int Resposta;
	system("cls");
	printf("*-------------Menu-------------*\n");
	printf("1 - receber todos os dados\n");
	printf("2 - imprime todos os dados\n");
	printf("3 - sair\n");
	printf("\nEscolha a opção que deseja: ");
	scanf("%d",&Resposta);
	getchar();
	system("cls");
	return Resposta;
}

void entrada(struct dados info[4]) {
    int x;

    printf("*-------------Entrada-------------*\n");
    for(x = 0; x < 4; x++) {
        printf("\nDigite o nome da %dª pessoa: ", x + 1);
        gets(info[x].nome);

        printf("Insira o endereço de %s: ", info[x].nome);
        gets(info[x].end);

        printf("Insira a cidade de %s: ", info[x].nome);
        gets(info[x].cidade);

        printf("Insira siglas do estado de %s: ", info[x].nome);
        gets(info[x].estado);

        printf("Insira o CEP de %s: ", info[x].nome);
        gets(info[x].cep);

    }
}

void impressao(struct dados info[4]){
    printf("*-------------Listagem-------------*\n");
    for(x = 0; x < 4; x++){
        printf("\nNome: %s",info[x].nome);
	printf("\nEndereço: %s",info[x].end);
	printf("\nCidade: %s",info[x].cidade);
	printf("\nEstado: %s",info[x].estado);
	printf("\nNome: %s",info[x].cep);
    }
}

int main(){
	struct dados info[4];
	int x;
	setlocale(LC_ALL,"");

	for(;;){
		switch(Menu()){
			case 1:
                		entrada(info);
			break;

			case 2:
				impressao(info);
			break;

			case 3:
               			printf("*-------------Saindo-------------*\n");
				exit(0);
			break;
		}
   	 printf("\n");
	system("pause");
	}
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

int bissexto(int ano) {
    if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
            return 366;
        return 365;
}

int meses(int mes, int ano){
    if(mes == 2) {
        return bissexto(ano) == 366 ? 29 : 28;
    }
    if (mes == 4 || mes == 6 || mes == 9 ||mes == 11 )
        return 30;
    return 31;
}

int Calculo(struct Calendario DataI, struct Calendario DataF){
    int ano, mes, Soma = 0;

    //contagem da diferença se as datas tiverem 1 ano ou mais de diferença
    if(DataI.ano != DataF.ano && DataF.mes >= DataI.mes)
        for(ano = DataI.ano; ano < DataF.ano; ano++)
            Soma += bissexto(ano);

    //contando se o mes INICIAL for MENOR que o mês FINAL
    if(DataI.mes != DataF.mes && DataF.mes > DataI.mes)
        ano = DataF.ano;
        for(mes = DataI.mes; mes < DataF.mes; mes++)
            Soma += meses(mes, ano);

    //contando se o mes INICIAL for MAIOR que o mês FINAL
     if (DataI.mes != DataF.mes && DataI.mes > DataF.mes) {
        ano = DataF.ano - 1;

    //conta os mses da data INICIAL até o ano da data FINAL
        for(mes = DataI.mes; mes < 13; mes++)
             Soma += meses(mes, ano);
        ano++;
    //conta os meses do ano FINAL
        for(mes = 1; mes < DataF.mes; mes++)
             Soma += meses(mes,ano);

    if(DataI.mes != DataF.mes && DataI.dia > DataF.dia)
        Soma += (meses(mes, ano) - DataI.dia) + DataF.dia;

    if(DataI.mes == DataF.mes && DataF.dia > DataI.dia)
        Soma += DataF.dia - DataI.dia;
    }
    return Soma;
}

int main(){
    char Resposta;
    int ano, mes, TotalDias;
    struct Calendario DataI, DataF;
    setlocale(LC_ALL,"");

    //inserindo ano I
    do {
        system("cls");
        printf("Insira a data inicial");
        printf("\n\nAno: ");
        do{
            scanf(" %d",&DataI.ano);
            if(DataI.ano < 0)
                printf("O ano deve ser superior a 0: ");
        }while(DataI.ano < 0);
    ano = DataI.ano;

    //inserindo mes I
        printf("Mês: ");
        do{
            scanf(" %d",&DataI.mes);
            if(DataI.mes > 12 || DataI.mes < 1)
                printf("O mês deve ser um valor entre 1 e 12: ");
        }while(DataI.mes > 12 || DataI.mes < 1);
    mes = DataI.mes;

    //inserindo dia I
        do{
            printf("Dia: ");
            scanf(" %d",&DataI.dia);
            TotalDias = meses(mes, ano);
        if(DataI.dia > TotalDias){
            printf("O dia deve ser um valor entre 1 e %d: ", TotalDias);
        }
        }while(DataI.dia < 1 || DataI.dia > TotalDias);
        printf("\n%d/%d/%d", DataI.dia, DataI.mes, DataI.ano);

    //Inserindo ano II
        printf("\nInsira o ano da 2ª data");
        printf("\n\nAno: ");
        do{
            scanf(" %d",&DataF.ano);
            if(DataF.ano < DataI.ano)
                printf("O ano da data final deve ser superior ou igual ao ano da data inicial: ");
        }while(DataF.ano < DataI.ano);
        ano = DataF.ano;
    //inserindo mes II
        printf("Mês: ");
        do{
            scanf(" %d",&DataF.mes);
            if(DataF.mes > 12 ||  DataF.mes < 1)
                    printf("O mês da data final deve estar entre 1 e 12: ");
        else if(DataI.ano == DataF.ano && DataI.mes > DataF.mes)
                    printf("O mês da data final deve ser maior ou igual ao mês da data inicial se os anos forem iguais: ");
        }while( (DataF.mes > 12 || DataF.mes < 1) || (DataI.ano == DataF.ano && DataI.mes > DataF.mes) );
        mes = DataF.mes;
    //inserindo dia II
        printf("Dia: ");
        do{
            scanf(" %d",&DataF.dia);
            TotalDias = meses(mes, ano);
            if(DataF.dia < 1 || DataF.dia > TotalDias)
                printf("O dia deve ser um valor entre 1 e %d: ", TotalDias);
        }while(DataF.dia > TotalDias);

    printf("\nA data inicial %d/%d/%d tem %d dias de diferença da data final %d/%d/%d", DataI.dia, DataI.mes, DataI.ano, Calculo(DataI, DataF), DataF.dia, DataF.mes, DataF.ano);
    printf("\n\nDeseja inserir novos valores? (s/n)");
    scanf(" %c",&Resposta);
    }while(Resposta == 's' || Resposta == 'S');
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
	printf("*-------------Menu-------------*\n");
	printf("1 - receber todos os dados\n");
	printf("2 - imprime todos os dados\n");
	printf("3 - calcula o IMC de todas as pessoas\n");
	printf("4 - sair\n");
	printf("\nEscolha a opção que deseja: ");
	scanf("%d",&Resposta);
	getchar();
	system("cls");
	return Resposta;
}

int main(){
	struct dados pessoas[4];
	int x;
	float IMC;
	setlocale(LC_ALL,"");

	for(;;){
		switch(Menu()){
			case 1:
				printf("*-------------Entrada-------------*\n");
				for(x = 0; x < 4; x++) {
					printf("\nDigite o nome da %dª pessoa: ", x + 1);
					gets(pessoas[x].nome);
					printf("Digite o peso de %s: ", pessoas[x].nome);
					do {
                        			scanf("%f",&pessoas[x].peso);
                        			getchar();
                        			if(pessoas[x].peso < 0)
                          	  		printf("Digite um valor válido: ");
					}while(pessoas[x].peso < 0);
					printf("Digite a altura de %s: ", pessoas[x].nome);
					do {
                        			scanf("%f",&pessoas[x].altura);
                        			getchar();
                        			if(pessoas[x].altura < 0)
                           			 	printf("Digite um valor válido: ");
					}while(pessoas[x].altura < 0);
				}
			break;

			case 2:
				printf("*-------------Listagem-------------*\n");
				for(x = 0; x < 4; x++) {
					printf("xº: \n");
					printf("\nNome: %s", pessoas[x].nome);
					printf("\nPeso: %.2f", pessoas[x].peso);
					printf("\nAltura: %.2f\n", pessoas[x].altura);
				}
			break;

			case 3:
				printf("*-----------Cálculo do IMC-----------*\n");
				for(x = 0; x < 4; x++) {
					IMC = (pessoas[x].peso)/(pessoas[x].altura*pessoas[x].altura);
					printf("\n%s tem %.2f de IMC\n",pessoas[x].nome, IMC);
				}
			break;

			case 4:
				printf("*-------------Saindo-------------*\n");
				exit(0);
			break;
		}
    		printf("\n");
		system("pause");
	}
}
#endif//ex4
