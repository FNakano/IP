/* funcoesArray.c - funções de alocação, inicialização e impressão de arrays
   este arquivo deve ser compilado junto com um arquivo teste-N para usar.
*/

#include "funcoesArray.h"

double* alocarArray(int numElem){

  double* array = (double*)malloc(sizeof(double) * numElem);

  return array;
    //return (double *) malloc (sizeof(double)*numElem);
}

void imprimirArray(int numElem, double* array){
        printf ("%p=[", array);
	for(int i = 0; i< numElem; i++){
		printf("%lf\n ", array[i]);
	}
        puts ("]");
	return;

}
void inicializarArray(double valorInicial, int numElem, double* array){
	for(int i = 0; i< numElem; i++){
 array[i] = valorInicial;
	}
	return;
}

void remunerarArray(double taxa, int numElem, double* array){
        for (int i=1;i<numElem;i++) {
          array[i]=array[i-1]+array[i-1]*taxa;
        }
}

void adicionarAporteArray(double taxa, int numElem, double* array, double *aporte){
/* acumula uma reserva: a partir de array[0] (valor inicial), aplica a taxa 
 * e acrescenta aporte[0]. Supondo que essas operações ocorram instantaneamente
 * (simultaneamente nesta ordem). */ 
   array[0]+=aporte[0];
   for (int i=1;i<numElem;i++) {
       array[i]=array[i-1]+(array[i-1])*taxa+aporte[0];
   }
}

/*
int main(){
	 printf("ola Mundo");
	double* array1 = alocarArray(11);
	imprimeArray(11, array1);
	return 0;
}
*/

