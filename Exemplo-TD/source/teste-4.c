/* Instrução para compilação: gcc funcoesArray.c teste-4.c -o teste-4
   Execução ./teste-4
*/

#include "funcoesArray.h"



int main(){
	 printf("ola Mundo");
	double* array1 = alocarArray(11);
	imprimirArray(11, array1);
	return 0;
}
