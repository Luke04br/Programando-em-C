#inclde < stdio.h >
#inclde < stdlib.h >
#inclde < locale.h >

#define ex1
//OBS.: Todos os programa devem ser finalizados pelo usuario.

#ifdef ex1
/* 1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(tamb m numa fun  o).

    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long          */
#endif // ex1

#ifdef ex2
/* 2 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na funcao main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para 
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1 
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main(). */
#endif // ex2

#ifdef ex3
/* 3 - Escreva um programa que receba n valores via teclado e receba tambem a
    operacao a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operacoes aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.  
    As variaveis sao LOCAIS na funcao main(). */
#endif // ex3

#ifdef ex4
/* 4 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva 
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros. 
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa 
    usando ponteiros.(utilize o comando return). 
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y                                 */
#endif // ex4

#ifdef ex5
/* 5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa funcao e imprima todos os registros no
    video em outra funcao. Faca um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opcao de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep                          */
#endif // ex5

#ifdef ex6
/* 6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro sempre usando ponteiros. */
#endif // ex6
