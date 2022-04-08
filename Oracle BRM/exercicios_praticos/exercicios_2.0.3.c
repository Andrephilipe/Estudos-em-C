/*
*@fileexercicios.c
@author Andre Philipe
@date 21-05-2025
@brief <Programa de exercicios praticos>
*/

/*Arquivo que implementa as funcoes do programa
*/
#include "funcoes_uteis.c"

//funcao principal
int main(int argc, char *argv[])
{

    int menu;
    /*Tipos definidos no arquivo arg_uteis.h */
    menu_item_m mt = OPCAO_1; OPCAO_2; OPCAO_3; OPCAO_4; OPCAO_5; OPCAO_6; OPCAO_7; EXIT;

    fun_time();

    printf("\nSou Andre Philipe email: cassiano.apg@gmail.com\n\n");
    printf("Escolha entre as opcoes e digite o numero correspodente:\n\n");
    printf("Opcao - 1 (Caso de leitura e impressao dos dados)\n");
    printf("Opcao - 2 (Caso de calculos matematicos)\n");
    printf("Opcao - 3 (Caso que conversao de grau)\n");
    printf("Opcao - 4 (Caso de calculo fatorial)\n");
    printf("Opcao - 5 (Caso de media de Array)\n");
    printf("Opcao - 6 (Caso de impressao da tabuada de 1 a 10 sem imprimir a coluna 5.)\n");
    printf("Opcao - 7 (Impressao de tres formas de Hello Word)\n");
    printf("\nOu digite exit para sair\n");
    scanf("%d",&menu);

    if(menu >= OPCAO_1 && menu <= OPCAO_7 || menu == EXIT)
    {

        switch (menu)
        {
            
        /*Caso de impressão de dados
        *Autor: Andre Philipe
        *Acao: recebe dados do teclado e imprime na tela
        */
            
        char nome [30];
        char sobrenome [40];
        char nomecompleto [250];
        int data, idade;

        case OPCAO_1:
    
            printf("Escreva seu primeiro nome: \n");
            scanf("%s",nome);
            printf("Escreva seu sobrenome: \n");
            scanf("%s",sobrenome);

            printf("Escreva o ano do seu aniversario: ");
            scanf("%d",&data);
            idade = (2021 - data);
        
            sprintf(nomecompleto, "%s %s",nome, sobrenome);
            printf("Seu nome e %s e tem %d caracteres sua idade e %d\n",nomecompleto,strlen(nomecompleto), idade);
          
            break;

        /*Caso de calculos matematicos
        *Autor: Andre Philipe
        *acao: recebe n1 e n2 passa como parametros para a fun_calculos() do arquivo funcoes_uteis.c
        */

        int num1_calc;
        int num2_calc;

        case 2:

            printf("Escreva dois numeros: \n");
            printf("Primeiro numero:");
            scanf("%d",&num1_calc);

            printf("Segundo numero: ");
            scanf("%d",&num2_calc);

            fun_calculos(&num1_calc, &num2_calc);
        
        break;

        /*
        *Caso de coversao de celsios para fahrenheit
        *Autor: Andre Philipe
        *
        */
        int num_int;
        double num_double;

        case 3:

            printf("Digite um grau em Fahrenheit:\n");
            scanf("%d",&num_int);

            num_double = num_int;

            fun_conv_grau(&num_int, &num_double);
        
        break;

        /*
        *Caso de calculo fatorial
        *Autor: Andre Philipe
        *acao: recebe num1 e envia como parametro para a funcao fun_fatorial() do arquivo funcoes_uteis.c
        */

        int num1;

        case 4:

            printf("Escreva um numero: ");
            scanf("%d", &num1);

            fun_fatorial(num1);

        break;
    
        /*Caso criar um array de char de 10 posições, coverte para inteiros e calcula a media.
        *Autor: Andre Philipe 
        */
        char valores[10];
        int valor = 0;
        int i = 0;
        int total = 0;
        int media = 0;

        char auxiliar[2];

        case 5:

        printf("Escreva 10 numeros: \n");

        for( i = 0; i <= COUNT; i++)
        {   
            printf("Digite um numero:\n");
            scanf("%c", &valores[i]);
            valores[i] = getchar();
        }
        for(i = 0; i < strlen(valores); i++)
        {
            auxiliar[0] = valores[i];
            putchar(valores[i]);
            valor = atoi(auxiliar);
            total = total + valor;
        }

        putchar(valor);
        media = total / 10;
        printf("\nA media dos valores e = %d",media);

        break;
        /*Caso de impressao da tabuada de 1 a 10 saltando a tabuada de 5
        *Autor: Andre Philipe 
        *acao: chama a funcao fun_tabuada
        */
        case 6:

            fun_tabuada();

        break;

        int item_submenu;

        case 7:

            printf("Digite o numero da sua opcao:\n\n");
            printf("Opcao - 1 (Em ingles);\n");
            printf("Opcao - 2 (Em Portugues);\n");
            printf("Opcao - 3 (Em Espanhol);\n");
            scanf("%d",&item_submenu);

            fun_submenus_hello_word(&item_submenu);

        break;

        }

        return 0;
    }

    //Bloco de finalização do programa
    else (menu == EXIT);

        { 
            int count = 10;

            while (count >= 0)
            {
                printf("%d \n",count);
                count--; 
            }

            printf("FIM!");
            fun_time();

        }
            return 0;
}
