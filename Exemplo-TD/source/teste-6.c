/* Instrução para compilação: gcc funcoesArray.c teste-6.c -o teste-6
   Execução ./teste-6
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
        for (int i=1;i<12;i++) {
          valorAnoCompleto[i]=valorAnoCompleto[i-1]+valorAnoCompleto[i-1]*0.005;
        }
        imprimirArray(12,valorAnoCompleto);
	return 0;
}
