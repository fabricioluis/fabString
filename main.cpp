#include <stdio.h>
#include <sys/sysinfo.h>

#include <iomanip>
#include <iostream>

#include "lib/fabString/fabString.h"

void getMemoryInfo();

int main() {
  getMemoryInfo();
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

  b = strpart(a, "?", "ddd");
  if (b) printf("%s\n", b);
  // free(b);

  strcpy(a, " b a ");

  b = strrtrim(a);
  getMemoryInfo();

  if (b) printf("%s - %ld\n", b, strlen(b));
  free(b);
}

void getMemoryInfo() {
  long long totalRAM;
  long long freeRAM;

  struct sysinfo si;
  sysinfo(&si);

  totalRAM = si.totalram;
  freeRAM = si.freeram;

  printf("%lld\n", totalRAM);
  printf("%lld\n", freeRAM);
}