/* Instrução para compilação: gcc funcoesArray.c teste-11.c -o teste-11 -lm
   Execução ./teste-11
   Testa este conjunto de funções, CALCULANDO RETORNO MENSAL.
   O título testado é o tesouro pré 2028 - vencimento em 01/01/2028, 
   taxa 13,43%aa
   O cálculo do rendimento MENSAL será feito usando a função pow() de math.h 
*/

#include "funcoesArray.h"
#include <math.h>


int main(){
	 printf("ola Mundo\n");
   puts ("Retorno em frações mensais\n");
   double mes=pow (1.1343, 1.0/12);
   double *valorBrutoMensalAno=alocarArray(13);
   valorBrutoMensalAno[0]=10000.0;
   remunerarArray(mes-1.0, 13, valorBrutoMensalAno);
   printf ("em 11(?) meses o valor bruto final é %lf\n", 
     valorBrutoMensalAno[11]);
   printf ("em 12(?) dias o valor bruto final é %lf\n", 
     valorBrutoMensalAno[12]);
   /* Seguindo o raciocínio do retorno diário, o mês zero corresponde ao  
    * elemento zero então o mês 12 corresponde ao elemento 12. */

 
   return 0;
}
