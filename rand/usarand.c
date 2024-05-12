#include <stdio.h>
#include <stdlib.h>

void main () {
  //srand(1023);   // Initialization, should only be called once.
  int r;
  for (int i=1;i<20;i++) {
    r = rand();
    printf ("%d\n", r);
  }
  puts ("new seed");
  srand(1023);   // Initialization, should only be called once.
  for (int i=1;i<10;i++) {
    r = rand();
    printf ("%d\n", r);
  }
  puts ("same seed");
  srand(1023);   // Initialization, should only be called once.
  for (int i=1;i<10;i++) {
    r = rand();
    printf ("%d\n", r);
  }
}

