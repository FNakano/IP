/* Instrução para compilação: gcc funcoesArray.c teste-12.c -o teste-12
   Execução ./teste-12
   Pagamento de uma dívida de 9mil com prestações de 990. Qual é a taxa 
   de juros? Executar o programa iterativamente.
   Depois de algumas iterações, cheguei a 0.0218430
*/

#include "funcoesArray.h"


int main(){
	 printf("ola Mundo\n");
   int quantosMeses= 10;  // 1+9 prestações
   double taxaMensal=0.1;               // o que queremos saber
   double *valor=alocarArray(quantosMeses);
   double *prestacaoPaga=alocarArray(quantosMeses);
   inicializarArray(990.0, quantosMeses, prestacaoPaga);  // valor da prestação
   valor[0]=-9000.0;  // No PIX - este é o valor a vista  
   adicionarAporteArray(taxaMensal, quantosMeses, valor, prestacaoPaga);
   imprimirArray(quantosMeses,valor);
   return 0;
}
