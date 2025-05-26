/* Instrução para compilação: gcc funcoesArray.c teste-12.c -o teste-12
   Execução ./teste-12
   Pagamento de uma dívida de 9mil com prestações de 990. Qual é a taxa 
   de juros? Escrever o programa que busca o valor.
   É possível calcular um chute inicial a partir da razão entre a soma das
   parcelas e zero.
   Depois de 
   OBSERVAÇÕES: esta não é a maneira mais rápida de encontrar a taxa.
     ela pode ser encontrado apenas fazendo contas.
     Este programa não é o mais curto possível. Uma tarefa poderia ser refatorar
     o código.
     Este programa poderia ser mais simples se testasse a diferença entre as 
     taxas ao invés de testar a diferença entre os valores.
*/

#include "funcoesArray.h"
#include <math.h>
#define EPSILON 5.0E-3   // meio centavo
#define CHUTE 0.1

int main(){
	 printf("ola Mundo\n");
   int quantosMeses= 10;  // 1+9 prestações
   double taxaMensalInferior=0.0, valorTaxaInferior;
   double taxaMensalSuperior=CHUTE, valorTaxaSuperior;
   double taxaMedia=-1.0;  // indica erro
   double *prestacaoPaga=alocarArray(quantosMeses);
   inicializarArray(990.0, quantosMeses, prestacaoPaga);  // valor da prestação
   int i=0;  // conta quantas iterações até o final
   
   double *valor=alocarArray(quantosMeses);
   valor[0]=-9000.0;  // No PIX - este é o valor a vista  
   adicionarAporteArray(taxaMensalSuperior, quantosMeses, valor, prestacaoPaga);
   imprimirArray(quantosMeses,valor);
   valorTaxaSuperior=valor[9];
   
   inicializarArray(0.0, quantosMeses, valor);
   valor[0]=-9000.0;  // No PIX - este é o valor a vista  
   adicionarAporteArray(taxaMensalInferior, quantosMeses, valor, prestacaoPaga);
   imprimirArray(quantosMeses,valor);
   valorTaxaInferior=valor[9];
   
   while (fabs(valorTaxaSuperior-valorTaxaInferior)>EPSILON) {
     taxaMedia=(taxaMensalSuperior+taxaMensalInferior)/2.0;
     inicializarArray(0.0, quantosMeses, valor);
     valor[0]=-9000.0;  // No PIX - este é o valor a vista  
     adicionarAporteArray(taxaMedia, quantosMeses, valor, prestacaoPaga);
     printf ("iterações %d\n", i++);
     imprimirArray(quantosMeses,valor);
     if (valor[9]>0.0) {
       // substitui a taxa inferior
       taxaMensalInferior=taxaMedia;
       valorTaxaInferior=valor[9];
     } else {
       // substitui a taxa superior
       taxaMensalSuperior=taxaMedia;
       valorTaxaSuperior=valor[9];
     }
   }
   printf ("Taxa=%lf\n", taxaMedia);
   return 0;
}
