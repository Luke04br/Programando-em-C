#include<stdio.h>
#include<std.lib>
#include<locale.h>
#define ex1

//OBS.: Todos os programa devem ser finalizados pelo usuario!!!
#ifdef ex1
/* 1 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned, float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char */ 
int main(){
  char Resposta;
  setloclae(LC_ALL,"");
  do {
    system("cls");
    printf("Deseja inserir novos valores? (s/n)");
    Resposta = getchar();
  }while(Resposta == 's' || Resposta == 'S');
  return 0;
}
#endif // ex1

#ifdef ex2
/* 2 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las usando ponteiros e retorne como resultado se 
    sao IGUAIS 1 ou se sao DIFERENTES 0 para a funcao main(). 
    Imprima o resultado na funcao main(). Declare os vetores como variavel global */ 
int comparacao(char *str1, char *str2){
    for(; str1 != '\0'&& str2 != '\0'; str1++, str2++)
        if(*str1 != *str2)
            return 0; // se tiver algo diferente
    if(str1 == '\0' && str2 == '\0')
        return 1; // se for igual e o finalizar estiver na mesma posição
    return 0; // se o finalizador n estiver na mesma posição
}
int main(){
char str1[11], str2[11];
  char Resposta;
  setloclae(LC_ALL,"");
  do {
    system("cls");
    printf("Insira a primeira string: ");
    gets(str1);
    printf("Insira a segunda string: ");
    gets(str2);
    comparacao();
    printf("Deseja inserir novos valores? (s/n)");
    Resposta = getchar();
  }while(Resposta == 's' || Resposta == 'S');
  return 0;
}
#endif // ex2

#ifdef ex3
/* 3 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva 
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros. 
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada usando ponteiros.(utilize o comando return). 
    O vetor deve ser declarado como variavel global.
    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y */

char vetor[14] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

char pesquisa(char *vetor, char letra) {
    for(x = 0; x < 14; x++)
        if(*(vetor + x) == vetor[x])
            return 1;
    return 0;
}

int main(){
char letra;
  setloclae(LC_ALL,"");
  do {
        system("cls");
        printf("Insira a letra que deseja pesquisar: ");
        letra = getchar();
        resultado = pesquisa(vetor, letra);
        if(resultado == 1)
            printf("A letra %c está presente no vetor!!!", letra);
        else   
            printf("A letra %c não está presente no vetor!!!", letra");
        printf("Deseja inserir novos valores? (s/n)");
        letra = getchar();
  }while(letra == 's' || letra == 'S');
  return 0;
}
#endif // ex3

#ifdef ex4
/* 4 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro. */ 
int main(){
  char Resposta;
  setloclae(LC_ALL,"");
  do {
    system("cls");
    printf("Deseja inserir novos valores? (s/n)");
    Resposta = getchar();
  }while(Resposta == 's' || Resposta == 'S');
  return 0;
}
#endif // ex4

#ifdef ex5
/* 5 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados via teclado numa funcao usando ponteiros. Imprima os dados
    recebidos no video numa usando ponteiros. Utilize um comando de loop. 
    O vetor de estruturas de ser declarado como variavel global
       estrutura: nome, end, cidade, estado, cep  */ 
int main(){
  char Resposta;
  setloclae(LC_ALL,"");
  do {
    system("cls");
    printf("Deseja inserir novos valores? (s/n)");
    Resposta = getchar();
  }while(Resposta == 's' || Resposta == 'S');
  return 0;
}
#endif // ex5

#ifdef ex6
/* 6 - Escreva um programa com a estrutura abaixo. Receba 2 datas via teclado 
    usando ponteiros. Calcule e exiba o numero de dias entre as duas datas
    usando ponteiros. Utilize um vetor de estruturas.
    	estrutura: dia, mes e ano  */ 
int main(){
  char Resposta;
  setloclae(LC_ALL,"");
  do {
    system("cls");
    printf("Deseja inserir novos valores? (s/n)");
    Resposta = getchar();
  }while(Resposta == 's' || Resposta == 'S');
  return 0;
}
#endif // ex6
