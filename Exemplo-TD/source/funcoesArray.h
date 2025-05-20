/* funcoesArray.h - prototipos das funções de alocação, inicialização e impressão de arrays
   este arquivo deve ser incluido dentro do arquivo teste-N para usar.
*/

#include <stdio.h>
#include <stdlib.h>

double* alocarArray(int numElem);

void imprimirArray(int numElem, double* array);

void inicializarArray(double valorInicial, int numElem, double* array);

void remunerarArray(double taxa, int numElem, double* array);

void adicionarAporteArray(double taxa, int numElem, double* array, double *aporte);
