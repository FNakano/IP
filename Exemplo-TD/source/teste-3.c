/* Instrução para compilação: gcc teste-3.c -o teste-3
   Execução ./teste-3
*/

#include <stdio.h>
#include <stdlib.h>

double* alocarArray(int numElem){

  double* array = (double*)malloc(sizeof(double) * numElem);

  return array;
    //return (double *) malloc (sizeof(double)*numElem);
}

void imprimeArray(int numElem, double* array){
	for(int i = 0; i< numElem; i++){
		printf("%lf ", array[i]);
	}
	return;
}

int main(){
	 printf("ola Mundo");
	double* array1 = alocarArray(11);
	imprimeArray(11, array1);
	return 0;
}
