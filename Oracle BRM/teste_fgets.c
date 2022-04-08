#include <stdio.h>
#include <stdlib.h>
#include <time.h>//Biblioteca com comandos de data e hora

int teste()
{

    int anoAtual;//Esta variável foi criada para receber o resultado do comando que exibe o ano atual.
    time_t data_ano;//Foi criada uma variável chamada data_ano que é do tipo time_t que é um tipo de variável que recebe valores de data e hora.
    time(&data_ano);

    struct tm *data = localtime(&data_ano);

    anoAtual = (data->tm_year+1900);  

    printf("%d\n",anoAtual);
    return 0;
}
