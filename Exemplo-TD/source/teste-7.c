/* Instrução para compilação: gcc funcoesArray.c teste-7.c -o teste-7
   Execução ./teste-7
   Testa o efeito da taxa de juros mensal no calculo da taxa de juros anual.
*/

#include "funcoesArray.h"



int main(){
	 printf("ola Mundo");
	double* array1 = alocarArray(11);
inicializarArray(1000.0, 11, array1);
imprimirArray(11, array1);

        double *valorAnoCompleto=alocarArray(12);
        valorAnoCompleto[0]=1000;
        remunerarArray(0.005, 12, valorAnoCompleto);
        imprimirArray(12,valorAnoCompleto);
	return 0;
}
