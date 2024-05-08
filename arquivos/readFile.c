#include <stdio.h>

#define BUFLEN 100

void main () {
  char buf[BUFLEN];
  FILE *fp;
  fp=fopen ("texto.txt", "rt");
  if (!fp) { 
    // caso haja erro para abrir o arquivo, escreve na tela a mensagem de erro.
	perror("");
	return;
  }
  while (!feof(fp)) {
	if (fgets (buf, BUFLEN, fp)) {
      printf ("%s", buf);
    }
  }
  fclose(fp);
}
