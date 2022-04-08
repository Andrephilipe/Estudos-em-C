#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  char valores[10];
  int valor = 0;
  int i = 0;
  int total = 0;
  int media = 0;
  int count = 9;
  char var_array;

  char auxiliar[2];

  printf("Escreva 10 numeros: \n");

  for( i = 0; i <= count; i++)
  {   
    printf("Digite um numero:\n");
    scanf("%c", &valores[i]);
    getchar();
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
  return 0;
}
