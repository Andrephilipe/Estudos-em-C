/*
Autor : André Philipe
Data: 19/05/2021

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definição da enum
	enum itens_menu {Opcao1 = 1, Opcao2, Opcao3}menu;

int main(int argc, char *argv[])
{

	printf("Ola sou o André Philipe\n email: cassiano.apg@gmail.com.\n");
	printf("Escolha uma das opções abaixo digite o número correspondente \n");
	printf("Opção 1: Leitura de nome e impressão.\n");
	printf("Opção 2: Calculos de soma, produto, quandrado e modulo.\n");
	printf("Opção 3 : Sair");
	scanf("%d",&menu);
	
	//Testando se o valor está na faixa válida usando os valores da enum
	if((menu >= Opcao1) && (menu <= Opcao3))
	{
	
		//switch que determina qual opção foi selecionada
		switch(menu)
		{
			char nome [35];
			char sobrenome [40];
			int datan,idade;

			//Primeiro casso leitura do nome e sobrenome
			case Opcao1:
				printf("Escreva seu primeiro nome: \n");
				scanf("%s",nome);

				printf("Seu sobrenome: \n");
				scanf("%s",sobrenome);
				strcat (nome, sobrenome);
				printf("%s contem %d caracteres \n",nome, strlen(nome));

				printf("Escreva seu ano de nascimento:");
				scanf("%d",&datan);
				idade = (2021 - datan);

				printf("Você tem %d anos",idade);

			break;

			//Calculos das questôes pedidas

			int primeironumero, segundonumero, soma, produto, quadrado, modulo;
			
			case Opcao2:

			printf("Escreva dois numeros:\n");

			printf("Escreva o primeiro numero: \n");
			scanf("%d",&primeironumero);

			printf("Escreva o segundo numero: \n");
			scanf("%d",&segundonumero);

			soma = primeironumero + segundonumero;
			produto = primeironumero * (segundonumero * segundonumero);
			quadrado = primeironumero * primeironumero;
			modulo = abs(primeironumero);

			printf("\nSoma dos numeros: %d",soma);
			printf("\nO produto : %d",produto);
			printf("\nO quadrado : %d",quadrado);
			printf("\nO modulo: %d",modulo);
	
			break;

			//fim do programa
			int n;
			n = 10;
			case Opcao3:
				while (n <= 0)
				{
					printf("%d\n",n);
				}
				printf("FIM");
			break;
		}
	}
	return 0;
}