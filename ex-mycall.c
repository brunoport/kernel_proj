/*
 * Uso da nova chamada de sistema
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char *buf = "5+2";
  int r = syscall(384,buf);
  printf("Chamei com %s, Retorno da chamada de sistema: %d.\n",buf, r);
  return 0;
}
