/*
*@file funcoes_uteis.c
@author Andre Philipe
@date 25-05-2025
@brief <Arquivo de implementacao de funcoes>
*/

#include "arq_uteis.h"

//funcoes auxiliares
/*
Funcao fun_fatorial()
*Autor: Andre Philipe
*acao: Calcula o fatorial de um numero recebido
*entrada: num1 do caso 4 do arquivo exercicios.c
*/
int fun_fatorial(int fatorial)
{
    int resposta = 1;
    int teste = fatorial;
   
    for (; fatorial >= 1; --fatorial)
    {
        resposta *= fatorial;
    }
    printf("O numero fatorial de %d e: %d\n",teste,resposta);

    return 0;
}
/*
Funcao fun_calculos()
*Autor: Andre Philipe
*acao: Faz calculos de soma, produto, quadrado, modulo, seno e diferança de numeros
*entrada: n1 e n2 do caso do 2 do arquivo exercicios.c
*/
int fun_calculos(int *num1, int *num2){
       
        int soma;
        int produto;
        int quadrado;
        int modulo;
        int raiz;
        int seno;
        int diferenca;

        soma = *num1 + *num2;
        produto = *num1 * (*num2 * *num2);
        quadrado = *num1 * *num1;
        modulo = abs(*num1);
        raiz = sqrt(soma);
        diferenca = (*num1 - *num2);
        seno = sin(diferenca);
            
        printf("A soma dos numeros e: %d\n ",soma);
        printf("O produto do primeiro numero e: %d \n",produto);
        printf("O quadrado do primeiro numero e: %d \n",quadrado);
        printf("O modulo do primeiro numero e: %d \n",modulo);
        printf("A raiz do primeiro numero e: %d \n",raiz);
        printf("O seno da diferença do primeiro para o segundo e: %d",seno);
        
        *num1 = NULL;
        *num2 = NULL;
        return 0;
}
/*Funcao que converte grau Fahrenhei em celsios
*Autor: Andre Philipe
*Acao: recebe um dados inteiro e imprimi convertido em int e double
*/
int fun_conv_grau(int *r_fahr, double *d_fahr)
{
    int grau_fahr;
    double grau_fahr_double;

    grau_fahr_double = (*d_fahr - 32.0) * 5.0/9.0;

    grau_fahr = (*r_fahr - 32) * 5/9;

    printf("O grau inteiro e: %d",grau_fahr);

    printf("\nO grau em double e: %f",grau_fahr_double);

    *r_fahr = NULL;

    return 0;
}

/*
Funcao fun_tabuada()
*Autor: Andre Philipe
*acao: imprime a tabuada de 1 a 10 saltando a tabuada de 5
*/
int fun_tabuada()
{
    int i, j;
    int tabuada[0] [0];;
    int r;
    FILE *text_tabuada;

    text_tabuada = fopen("tabuada.txt", "w");
  
       for (i = 1; i <= 10; i++)
       { 
          if( i == 5)
          continue;
         for (j = 1; j <= 10; j++)
            printf("%d x %d = %d\n", j, i, r = i * j);//Nao consegui fazer o scanf e criar a matriz.
            fprintf(text_tabuada,"[%d] [%d] [%d]\n", j, i, r, tabuada[j] [i]);
        }
        
        fprintf(text_tabuada,"[%d] [%d] [%d]", j, i, r, tabuada[j] [i]);
        
        fclose(text_tabuada);
        return 0;
}
/*Funcao que retorna a hora e ano da maquina
*Autor: Andre Philipe
*/
int fun_time()
{
  struct tm *data_hora_atual;     
  
  time_t segundos;
  
  time(&segundos);   
  
  data_hora_atual = localtime(&segundos);  

  printf("\nHora: %d:",data_hora_atual->tm_hour); 
  printf("%d:",data_hora_atual->tm_min);
  printf("%d\n",data_hora_atual->tm_sec); 
  
  printf("Data: %d/", data_hora_atual->tm_mday);
  printf("%d/",data_hora_atual->tm_mon+1);
  printf("%d\n",data_hora_atual->tm_year+1900);

  return 0;
}

/*Funcao para ativas o submenu para opcoes do hello word
*Autor: Andre Philipe
*acao: recebe parametros do caso 7 no arquivo exercicios.c e retorna opcoes do typedef hello_types no arquivo arp_uteis.h
*/ 
int fun_submenus_hello_word(int *submenu){
  
    //*submenu = submenu_t;

    hello_types_w hw = HELLO_1; HELLO_2; HELLO_3;

    //printf("Digite o numero da sua opcao:\n");
    ////printf("Opcao - 1 (Em ingles);\n");
   // printf("Opcao - 2 (Em Portugues);\n");
   // printf("Opcao - 3 (Em Espanhol);\n");

    //scanf("%d",&submenu);
  

    if (*submenu == 1 || *submenu == 2 || *submenu == 3 )
    {
      switch (*submenu)
    {
    case HELLO_1:

      printf("Hellow Word!");

      break;

    case HELLO_2:

    printf("Ola Mundo!");

    break;

    case HELLO_3:
    
    printf("Hola Mundo!");
    
    break;
    
    default:
      break;
    }
    }
    *submenu = NULL;

    return 0;
}

/*funcao para arquivo delogs da palicacao
*Autor: Andre Philipe
*/