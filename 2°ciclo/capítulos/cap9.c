#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex6

/*

1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.

    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o

    conteudo de cada um dos membros numa funcao e imprima-os no video no

    seguinte formato(tamb m numa fun  o).

    estrutura: char, int, long, float, double, unsigned char, unsigned int,

    unsigned long

            10        20        30        40        50        60        70

    1234567890123456789012345678901234567890123456789012345678901234567890

        char      int       long                float               double

              unsigned char       unsigned int        unsigned long



2 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres

    passando como parametro ponteiro.

    Os vetores devem ser declarados como variaveis LOCAIS na funcao main().

    Escreva uma funcao para comparar as 2 strings. Passe como parametros para

    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1

    ou se DIFERENTES 0. Mostre o resultado no video na funcao main().



3 - Escreva um programa que receba n valores via teclado e receba tambem a

    operacao a ser executada. Quando for digitado "=" o programa deve mostrar

    o resultado acumulado dos n valores. As operacoes aritmeticas e a entrada

    de dados devem ser funcoes que recebe os valores usando ponteiros.

    As variaveis sao LOCAIS na funcao main().



4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva

    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.

    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao

    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa

    usando ponteiros.(utilize o comando return).

    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y



5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas

    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros

    sequencialmente pelo teclado numa funcao e imprima todos os registros no

    video em outra funcao. Faca um menu. Utilize ponteiros nas funcoes.

    Coloque no menu a opcao de sair tambem. Utilize o comando switch.

    (vetor de estruturas)

     estutura: nome, end, cidade, estado, cep



6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e

    exclui um registro sempre usando ponteiros.

*/

#ifdef ex1

struct tipos{
       char c;
       int i;
       long l;
       float f;
       double lf;
       unsigned char hhu;
       unsigned int u;
       unsigned long lu;
};

void receber(struct tipos *pont){
printf("Digite o valor da variável do tipo char: ");
scanf(" %c",&pont->c);

printf("Digite o valor da variável do tipo int: ");
scanf("%i",&pont -> i);

printf("Digite o valor da variável do tipo long: ");
scanf("%ld",&pont -> l);

printf("Digite o valor da variável do tipo float: ");
scanf("%f",&pont -> f);

printf("Digite o valor da variável do tipo double: ");
scanf("%lf",&pont -> lf);

printf("Digite o valor da variável do tipo unsigned char: ");
scanf("%hhu",&pont -> hhu);

printf("Digite o valor da variável do tipo unsigned int: ");
scanf("%u",&pont -> u);

printf("Digite o valor da variável do tipo unsigned long: ");
scanf("%lu",&pont -> lu);
}
main()
{
    setlocale(LC_ALL,"Portuguese");
   struct tipos dados;
   char resposta;
   struct tipos *prt = &dados;

    do{
        receber(prt);

        printf("        10        20        30        40        50        60        70\n");
        printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
        printf("    %-9c %-9i %-19ld %-19.2f %-6.2lf\n",prt->c,prt->i,prt->l,prt->f,prt->lf);
        printf("          %-19hhu %-19u %-21lu\n",prt->hhu,prt->u,prt->lu);

        printf("Digite s se deseja inserir novos dados:");
        scanf(" %c",&resposta);
    }while(resposta =='s'||resposta=='S');
}
#endif //ex1

