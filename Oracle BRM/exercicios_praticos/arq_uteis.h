/*
*@file arq_uteis.c
@author Andre Philipe
@date 25-05-2025
@brief <Arquivos de definicoes, referencias e claracoes do programa exercicios>
*/
#ifndef ARQ_HEADER
#define ARQ_HEADER
/*
*Bibliotecas utilizadas 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define COUNT 9

/*tipo criado para utilizacao no menu para opcoes de casos no inicio do programa
*/
typedef enum menu_item
{
    OPCAO_1 = 1,
    OPCAO_2 = 2,
    OPCAO_3 = 3,
    OPCAO_4 = 4,
    OPCAO_5 = 5,
    OPCAO_6 = 6,
    OPCAO_7 = 7,
    EXIT = 8,
} menu_item_m;

/*tipo criado para utilizacao no submenu na opcoes de tipos no caso 7 no arquivo
*uso: utilizado na funcao fun_subemenus_hello_word() no arqivo funcoes_uteis 
*/
typedef enum hello_types
{
    HELLO_1 = 1,
    HELLO_2 = 2,
    HELLO_3 = 3,

} hello_types_w;

//declaracoes de funcoes..

/*
Funcao fun_fatorial()
*Autor: Andre Philipe
*acao: Calcula o fatorial de um numero recebido
*entrada: num1 do caso 4 do arquivo exercicios.c
*/
int fun_fatorial(int fatorial);
/*
Funcao fun_calculos()
*Autor: Andre Philipe
*acao: Faz calculos de soma, produto, quadrado, modulo, seno e diferança de numeros
*entrada: n1 e n2 do caso do 2 do arquivo exercicios.c
*/
int fun_calculos(int *num1, int *num2);

/*Funcao que converte grau Fahrenhei em celsios
*Autor: Andre Philipe
*Acao: recebe um dados inteiro e imprimi convertido em int e double
*/
int fun_conv_grau(int *r_fahr, double *d_fahr);
/*
Funcao fun_tabuada()
*Autor: Andre Philipe
*acao: imprime a tabuada de 1 a 10 saltando a tabuada de 5
*/
int fun_tabuada();

/*Funcao que retorna a hora e ano da maquina
*Autor: Andre Philipe
*/
int fun_time();
/*Funcao para ativas o submenu para opcoes do hello word
*Autor: Andre Philipe
*acao: recebe parametros do caso 7 no arquivo exercicios.c e retorna opcoes do typedef hello_types no arquivo arp_uteis.h
*/
int fun_submenus_hello_word(int *submenu);

#endif