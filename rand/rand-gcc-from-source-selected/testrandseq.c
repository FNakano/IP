// adaptação do testrand.c para gerar aleatoriamente 10 números, para conferir com o uso da função da biblioteca padrão.
// gera os 10 números corretamente quando a semente vale 1 mas não quando a semente vale 1023.
// gera os mesmos 10 números tanto para semente zero quanto para semente 1023.
// parece ser problema para setar o estado inicial. Usando srand(1023) gerando 10 números, usando srand(1023) e gerando 10 números os dez números são diferentes, mais, é como se tivesse iniciado com 1 da primeira vez e não iniciado na segunda vez.

#include "stdlib.h" // FN modificado para usar o header local
#include <stdio.h>
#include "fnrandom.h"

int
main (void)
{
  int i1, i2;
  int j1, j2;

  /* The C standard says that "If rand is called before any calls to
     srand have been made, the same sequence shall be generated as
     when srand is first called with a seed value of 1." */
  // i1 = rand();
  // i2 = rand();
  for (int i=0;i<10;i++) {
    printf ("%d\n", rand());
  }
  puts ("new seed");
  srand (1023);
  for (int i=0;i<10;i++) {
    printf ("%d\n", rand());
  }
  puts ("same seed");
  srand (1023);
  for (int i=0;i<10;i++) {
    printf ("%d\n", rand());
  }
}
