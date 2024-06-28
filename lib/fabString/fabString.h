/*
 * Autor: Fabricio Luis
 * Versao: 240609.1535
 * fabString.h
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void int2bin(int numero, int qtdeBits, int bits);

void impAscii(char *str1);

char *stralltrim(char *str1);

char *strltrim(char *str1);

char *strrtrim(char *str1);

char *strlrtrim(char *str1);

char *strpart(char *str1, const char *str2, const char *str3);

int strpos(char *str1, const char *str2, int n = -1);

int strposf(char *str1, const char *str2);

char *strSoNumero(char *str1);

char *substrend(char *str1, size_t pos);

char *substr(char *str1, size_t pos, size_t tam);
