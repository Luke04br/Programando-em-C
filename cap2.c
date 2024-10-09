#include <stdio.h>
#include <stdlib.h>
#include<locale.h>

#define ex5
//OBS.: Todos os programa devem ser finalizados pelo usuario.


#ifdef ex1
/*1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
 ,   pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    char Resposta;
    int Palpite, min, max;
    setlocale(LC_ALL, "");

    do {
        system("cls");
        Palpite = 50;
        min = 1;
        max = 99;
        printf("Pense em um número de 1 a 99. Agora responda as perguntas com <, > ou =\n\n");
        do {
            do {
                printf("O número é maior, menor ou igual a %d? ", Palpite);
                scanf(" %c", &Resposta);
                if (Resposta != '<' && Resposta != '=' && Resposta != '>') {
                    printf("Digite um símbolo válido!\n\n");
                }
            } while (Resposta != '<' && Resposta != '=' && Resposta != '>');

            if (Resposta == '=')
                printf("O número que você pensou é %d!!!\n", Palpite);

            else if (Resposta == '<')
                max = Palpite - 1;

            else
                min = Palpite + 1;

            Palpite = (max + min) / 2;

            if (Palpite < 1) {
                Palpite = 1;
                Resposta = '=';
                printf("O número que você pensou é %d!!!\n", Palpite);
            }
            else if (Palpite > 98) {
                Palpite = 99;
                Resposta = '=';
                printf("O número que você pensou é %d!!!\n", Palpite);
            }
        }while (Resposta != '=');

        printf("Digite S ou s, caso queira jogar novamente: ");
        scanf(" %c", &Resposta);
    } while (Resposta == 'S' || Resposta == 's');

    return 0;
}


#endif // ex1

#ifdef ex2
/*2 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video.*/

int main() {
    char Resposta;
    int Palpite,  min, max;
    setlocale(LC_ALL,"");

    do {
        system("cls");
        Palpite = 50;
        min = 1;
        max = 99;
        printf("Pense em um número de 1 a 99. Agora responda as perguntas com <, > ou =\n\n");
        do{
            do{
                printf("O número é maior, menor ou igual a %d?",Palpite); // Pergunta 1
                scanf(" %c",&Resposta);
                if(Resposta != '<' && Resposta != '='&& Resposta != '>')
                    printf("Digite um símbolo válido!\n\n");
            }while(Resposta != '<' && Resposta != '='&& Resposta != '>');

            switch (Resposta) {
                case '=':
                    printf("O número que você pensou é %d!!!\nMELHORE, CONEEEE!!!", Palpite);
                    break;

                case '<':
                    max = Palpite - 1;
                    break;

                case '>':
                    min = Palpite + 1;
                    break;
            }
            Palpite = (max + min)/2;

            if(Palpite < 1) {
                Palpite = 1;
                Resposta = '=';
                printf("O número que você pensou é %d!!!\n", Palpite);
            }
            else if (Palpite > 98) {
                Palpite = 99;
                Resposta = '=';
                printf("O número que você pensou é %d!!!\n", Palpite);
            }
        }while(Resposta != '=');

    printf("Digite S ou s, caso queria jogar novamente: ");
    scanf(" %c",&Resposta);

    }while(Resposta == 'S' || Resposta == 's');
return 0;
}
#endif // ex2

#ifdef ex3
/*3 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados.*/
int main() {
    int x = 0, cont, numeros[100];
    float media;
    char Resposta;
    setlocale(LC_ALL,"");

    do{
        media = 0;
        cont = 0;
        system("cls");
        for(x;;x++) {
            printf("Digite um número (%d°): ",x+1);
            scanf("%d",&numeros[x]);
            if(numeros[x]<0)
                break;
            else
                cont++;
       }
        for(x=0;x<cont;x++)
            media += numeros[x];
        media = media/cont;
        if(cont == 0)
                printf("\nNão há números positivos para calcular a média\n");

        else
        printf("\nA média dos números positivos digitados é: %.2f\n", media);

        printf("\nDigite S ou s para realizar um novo cálculo: ");
        scanf(" %c",&Resposta);
    }while(Resposta == 'S' || Resposta == 's');
    return 0;
}
#endif // ex3

