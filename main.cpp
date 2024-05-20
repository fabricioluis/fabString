#include <stdio.h>

#include "lib/fabString/fabString.h"

int main() {
  printf("Teste total com lib fabString.\n");

  char *a = (char *)malloc(50 * sizeof(char));
  char *b = (char *)malloc(50 * sizeof(char));
  char *temp = (char *)malloc(50 * sizeof(char));

  //          1         2         3         4
  // 1234567890123456789012345678901234567890
  // GET /inclusao?nome=Maria&valor=123

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

  printf("\n*** - strSoNumero\n");
  strcpy(a, "GET /inclusao?nome=Maria&valor=123");
  printf("%s - %s\n", a, strSoNumero(a));

  /*
        b = substr(a, 5, 4);
        if (b)
          printf("%s - %ld\n", b, strlen(b));

        b = strpart(a, "?", "&");
        if (b)
          printf("%s\n", b);

        b = substrend(a, 30);
        if (b)
          printf("%s\n", b);
      */
}