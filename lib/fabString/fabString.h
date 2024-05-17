/*
 * Autor: Fabricio Luis
 * Versao: 221002.1259
 * fabString.h
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void impint2bin(int b, int bits);

void impAscii(char *str1);

char *int2bin(int numero, int bits);

char *stralltrim(char *str1);

char *strltrim(char *str1);

char *strrtrim(char *str1);

char *strlrtrim(char *str1);

char *strpart(char *str1, const char *str2, const char *str3);

int strpos(char *string, const char *found);

int strposf(char *str1, const char *str2);

int str2int(char *str1);

char *strSoNumero(char *str1);

char *substrend(char *str1, int pos);

char *substr(char *str1, int pos, int tam);
