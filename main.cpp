#include <stdio.h>

#include "lib/fabString/fabString.h"

int main() {
  //           1         2         3         4
  // 01234567890123456789012345678901234567890
  // GET /inclusao?nome=Maria&valor=123

  printf("Teste total com lib fabString.\n");

  char *a = (char *)malloc(50 * sizeof(char));
  char *b = (char *)malloc(50 * sizeof(char));
  char *c;

  strcpy(a, "abcd");
  printf("%s\n", a);

  size_t tam = strlen(a);

  printf("*** - substr\n");
  for (size_t i = 1; i <= tam; i++) {
    printf("%zu - %s\n", i, substr(a, 0, i));
  }

  printf("\n*** - substrend\n");
  for (size_t i = 0; i < tam; i++) {
    printf("%zu - %s\n", i, substrend(a, i));
  }

  strcpy(a, "GET /inclusao?nome=Maria&valor=123");

  printf("\n*** - strSoNumero\n");
  printf("%s - %s\n", a, strSoNumero(a));

  c = strpart(a, "?", "a&");
  printf("%s\n", c);

  /*
    b = strpart(a, "/", "?");
    if (b) printf("%s\n", b);
    free(b);

    c = substr(a, 2, 5);
    if (c) printf("%s\n", c);
  */
}