#ifdef ex2
void receber(char *pont1, char *pont2){
    printf("Digite a primeira string (máx 10 caracteres): ");
    scanf("%[^\n]",pont1);
    getchar();
    pont1[11]='\0';

    printf("\nDigite a segunda string (máx 10 caracteres): ");
    scanf("%[^\n]",pont2);
    getchar();
    pont2[11]='\0';
}

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
    char nome1[11],nome2[11];
    int diferenca;

    setlocale(LC_ALL,"Portuguese");

    do{
    receber(nome1,nome2);

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
int entrada(int *pi[],char *pc[]){
int x=0;
int cont=0;

printf("Digite os valores e a(s) operação(ões) aritmética(s) a serem calculados: (digite '=' para receber o resultado:");

for(x=0;pc!= '=';x++){
    scanf("%d",pi[x]);
    scanf("%c",pc[x]);
    getchar();
    cont++;
}
return cont;
}

int soma(int *p1, int *p2){
int resultadosoma;

    resultadosoma=*p1+*p2;
return resultadosoma;
}

int subt(int *p3, int *p4){
int resultadosubt;

    resultadosubt=*p3-*p4;
return resultadosubt;
}

float divs(float *p5, float *p6){
float resultadodiv;

    resultadodiv=*p5 / *p6;
return resultadodiv;
}

int mult(int *p7, int *p8){
int resultadomult;

resultadomult=*p7 * *p8;

return resultadomult;
}
main()
{   char resposta;
    int tamanho, cont, x;
    float resultadoacumulado;
    int numero[tamanho];
    char operacao[tamanho];

    setlocale(LC_ALL,"Portuguese");

    do{
    cont = entrada(numero,operacao);

    for(x=0;x<cont;x++){
    printf("%d",numero[x]);
    printf(" %c",operacao[x]);}

    for(x=0;x<cont;x++){
        switch (operacao[x]){
        case '+':
        resultadoacumulado += soma(numero[x],numero[x+1]);
        break;
        case '-':
        resultadoacumulado += subt(numero[x],numero[x+1]);
        break;
        case '/':
        resultadoacumulado += divs(numero[x],numero[x+1]);
        break;
        case '*':
        resultadoacumulado += mult(numero[x],numero[x+1]);
        break;
        }
    }
    printf("o resutado é: %f", resultadoacumulado);
    printf("Digite s se deseja inserir novos dados: ");
    scanf(" %c",&resposta);
    }while(resposta=='s'||resposta=='S');
}
#endif // ex3

#ifdef ex4
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
    char vet[13]= {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
    int resultado;

    setlocale(LC_ALL,"Portuguese");

    do{
    printf("Digite a letra que deseja pesquisar no vetor:");
    scanf("%c",&letrapesquisada);

    char *pc = &letrapesquisada;

    resultado = pesquisa(*pc,vet);

    if(resultado == 0)
        printf("\nNão há a letra '%c' no vetor!",*pc);
    else printf("\nA letra '%c' está no vetor!",*pc);

    printf("\nDigite s se deseja realizar uma nova pesquisa: ");
    scanf(" %c",&resposta);
    getchar();
    }while(resposta=='s'||resposta=='S');
}
#endif // ex4

#ifdef ex5
struct registro {
char nome[20];
char end[50];
char cidade[30];
char estado[2];
int cep[8];
};

void entrada(struct registro *pont){
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
void imprimir(struct registro *pont){
int x;
char resposta;

    do{
        for(x=0;x<4;x++){
        printf("\n\no nome %d é:%s",x+1,(pont+x) -> nome);
        printf("\no endereço %d é: %s",x+1,(pont+x) -> end);
        printf("\na cidade %d é: %s",x+1,(pont+x) -> cidade);
        printf("\no estado %d é: %s",x+1,(pont+x) -> estado);
        printf("\no cep %d é: %d",x+1,(pont+x) -> cep);

        }
    printf("\n\nDigite 's' se deseja voltar ao menu:");
    scanf("%c",&resposta);
    getchar();
    }while(resposta != 's'||resposta!='S');
}

void sair(){
system ("cls");
exit(0);}

main()
{   int resposta;
    struct registro dados[4];
    struct registro *str = &dados[0];

    setlocale(LC_ALL,"Portuguese");

    do{
    printf("******************** - menu - ********************\n\n");
    printf("1-Inseir registros\n2-Visualizar os registros\n3-Sair");
    printf("\n\nDigite para onde deseja seguir:");

    do{
    scanf("%d",&resposta);
    getchar();
    if (resposta!=1&&resposta!=2&&resposta!=3)
        printf("\nDigite uma das opções do menu:");
    }while(resposta!=1&&resposta!=2&&resposta!=3);

    switch (resposta){
    case 1:
        entrada(str);
        break;
    case 2:
        imprimir(str);
        break;
    case 3:
         sair();
        break;
    }
    system("cls");
    }while(resposta!=3);
}
#endif // ex5

#ifdef ex6
struct registro {
char nome[20];
char end[50];
char cidade[30];
char estado[2];
int cep;
};

void entrada(struct registro *pont){
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

void imprimir(struct registro *pont){
int x;
char resposta;

    do{

        for(x=0;x<4;x++){
        if ((pont+x) -> nome[0] != '*'){
        printf("\n\no nome %d é:%s",x+1,(pont+x) -> nome);
        printf("\no endereço %d é: %s",x+1,(pont+x) -> end);
        printf("\na cidade %d é: %s",x+1,(pont+x) -> cidade);
        printf("\no estado %d é: %s",x+1,(pont+x) -> estado);
        printf("\no cep %d é: %d",x+1,(pont+x) -> cep);
        }
        }

    printf("\n\nDigite 's' se deseja voltar ao menu:");
    scanf(" %c",&resposta);
    getchar();
    }while(resposta != 's' && resposta!='S');
}

void sair(){
system ("cls");
exit(0);}

int pesquisa(struct registro *pont) {
char nomeprocurado[20];
int resultado = 0;
int x, y;

    printf("Digite o nome do registro que deseja pesquisar: ");
    scanf("%[^\n]",&nomeprocurado);
    getchar();
    for (x=0;x<4;x++) {
        for (y = 0; (pont+x) -> nome[y] != '\0' && nomeprocurado[y] != '\0'; y++) {
        if ((pont+x) -> nome[y] != nomeprocurado[y]) {
            break;
        }
        }
        if ((pont + x)->nome[y] == '\0' && nomeprocurado[y] == '\0') {
            return x;
        }
    }

    return -1;
}

void procura(struct registro *pont){
int resultado=0;
char resposta;

    do{
    resultado = pesquisa(pont);

    if (resultado == -1)
      printf("Esse nome não está registrado!");

    else{
        printf("\nO nome %s está registrado! Veja:",(pont+resultado) -> nome);
        printf("\nNome: %s",(pont+resultado) -> nome);
        printf("\nEdereço: %s",(pont+resultado) -> end);
        printf("\nCidade: %s",(pont+resultado) -> cidade);
        printf("\nEstado: %s",(pont+resultado) -> estado);
        printf("\nCEP: %i",(pont+resultado) -> cep);
    }

    printf("\n\nDigite 's' se deseja voltar ao menu:");
    scanf(" %c",&resposta);
    getchar();


}while(resposta != 's' && resposta!='S');
}

void altera(struct registro *pont){
char nomeprocurado[20], resposta;
int x;

do{
    x=pesquisa(pont);

    if(x==-1)
    printf("Não há nenhum registro com esse nome");

    else{
    printf("Digite o novo nome: ");
    scanf("%[^\n]",&pont[x].nome);
    getchar();
    printf("Digite o novo endereço: ");
    scanf("%[^\n]",&pont[x].end);
    getchar();
    printf("Digite a nova cidade: ");
    scanf("%[^\n]",&pont[x].cidade);
    getchar();
    printf("Digite o novo estado (abreviado, exemplo 'SP'): ");
    scanf("%[^\n]",&pont[x].estado);
    getchar();
    printf("Digite o novo CEP (somente números): ");
    scanf("%d",&pont[x].cep);
    getchar();

    printf("\nRegistro alterado com sucesso!\n");
    }
    printf("\n\nDigite 's' se deseja voltar ao menu:");
    scanf(" %c",&resposta);
    getchar();
}while(resposta != 's' && resposta!='S');
}

void exclui(struct registro *pont){
int x;
char resposta;

do{
    x=pesquisa(pont);
    
    if(x==-1)
    printf("Não há nenhum registro com esse nome");

    else{
    printf("\nDigite s se deseja mesmo excluir o registro %s",*(pont+x)->nome);
    scanf(" %c",&resposta);
    getchar;
    if(resposta=='s'||resposta=='S'){
    *pont[x].nome = '*';
     printf("\nRegistro excluído com sucesso!\n");}
    }

    printf("\n\nDigite 's' se deseja voltar ao menu:");
    scanf(" %c",&resposta);
    getchar();
}while(resposta != 's' && resposta!='S');
}


main()
{   int resposta;
    struct registro dados[4];
    struct registro *str = &dados[0];

    setlocale(LC_ALL,"Portuguese");

    do{

    printf("******************** - menu - ********************\n\n");
    printf("1-Inseir registros\n2-Visualizar os registros\n3-Sair\n4-Procura\n5-Altera\n6-Exclui");
    printf("\n\nDigite para onde deseja seguir:");

    do{
    scanf("%d",&resposta);
    getchar();

    if (resposta!=1&&resposta!=2&&resposta!=3&&resposta!=4&&resposta!=5&&resposta!=6)
        printf("\nDigite uma das opções do menu:");
    }while(resposta!=1&&resposta!=2&&resposta!=3&&resposta!=4&&resposta!=5&&resposta!=6);

    switch (resposta){
    case 1:
        entrada(str);
        break;
    case 2:
        imprimir(str);
        break;
    case 3:
        sair();
        break;
    case 4:
        procura(str);
        break;
    case 5:
        altera(str);
        break;
    case 6:
        exclui(str);
        break;
    }
    system("cls");
    }while(resposta!=3);
}
#endif // ex6
