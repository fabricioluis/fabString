#include "lib/fabString/fabString.h"
#include <stdio.h>

int main() {
  printf("Teste total com lib fabString.\n");

  char *a = (char *)malloc(50 * sizeof(char));
  strcpy(a, "GET /inclusao?nome=Maria&valor=123");

  printf("%s\n", a);

  char *temp = (char *)malloc(50 * sizeof(char));

  temp = substr(a, 2, 3);
  printf("%s\n", temp);
  free(temp);
}