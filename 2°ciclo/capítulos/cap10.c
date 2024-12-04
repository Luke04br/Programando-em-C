#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex2

/*
1 - Escreva um programa para criar e abrir um arquivo texto de nome "arq.txt".
    Receba via teclado diversos caracteres (um por vezes) e escreva-os
    nesse arquivo. O caracter '0' finaliza a entrada de dados. Abra o arquivo
    "arq.txt", leia e imprima na tela todos os caracteres armazenados no
    arquivo (um por vezes).

2 - Escreva um programa para gerenciar uma agenda de contatos. Para cada contato
    armazene o nome, o telefone e o aniversario (dia e mes) em uma estrutura de
    dados. Utilize um vetor de estrutura de 4 elementos como variavel LOCAL na
    funcao main(). Utilize ponteiros para passar o vetor de estrutura para
    as funcoes. Sempre que o programa for encerrado, os contatos devem ser
    escritos no arquivo e quando o programa iniciar os contatos devem ser lidos
    do arquivo.
    O programa deve ter as seguintes opcoes:(cada opcao do menu e' um funcao)
    1 - inserir contato
    2 - listar todos os contatos
    3 - pesquisar um contato pelo nome
    4 - listar os contatos cujo nome inicia com uma letra digitada
    5 - imprimir os aniversariantes do mês.
    6 - altera contato
    7 - exclui contato
    8 - saida

3 - Escreva um programa para controle de um cadastro de clientes. Para cada
    registro sera' armazenado nome, email e celular numa estrutura de dados.
    A unica estrutura de dados e' uma variavel LOCAL na funcao main().
    Escreva os registros direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros para
    passar parametros para as funcoes.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui registros
    2 - listar todos os registros
    3 - pesquisar registro pelo nome
    4 - altera registro
    5 - exclui registro
    6 - saida



4 - Escreva um programa para o controle de mercadorias em uma dispensa
    domestica. Para cada produto sera' armazenado um codigo numerico, nome
    do produto e quantidade atual numa estrutura de dados. A unica estrutura
    de dados deve ser declarada como variavel LOCAL na funcao main(). Escreva
    os itens das mercadorias direto no arquivo. (utilize a funcao fseek quando
    necessario). NAO pode usar vetor de estruturas. Utilize ponteiros.
    O programa deve ter as seguintes opcoes: (cada opcao do menu e' um funcao)
    1 - inclui produtos
    2 - listar todos os produtos
    3 - pesquisar uma mercadoria pela descrição
    4 - listar os produtos não disponíveis.
    5 - alterar a quantidade atual
    6 - altera produtos
    7 - exclui produtos
    8 - saida
*/

#ifdef ex1
int main() {
    FILE *arquivo;
    char caractere;

    setlocale(LC_ALL,"Portuguese");

    arquivo = fopen("arq.txt", "w");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo para escrita\n");
        return 1;
    }

    printf("Digite caracteres para armazenar no arquivo (digite '0' para finalizar):\n");

    while (1) {
        caractere = getchar();
        if (caractere == '0') {
            break;
        }
        fprintf(arquivo, "%c", caractere);
    }
    fclose(arquivo);

    arquivo = fopen("arq.txt", "r");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo para leitura\n");
        return 1;
    }

    printf("\nConteúdo do arquivo 'arq.txt':\n");

   while (fscanf(arquivo, "%c", &caractere) == 1) {
        putchar(caractere);
    }

    fclose(arquivo);

    return 0;
}
#endif // ex1

#ifdef ex2
struct registro {
char nome[20];
int telefone;
int dia;
int mes;
};

void entrada(struct registro *pont){
int x;

    for(x=0;x<4;x++){
    printf("\nDigite o nome %d:",x+1);
    scanf("%[^\n]",&(pont+x) -> nome);
    getchar();
    printf("\nDigite o telefone %d:",x+1);
    scanf("%d",&(pont+x) -> telefone);
    getchar();
    printf("\nDigite o dia do aniverário %d:",x+1);
    scanf("%d",&(pont+x) -> dia);
    getchar();
    printf("\nDigite o mês do aniversário %d",x+1);
    scanf("%d",&(pont+x) -> mes);
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
        printf("\no telefone %d é: %d",x+1,(pont+x) -> telefone);
        printf("\na aniversário %d é: %d/%d",x+1,(pont+x) -> dia,(pont+x) -> mes);
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
        printf("\nTelefone: %d",(pont+resultado) -> telefone);
        printf("\nAniversário: %d/%d",(pont+resultado) -> dia,(pont+resultado) -> mes);

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
    printf("Digite o novo telefone: ");
    scanf("%d",&pont[x].telefone);
    getchar();
    printf("Digite o novo dia do aniversário: ");
    scanf("%d",&pont[x].dia);
    getchar();
    printf("Digite o novo mes do aniversário: ");
    scanf("%d",&pont[x].mes);
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
    printf("1-Inseir registros\n2-Listagem\n3-Sair\n4-Procura\n5-Altera\n6-Exclui");
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
#endif // ex2

