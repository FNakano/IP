/* Instrução para compilação: gcc funcoesArray.c teste-7.c -o teste-7
   Execução ./teste-7
   Testa o efeito da taxa de juros mensal no calculo da taxa de juros anual.
*/

#include "funcoesArray.h"



int main(){
	 printf("ola Mundo");
	double* aporte = alocarArray(60);
        inicializarArray(2000.0, 60, aporte);
        imprimirArray(60, aporte);

        double *valorAnoCompleto=alocarArray(60);
        valorAnoCompleto[0]=0.0;
        //remunerarArray(0.005, 12, valorAnoCompleto);
        adicionarAporteArray(0.006,60,valorAnoCompleto,aporte); 
        imprimirArray(60,valorAnoCompleto);
	return 0;
}
