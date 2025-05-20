/* Instrução para compilação: gcc funcoesArray.c teste-5.c -o teste-5
   Execução ./teste-5
*/

#include "funcoesArray.h"



int main(){
	 printf("ola Mundo");
	double* array1 = alocarArray(11);
inicializarArray(1000.0, 11, array1);	
imprimirArray(11, array1);
	return 0;
}
