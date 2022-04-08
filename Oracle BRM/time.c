#include <stdio.h>
#include <time.h>

int main(){
  typedef enum hello_types
{
    HELLO_1 = 1,
    HELLO_2 = 2,
    HELLO_3 = 3,

} hello_types_w;
    
    int submenu;

    hello_types_w hw = HELLO_1; HELLO_2; HELLO_3;

    printf("Digite o numero da sua opcao:\n");
    printf("Opcao - 1 (Em ingles);\n");
    printf("Opcao - 2 (Em Portugues);\n");
    printf("Opcao - 3 (Em Espanhol);\n");

    scanf("%d",&submenu);
  

    if (submenu == 1 || submenu == 2 || submenu == 3 )
    {
      switch (submenu)
    {
    case HELLO_1:

      printf("Hellow Word!");

      break;

    case HELLO_2:

    printf("Olá Mundo!");

    break;

    case HELLO_3:
    
    printf("Hola Mundo!");
    
    break;
    
    default:
      break;
    }
    }
    
    return 0;
}