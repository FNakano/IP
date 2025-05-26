/* Instrução para compilação: gcc funcoesArray.c teste-10.c -o teste-10 -lm
   Execução ./teste-10
   Testa este conjunto de funções com o resultado da calculadora do 
   tesouro direto.
   O título testado é o tesouro pré 2028 - vencimento em 01/01/2028, 
   taxa 13,43%aa
   O cálculo do rendimento diario será feito usando a função pow() de math.h 
*/

#include "funcoesArray.h"
#include <math.h>


int main(){
	 printf("ola Mundo\n");
   puts ("Retorno em frações diárias\n");
   puts ("Na calculadora \
     (https://www.tesourodireto.com.br/titulos/calculadora.htm), \
     um ano tem 252 dias úteis.\n");
   double dia=pow (1.1343, 1.0/252.0);
   double *valorBrutoDiarioAno=alocarArray(253);
   // imprimirArray(252, valorBrutoDiarioAno);
   valorBrutoDiarioAno[0]=10000.0;
   remunerarArray(dia-1.0, 253, valorBrutoDiarioAno);
   //imprimirArray(252, valorBrutoDiarioAno);
   printf ("em 251(?) dias o valor bruto final é %lf\n", 
     valorBrutoDiarioAno[251]);
   printf ("em 252(?) dias o valor bruto final é %lf\n", 
     valorBrutoDiarioAno[252]);
   /* Nota-se que o dia zero deve ser contado como dia zero então o array 
    * deve ter 253 elementos. */
   /* Caso mude-se a data de início de 01/01/2027, há um fim de semana e 
    * a contagem de dias úteis na calculadora do tesouro só diminui se a 
    * data de início for 04/01/2027.
    * Veja:
    * [captura de tela calculadora TD 01/01/2027](../images/Captura%20de%20tela%20de%202025-05-25%2010-44-08.png)
    * [captura de tela calculadora TD 03/01/2027](../images/Captura%20de%20tela%20de%202025-05-25%2010-45-25.png)
    * [captura de tela calculadora TD 04/01/2027](../images/Captura%20de%20tela%20de%202025-05-25%2010-46-10.png)
    */

 
   return 0;
}