#ifdef ex4
/*4 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
    consumidos por um carro em um percurso.
    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
    abaixo:
    CONSUMO (km/l) MENSAGEM
    menor que 8    Venda o carro!
    entre 8 e 14   Economico!
    maior que 14   Super economico!*/
int main() {
    float distancia, litros, consumo;
    char Resposta;
    setlocale(LC_ALL,"");
    do{
        system("cls");
        do {
            printf("Digite a distância percorrida em Km pelo carro: ");
            scanf("%f",&distancia);
            if(distancia<0)
                printf("digite um valor válido!\n");
        }while(distancia<0);

        do {
            printf("Digite a quantidade de litros necessária para percorrer a distância: ");
            scanf("%f",&litros);
            if(litros<0)
                printf("digite um valor válido!\n");
        }while(distancia<0);
        consumo = distancia/litros;
        printf("\o carro tem consumo de: %.2fKm/L", consumo);
        if (consumo <=8)
            printf("\nVenda o carro!");
        else if(consumo<=14)
            printf("\nEconômico!");
        else
            printf("\nSuper econômico!");
        printf("\n\nDigite S ou s para realizar um novo cálculo: ");
        scanf(" %c",&Resposta);
    }while(Resposta == 'S' || Resposta == 's');
    return 0;
}
#endif // ex4

#ifdef ex5
/*5 - As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles.*/
int main() {
	int horasI, minutosI, segundosI, horasF, minutosF, segundosF;
	char Resposta;
	setlocale(LC_ALL,"");
	do{
        system("cls");
		do {
			printf("Digite a hora que a ligação foi iniciada: ");
			scanf("%d",&horasI);
			if(horasI<0 || horasI>23)
				printf("Digite um valor válido!\n");
		}while(horasI<0 || horasI>23);

		do {
			printf("\nDigite os minutos em que a ligação foi iniciada: ");
			scanf("%d",&minutosI);
			if(minutosI<0||minutosI>59)
				printf("Digite um valor válido!\n");
		}while(minutosI<0||minutosI>59);

		do {
			printf("\nDigite os segudos em que ligação foi iniciada: ");
			scanf("%d",&segundosI);
			if(segundosI<0 ||segundosI>59)
				printf("Digite um valor válido!\n");
		}while(segundosI<0 ||segundosI>59);


		do {
			printf("\nDigite a hora que a ligação foi finalizada: ");
			scanf("%d",&horasF);
			if (horasF<0 || horasF>23 || horasF<horasI)
				printf("Digite um valor válido!\n");
		}while(horasF<0 || horasF>23|| horasF<horasI);

		do {
			printf("\nDigite os minutos em que a ligação foi finalizada: ");
			scanf("%d",&minutosF);
			if(minutosF<0||minutosF>59 || (horasF==horasI && minutosF<minutosI))
				printf("Digite um valor válido!\n");
		}while(minutosF<0||minutosF>59 || (horasF==horasI && minutosF<minutosI));

		do {
			printf("\nDigite os segudos em que ligação foi finalizada: ");
			scanf("%d",&segundosF);
			if(segundosF<0 ||segundosF>59 || (horasF==horasI && minutosF==minutosI && segundosF<segundosI))
				printf("Digite um valor válido!\n");
		}while(segundosF<0 ||segundosF>59 ||(horasF==horasI && minutosF==minutosI && segundosF<segundosI));

		horasI = horasF-horasI;
		minutosI = minutosF - minutosI;
		segundosI = segundosF - segundosI;
		printf("\nA ligação teve duração de %d horas, %d minutos e %d segundos",horasI,minutosI,segundosI);
		printf("\n\nDigite S caso queira verificar a duração de alguma outra ligação: ");
		scanf(" %c",&Resposta);
	}while(Resposta == 'S' || Resposta == 's');
	return 0;
}
#endif//ex5
