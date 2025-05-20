#include <stdio.h>
#include <stdlib.h>

double* alocarArray(int numElem){

double* array = (double*)malloc(sizeof(double) * numElem);

return array;
}


int main(){
  printf("ola Mundo");
}
