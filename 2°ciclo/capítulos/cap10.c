#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ex3

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
    printf("\nDigite o mês do aniversário %d:",x+1);
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

void procuraInicial(struct registro *pont){
 int x,cont;
 char inicial,resposta;
do{
    printf("Digite a inicial que deseja pesquisar: ");
    scanf("%c",&inicial);
    getchar();
    cont = 0;

    for (x=0;x<4;x++) {
    if ((pont+x) -> nome[0] == inicial) {
    printf("\n\nNome: %s",(pont+x) -> nome);
    printf("\nTelefone: %d",(pont+x) -> telefone);
    printf("\nAniversário: %d/%d",(pont+x) -> dia,(pont+x) -> mes);
    cont++;
    }
    }
    if (cont==0){
        printf("Não há nenhum registro com a inicial");
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

void aniversariantes(struct registro *pont){
int x,mes,cont;
char resposta;

do{
    printf("Digite o mes que deseja pesquisar os aniversariantes:");
    scanf("%d",&mes);

    cont =0;

    for(x=0;x<4;x++){
        if ((pont+x) -> mes == mes){
        printf("\n\nNome: %s",(pont+x) -> nome);
        printf("\nTelefone: %d",(pont+x) -> telefone);
        printf("\nAniversário: %d/%d",(pont+x) -> dia,(pont+x) -> mes);
        cont++;
    }
    }

    if (cont==0){
        printf("Não há nenhum aniversariante no mes pesquisado");
    }

    printf("\n\nDigite 's' se deseja voltar ao menu:");
    scanf(" %c",&resposta);
    getchar();
}while(resposta != 's' && resposta!='S');
}

int main() {
    int resposta;
    struct registro dados[4];
    struct registro *str = &dados[0];
    setlocale(LC_ALL, "Portuguese");


    FILE *arquivo = fopen("contatos.txt", "r");
    if (arquivo != NULL) {
        for (int x = 0; x < 4; x++) {
            fscanf(arquivo, " %[^\n]", (str + x)->nome);
            fscanf(arquivo, "%d", &(str + x)->telefone);
            fscanf(arquivo, "%d", &(str + x)->dia);
            fscanf(arquivo, "%d", &(str + x)->mes);
        }
        fclose(arquivo);
    }

    do {
        printf("******************** - menu - ********************\n\n");
        printf("1-Inseir contato\n2-Listagem\n3-Procurar\n4-Procurar pela inicial\n5-Aniversariante do mês\n6-Altera\n7-Exclui\n8-Sair");
        printf("\n\nDigite para onde deseja seguir:");

        do {
            scanf("%d", &resposta);
            getchar();

            if (resposta < 1 || resposta > 8)
                printf("\nDigite uma das opções do menu:");
        } while (resposta < 1 || resposta > 8);

        switch (resposta) {
            case 1:
                entrada(str);
                break;
            case 2:
                imprimir(str);
                break;
            case 3:
                procura(str);
                break;
            case 4:
                procuraInicial(str);
                break;
            case 5:
                aniversariantes(str);
                break;
            case 6:
                altera(str);
                break;
            case 7:
                exclui(str);
                break;
            case 8:

                arquivo = fopen("contatos.txt", "w");
                if (arquivo != NULL) {
                    for (int x = 0; x < 4; x++) {
                        fprintf(arquivo, "%s\n", (str + x)->nome);
                        fprintf(arquivo, "%d\n", (str + x)->telefone);
                        fprintf(arquivo, "%d\n", (str + x)->dia);
                        fprintf(arquivo, "%d\n", (str + x)->mes);
                    }
                    fclose(arquivo);
                }
                sair();
                break;
            default:
                break;
        }
    } while (resposta != 8);

    return 0;
}
#endif // ex2

#ifdef ex3
struct cliente {
    char nome[50];
    char email[50];
    char celular[15];
};

void incluir_registro(FILE *arquivo) {
    struct cliente c;
    fseek(arquivo, 0, SEEK_END);


    printf("\nDigite o nome do cliente: ");
    fgets(c.nome, sizeof(c.nome), stdin);
    printf("Digite o email do cliente: ");
    fgets(c.email, sizeof(c.email), stdin);
    printf("Digite o celular do cliente: ");
    fgets(c.celular, sizeof(c.celular), stdin);

    for (int i = 0; c.nome[i] != '\0'; i++) {
        if (c.nome[i] == '\n') {
            c.nome[i] = '\0';
            break;
        }
    }
    for (int i = 0; c.email[i] != '\0'; i++) {
        if (c.email[i] == '\n') {
            c.email[i] = '\0';
            break;
        }
    }
    for (int i = 0; c.celular[i] != '\0'; i++) {
        if (c.celular[i] == '\n') {
            c.celular[i] = '\0';
            break;
        }
    }

    fwrite(&c, sizeof(struct cliente), 1, arquivo);
    printf("Registro adicionado com sucesso!\n");
}


void listar_registros(FILE *arquivo) {
    struct cliente c;
    fseek(arquivo, 0, SEEK_SET);

    printf("\n** Lista de Registros **\n");
    while (fread(&c, sizeof(struct cliente), 1, arquivo) == 1) {
        printf("\nNome: %s\nEmail: %s\nCelular: %s\n", c.nome, c.email, c.celular);
    }
}


int pesquisar_registro(FILE *arquivo) {
    struct cliente c;
    char nome_procurado[50];
    fseek(arquivo, 0, SEEK_SET);

    while (fread(&c, sizeof(struct cliente), 1, arquivo) == 1) {
        int i = 0;
        while (c.nome[i] == nome_procurado[i] && c.nome[i] != '\0' && nome_procurado[i] != '\0') {
            i++;
        }
        if (c.nome[i] == '\0' && nome_procurado[i] == '\0') {
            return 1;
        }
    }
    return 0;
}

void alterar_registro(FILE *arquivo) {
    struct cliente c;
    char nome_procurado[50];
    printf("\nDigite o nome do cliente que deseja alterar: ");
    fgets(nome_procurado, sizeof(nome_procurado), stdin);

    for (int i = 0; nome_procurado[i] != '\0'; i++) {
        if (nome_procurado[i] == '\n') {
            nome_procurado[i] = '\0';
            break;
        }
    }

    if (pesquisar_registro(arquivo)) {
        printf("Cliente encontrado. Digite os novos dados:\n");

        printf("Digite o novo nome: ");
        fgets(c.nome, sizeof(c.nome), stdin);
        printf("Digite o novo email: ");
        fgets(c.email, sizeof(c.email), stdin);
        printf("Digite o novo celular: ");
        fgets(c.celular, sizeof(c.celular), stdin);

        for (int i = 0; c.nome[i] != '\0'; i++) {
            if (c.nome[i] == '\n') {
                c.nome[i] = '\0';
                break;
            }
        }
        for (int i = 0; c.email[i] != '\0'; i++) {
            if (c.email[i] == '\n') {
                c.email[i] = '\0';
                break;
            }
        }
        for (int i = 0; c.celular[i] != '\0'; i++) {
            if (c.celular[i] == '\n') {
                c.celular[i] = '\0';
                break;
            }
        }

        fseek(arquivo, 0, SEEK_SET);
        FILE *temp = fopen("temp.dat", "wb");
        while (fread(&c, sizeof(struct cliente), 1, arquivo) == 1) {
            fwrite(&c, sizeof(struct cliente), 1, temp);
        }
        fclose(arquivo);
        fclose(temp);
        remove("clientes.dat");
        rename("temp.dat", "clientes.dat");

        printf("Registro alterado com sucesso!\n");
    } else {
        printf("Cliente não encontrado!\n");
    }
}


void excluir_registro(FILE *arquivo) {
    struct cliente c;
    char nome_procurado[50];
    printf("\nDigite o nome do cliente que deseja excluir: ");
    fgets(nome_procurado, sizeof(nome_procurado), stdin);

    for (int i = 0; nome_procurado[i] != '\0'; i++) {
        if (nome_procurado[i] == '\n') {
            nome_procurado[i] = '\0';
            break;
        }
    }

    if (pesquisar_registro(arquivo)) {
        printf("Cliente encontrado. Excluindo...\n");

        fseek(arquivo, 0, SEEK_SET);
        FILE *temp = fopen("temp.dat", "wb");
        while (fread(&c, sizeof(struct cliente), 1, arquivo) == 1) {
            if (strcmp(c.nome, nome_procurado) != 0) {
                fwrite(&c, sizeof(struct cliente), 1, temp);
            }
        }
        fclose(arquivo);
        fclose(temp);
        remove("clientes.dat");
        rename("temp.dat", "clientes.dat");
        printf("Registro excluído com sucesso!\n");
    } else {
        printf("Cliente não encontrado!\n");
    }
}

int main() {
    FILE *arquivo;
    int opcao;
    
     setlocale(LC_ALL,"Portuguese");

    arquivo = fopen("clientes.dat", "r+b");
    if (arquivo == NULL) {
        arquivo = fopen("clientes.dat", "wb");
    }

    do {
        printf("\n*** Menu de Cadastro de Clientes ***\n");
        printf("1 - Incluir registros\n");
        printf("2 - Listar todos os registros\n");
        printf("3 - Pesquisar registro pelo nome\n");
        printf("4 - Alterar registro\n");
        printf("5 - Excluir registro\n");
        printf("6 - Saída\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                incluir_registro(arquivo);
                break;
            case 2:
                listar_registros(arquivo);
                break;
            case 3:
                pesquisar_registro(arquivo);
                break;
            case 4:
                alterar_registro(arquivo);
                break;
            case 5:
                excluir_registro(arquivo);
                break;
            case 6:
                fclose(arquivo);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}

#endif // ex5

#ifdef ex4

struct mercadoria {
    int codigo;
    char nome[50];
    int quantidade;
};


void ler_string(char *str, int tamanho) {
    int i = 0;
    char c;
    while (i < tamanho - 1 && (c = getchar()) != '\n' && c != EOF) {
        str[i] = c;
        i++;
    }
    str[i] = '\0';
}


void incluir_produto(FILE *arquivo) {
    struct mercadoria produto;
    fseek(arquivo, 0, SEEK_END);

    printf("\nDigite o código do produto: ");
    scanf("%d", &produto.codigo);
    getchar();

    printf("Digite o nome do produto: ");
    ler_string(produto.nome, sizeof(produto.nome));

    printf("Digite a quantidade atual do produto: ");
    scanf("%d", &produto.quantidade);

    fwrite(&produto, sizeof(struct mercadoria), 1, arquivo);
    printf("Produto adicionado com sucesso!\n");
}


void listar_produtos(FILE *arquivo) {
    struct mercadoria produto;
    fseek(arquivo, 0, SEEK_SET);

    printf("\n** Lista de Produtos **\n");
    while (fread(&produto, sizeof(struct mercadoria), 1, arquivo) == 1) {
        printf("\nCódigo: %d\nNome: %s\nQuantidade: %d\n", produto.codigo, produto.nome, produto.quantidade);
    }
}

int comparar_strings(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }
    return str1[i] == str2[i];
}

void pesquisar_produto(FILE *arquivo) {
    char nome_procurado[50];
    struct mercadoria produto;

    printf("\nDigite o nome do produto que deseja pesquisar: ");
    ler_string(nome_procurado, sizeof(nome_procurado));

    fseek(arquivo, 0, SEEK_SET);
    int encontrado = 0;
    while (fread(&produto, sizeof(struct mercadoria), 1, arquivo) == 1) {
        if (comparar_strings(produto.nome, nome_procurado)) {
            printf("\nProduto encontrado!\nCódigo: %d\nNome: %s\nQuantidade: %d\n", produto.codigo, produto.nome, produto.quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado!\n");
    }
}


void listar_produtos_nao_disponiveis(FILE *arquivo) {
    struct mercadoria produto;
    fseek(arquivo, 0, SEEK_SET);

    printf("\n** Produtos Não Disponíveis **\n");
    int encontrado = 0;
    while (fread(&produto, sizeof(struct mercadoria), 1, arquivo) == 1) {
        if (produto.quantidade == 0) {
            printf("\nCódigo: %d\nNome: %s\nQuantidade: %d\n", produto.codigo, produto.nome, produto.quantidade);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Não há produtos não disponíveis.\n");
    }
}

void alterar_quantidade(FILE *arquivo) {
    int codigo;
    struct mercadoria produto;
    printf("\nDigite o código do produto que deseja alterar a quantidade: ");
    scanf("%d", &codigo);

    fseek(arquivo, 0, SEEK_SET);
    int encontrado = 0;
    while (fread(&produto, sizeof(struct mercadoria), 1, arquivo) == 1) {
        if (produto.codigo == codigo) {
            printf("\nProduto encontrado: %s (Código: %d)\n", produto.nome, produto.codigo);
            printf("Quantidade atual: %d\n", produto.quantidade);
            printf("Digite a nova quantidade: ");
            scanf("%d", &produto.quantidade);


            fseek(arquivo, -sizeof(struct mercadoria), SEEK_CUR);
            fwrite(&produto, sizeof(struct mercadoria), 1, arquivo);
            printf("Quantidade atualizada com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado!\n");
    }
}

void alterar_produto(FILE *arquivo) {
    int codigo;
    struct mercadoria produto;
    printf("\nDigite o código do produto que deseja alterar: ");
    scanf("%d", &codigo);

    fseek(arquivo, 0, SEEK_SET);
    int encontrado = 0;
    while (fread(&produto, sizeof(struct mercadoria), 1, arquivo) == 1) {
        if (produto.codigo == codigo) {
            printf("\nProduto encontrado: %s (Código: %d)\n", produto.nome, produto.codigo);
            printf("Digite o novo nome: ");
            ler_string(produto.nome, sizeof(produto.nome));

            printf("Digite o novo código: ");
            scanf("%d", &produto.codigo);

            fseek(arquivo, -sizeof(struct mercadoria), SEEK_CUR);
            fwrite(&produto, sizeof(struct mercadoria), 1, arquivo);
            printf("Produto alterado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto não encontrado!\n");
    }
}

void excluir_produto(FILE *arquivo) {
    int codigo;
    struct mercadoria produto;
    printf("\nDigite o código do produto que deseja excluir: ");
    scanf("%d", &codigo);

    fseek(arquivo, 0, SEEK_SET);
    int encontrado = 0;
    FILE *temp = fopen("temp.dat", "wb");
    while (fread(&produto, sizeof(struct mercadoria), 1, arquivo) == 1) {
        if (produto.codigo != codigo) {
            fwrite(&produto, sizeof(struct mercadoria), 1, temp);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);
    remove("mercadorias.dat");
    rename("temp.dat", "mercadorias.dat");

    if (encontrado) {
        printf("Produto excluído com sucesso!\n");
    } else {
        printf("Produto não encontrado!\n");
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");
    FILE *arquivo;
    int opcao;

     setlocale(LC_ALL,"Portuguese");
    
    arquivo = fopen("mercadorias.dat", "r+b");
    if (arquivo == NULL) {
        arquivo = fopen("mercadorias.dat", "wb");
    }

    do {
        printf("\n*** Menu de Controle de Mercadorias ***\n");
        printf("1 - Incluir produtos\n");
        printf("2 - Listar todos os produtos\n");
        printf("3 - Pesquisar um produto pela descrição\n");
        printf("4 - Listar os produtos não disponíveis\n");
        printf("5 - Alterar a quantidade de um produto\n");
        printf("6 - Alterar um produto\n");
        printf("7 - Excluir um produto\n");
        printf("8 - Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                incluir_produto(arquivo);
                break;
            case 2:
                listar_produtos(arquivo);
                break;
            case 3:
                pesquisar_produto(arquivo);
                break;
            case 4:
                listar_produtos_nao_disponiveis(arquivo);
                break;
            case 5:
                alterar_quantidade(arquivo);
                break;
            case 6:
                alterar_produto(arquivo);
                break;
            case 7:
                excluir_produto(arquivo);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 8);

    fclose(arquivo);
    return 0;
}

#endif // ex4
