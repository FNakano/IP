#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printuf (char uf[60][60]) {
  for (int i=0;i<60;i++) {
    // puts (uf[i]);
    printf ("%s, %ld\n", uf[i], strlen(uf[i]));
  }
}

void main () {
  char uf[60][60]={
    "Acre","AC","Alagoas","AL","Amapa","AP","Amazonas","AM",
    "Bahia","BA","Ceara","CE","Espirito Santo","ES",
    "Goias","GO","Maranhao","MA","Mato Grosso","MT",
    "Mato Grosso do Sul","MS","Minas Gerais","MG",
    "Para","PA","Paraiba","PB","Parana","PR",
    "Pernambuco","PE","Piaui","PI","Rio de Janeiro","RJ",
    "Rio Grande do Norte","RN","Rio Grande do Sul","RS",
    "Rondonia","RO","Roraima","RR","Santa Catarina","SC",
    "Sao Paulo","SP","Sergipe","SE","Tocantins","TO",
    "Distrito Federal","DF", "São Paulo", "SP"};

  // char uf2[60][60];
  // memcpy (uf2, uf, 60*60*sizeof(char));
  qsort (uf, 60, 60*sizeof(char), strcmp);
  printuf(uf);
}
