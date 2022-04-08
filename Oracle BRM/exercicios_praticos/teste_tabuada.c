#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>



int main()
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
            printf("%d x %d = %d\n", j, i, r = i * j);
            fprintf(text_tabuada,"[%d] [%d] [%d]\n", j, i, r, tabuada[j] [i]);
        }

        fprintf(text_tabuada,"[%d] [%d] [%d]", j, i, r, tabuada[j] [i]);
        
        fclose(text_tabuada);
        return 0;

}