#include <stdio.h>
#include <time.h>

void main () {
  struct timespec t;
  clock_gettime(CLOCK_MONOTONIC, &t);
  printf ("%ld, %ld\n", t.tv_sec, t.tv_nsec); // https://www.ibm.com/docs/en/zos/3.1.0?topic=functions-clock-gettime-retrieve-time-specified-clock
}
