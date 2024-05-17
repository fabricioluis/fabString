#include "lib/fabString/fabString.h"
#include <stdio.h>

int main() {
  printf("Teste total com lib fabString.\n");

  char *a = (char *)malloc(50 * sizeof(char));
  char *b = (char *)malloc(50 * sizeof(char));
  char *temp = (char *)malloc(50 * sizeof(char));

  //          1         2         3         4
  // 1234567890123456789012345678901234567890
  // GET /inclusao?nome=Maria&valor=123

  strcpy(a, "GET /inclusao?nome=Maria&valor=123");

  printf("%s\n", a);

  b = substr(a, 5, 9);
  printf("%s\n", b);

  b = strpart(a, "?", "&");
  printf("%s\n", b);
}