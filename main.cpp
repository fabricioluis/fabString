#include <stdio.h>
#include <sys/sysinfo.h>

#include <iomanip>
#include <iostream>

#include "lib/fabString/fabString.h"
#include "../../../../../usr/include/x86_64-linux-gnu/sys/time.h"

void printNum(long long numero);
void getMemoryInfo();
double get_microseconds();

//           1         2         3         4
// 01234567890123456789012345678901234567890
// GET /inclusao?nome=Maria&valor=123

int main()
{
  getMemoryInfo();

  char *a = (char *)malloc(50 * sizeof(char));
  char *b = (char *)malloc(50 * sizeof(char));

  // Jah testadas.
  // substr
  // substrend
  // strpart
  // strposf e strposf
  // strrtrim, strltrim e strlrtrim

  /*
    strcpy(a, "abcd");
    printf("%s\n", a);

    size_t tam = strlen(a);

    printf("*** - substr\n");
    for (size_t i = 1; i <= tam; i++)
    {
      printf("%zu - %s\n", i, substr(a, 0, i));
    }

    printf("\n*** - substrend\n");
    for (size_t i = 0; i < tam; i++)
    {
      printf("%zu - %s\n", i, substrend(a, i));
    }

    strcpy(a, "GET /inclusao?nome=Maria&valor=123");
    b = strpart(a, "nome=", "a&v");
    if (b)
      printf("%s (%zu)\n", b, strlen(b));
    free(b);

    int i = strposf(a, "/in");
    printf("i = %d\n", i);

    strcpy(a, "abc  d ");
    b = strrtrim(a);
    printf("%s (%zu)\n", b, strlen(b));
  */

  strcpy(a, " Aa Bb Cc ");
  printf("%s (%zu)\n", a, strlen(a));
  b = stralltrim(a);
  printf("%s (%zu)\n", b, strlen(b));
  impAscii(a);

  int2bin(65535, 32, 4);
  int2bin(65536, 32, 4);

  getMemoryInfo();
  free(a);
  free(b);

  printf("...Fim...\n");
}

void getMemoryInfo()
{
  long long totalRAM;
  long long freeRAM;

  struct sysinfo si;
  sysinfo(&si);

  totalRAM = si.totalram;
  freeRAM = si.freeram;

  printNum(totalRAM);
  printNum(freeRAM);
}

void printNum(long long numero)
{
  printf("%3lld.%3lld.%3lld.%3lld\n", numero / 1000000000,
         (numero % 1000000000) / 1000000, (numero % 1000000) / 1000,
         numero % 1000);
}

double get_microseconds()
{
  struct timeval tv;

  gettimeofday(&tv, NULL);

  double seconds = (double)tv.tv_sec;
  double micros = (double)tv.tv_usec / 1000000;

  return seconds + micros;
}
