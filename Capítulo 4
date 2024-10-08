#include <stdlib.h>
#include <locale.h>
#define ex1

//OBS.: Todos os programa devem ser finalizados pelo usuario.
#ifdef ex1
/*1 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores
    ordenados.*/
int main() {
int A[10],ordem[10],x,y;
char resposta;

setlocale(LC_ALL,"Portuguese");

  do{
    for(x=0;x<10;x++){
      printf("Digite o %d° número:",x+1);
      scanf("%d",&A[x]);
      ordem[x]=A[x];
        }
    for(x=0;x<10;x++){
        for(y=0;y<10;y++){
            if(A[x]>A[y]){
                ordem[x]= A[y];
                ordem[y]= A[x];
            }else{ordem[x]= A[x];
                ordem[y]= A[y];}
        }
    }

    printf("os valores ordenados em ordem crescente são:");

    for(x=0;x<10;x++){
        printf("%d\n",ordem[x]);
    }

    printf("Deseja inserir mais números?\n");
    scanf(" %c",&resposta);

  }while(resposta=='s'||resposta=='S');
}
#endif//ex1

#ifdef ex2
/*2 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
*/
int main() {

    setlocale(LC_ALL,"");

    int I[3],x;
    long L[3];
    unsigned U[3];
    float F[3];
    double D[3];
    char Resposta;

do{
    for(x=0;x<3;x++){
    printf("\nDigite o %d° valor para a variável tipo int: ",x+1);
    scanf("%d",&I[x]);
    }
    system("cls");

    for(x=0;x<3;x++){
    printf("\nDigite o %d° valor para a variável tipo long: ",x+1);
    scanf("%ld",&L[x]);
    getchar();
    }
    system("cls");

    for(x=0;x<3;x++){
    printf("\nDigite o %d° valor para a variável tipo unsigned:",x+1);
    scanf("%u",&U[x]);
    getchar();
    }
    system("cls");

    for(x=0;x<3;x++){
    printf("\nDigite o %d° valor para a variável tipo float: ",x+1);
    scanf("%f",&F[x]);
    getchar();
    }
    system("cls");

    for(x=0;x<3;x++){
    printf("\nDigite o %d° valor para a variável tipo double: ",x+1);
    scanf("%lf",&D[x]);
    getchar();
    }
    system("cls");

    printf("\n\nimprimindo:\n\n        10        20        30        40        50\n12345678901234567890123456789012345678901234567890\n");
    for(x=0;x<3;x++){
    printf("  %-11d         %-11ld         %-8u\n",I[x],L[x],U[x]);
    printf("            %-11f         %-18lf     \n",F[x],D[x]);
    }

    printf("\nDeseja inserir mais números?(Digite s se sim):");
    scanf("%c",&Resposta);
    getchar();

}while(Resposta=='s'||Resposta=='S');
    return 0;


}
#endif//ex2

#ifdef ex3
/*3 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de ordem impar
    e o outro tera´ as componentes de ordem par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
    deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.*/
int main() {
    int vetor[10], p[5], i[5], x, y, z;
    char Resposta;
    setlocale(LC_ALL,"");

    do{
        y = -1;
        z = -1;
        printf("Digite os 10 valores do vetor\n");
        for(x=0;x<10;x++) {
            printf("%d° valor: ",x+1);
            scanf("%d",&vetor[x]);
        }
        for(x=0;x<10;x++) {
            if(x%2==0){
                y++;
                p[y]=vetor[x];
            }
            else {
                z++;
                i[z]=vetor[x];
            }
        }
        printf("vetor de índice par: ");
        for(x=0;x<5;x++)
            printf(" %d" ,p[x]);

         printf("\nvetor de índice ímpar: ");
        for(x=0;x<5;x++)
            printf(" %d" ,i[x]);

        printf("\n\nDigite s caso queira continuar: ");
        scanf(" %c",&Resposta);
    }while(Resposta=='s'||Resposta=='S');
}
#endif//ex3

#ifdef ex4
/*4 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de valor impar
    e o outro tera´ as componentes de valor par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
    programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}.*/
int main() {
    int vetor[10], p[10], i[10], x, y, z;
    char Resposta;
    setlocale(LC_ALL,"");

    do{
        y = -1;
        z = -1;
        printf("Digite os 10 valores do vetor\n");
        for(x=0;x<10;x++) {
            printf("%d° valor: ",x+1);
            scanf("%d",&vetor[x]);
        }
        for(x=0;x<10;x++) {
            if(vetor[x]%2==0){
                y++;
                p[y]=vetor[x];
            }
            else {
                z++;
                i[z]=vetor[x];
            }
        }
        printf("vetor de valores pares: ");
        if (y == -1)
            printf("não há números pares");
        else{
        for(x=0;x<y+1;x++)
            printf(" %d" ,p[x]);
        }

         printf("\nvetor de valores ímpares: ");
         if (z == -1)
            printf("não há números ímpares");
         else{
        for(x=0;x<z+1;x++)
            printf(" %d" ,i[x]);
         }

        printf("\n\nDigite s caso queira continuar: ");
        scanf(" %c",&Resposta);
    }while(Resposta=='s'||Resposta=='S');
}
#endif//ex4

#ifdef ex5
/*5 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
    resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
    dos 6 elementos dos vetores.*/
int main() {
int A[2][3], B[2][3],soma[2][3],x,y;
char Resposta;

setlocale(LC_ALL,"");
do{
    for(x=0;x<2;x++){
        for(y=0;y<3;y++){
        printf("\nDigite o valor de índice [%d][%d] do vetor A:",x,y);
        scanf("%d",&A[x][y]);
        getchar();
        }
    }

    for(x=0;x<2;x++){
        for(y=0;y<3;y++){
        printf("\nDigite o valor de índice [%d][%d] do vetor B:",x,y);
        scanf("%d",&B[x][y]);
        getchar();
        }
    }

    for(x=0;x<2;x++){
        for(y=0;y<3;y++){
        soma[x][y] = A[x][y] + B[x][y];
        }
    }

    printf("\nos valores somados são:\n");
    for(x=0;x<2;x++){
        for(y=0;y<3;y++){
        printf("valor da soma dos valores de índice [%d][%d]: %d\n",x,y,soma[x][y]);
        }
    }

    printf("Deseja inserir mais valores?(Digite s se sim):");
    scanf("%c",&Resposta);
    getchar();

}while(Resposta=='s'||Resposta=='S');
}
#endif//ex5
