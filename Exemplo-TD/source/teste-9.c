/* Instrução para compilação: gcc funcoesArray.c teste-9.c -o teste-9 -lm
   Execução ./teste-9
   Testa este conjunto de funções com o resultado da calculadora do tesouro direto.
   O título testado é o tesouro pré 2028 - vencimento em 01/01/2028, taxa 13,43%aa
   O cálculo do rendiment mensal será feito usando a função pow() de math.h 
*/

#include "funcoesArray.h"
#include <math.h>


int main(){
	 printf("ola Mundo\n");
   puts ("Retorno em frações diárias\n");
   double dia=pow (1.1343, 1.0/252.0);
   double faltaUmDia=pow(dia, 251.0);
   printf ("FaltaUm=%lf\n", faltaUmDia);
   puts ("retorno contínuo");
   double r=(log(13917.30)-log(10000.0))/(31.0/12.0);
   printf("Taxa de retorno contínua %lf.\n", r);
   puts ("Cálculo da taxa mensal\n");
   double taxaMensal=pow(1.1343, 1/12.0)-1;
   printf ("Taxa mensal %lf\n", taxaMensal);
   int quantosMeses= 31;  // meses de 20/05/2025 (hoje) até 01/01/2028: 24+7=31
   double *valorTDPre=alocarArray(quantosMeses);
   valorTDPre[0]=10000.0;
   remunerarArray(taxaMensal, quantosMeses, valorTDPre);
   imprimirArray(quantosMeses,valorTDPre);
   return 0;
}
