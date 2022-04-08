#include <stdio.h>
#include <stdlib.h>

#define LOG fopen("log_da_aplicacao.log","w")

int imprime_log()
{
    FILE *log;

    log = fopen("log_da_aplicacao.log","w");

    if(log==NULL)
    {
        printf("Ocorreu um arro na criacao do arquivo!");
        return 0;

    }
}

int soma(int *n1, int *n2){
    
    //int n1, n2;
    char nome[40];

    int soma = *n1 + *n2;

    printf("%d",soma);
    printf("ESCREVA SEU NOME:\n");
    scanf("%s",&nome);

    fprintf(LOG,"%d",soma);
    fprintf(LOG,"%s\n",nome);

    fclose(LOG);

    return 0;
}

int main() 
{
    int n_1, n_2;

    printf("Digite um numeros:\n");
    scanf("%d",&n_1);
    printf("Digite outro numero:\n");
    scanf("%d",&n_2);

    soma(&n_1,&n_2);
    
}
