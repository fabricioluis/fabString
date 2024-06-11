// gcc -c fabString.c -o fabString.o

/*
 * Autor: Fabricio Luis
 * Versao: 240609.1535
 * fabString.c
 */

#include "fabString.h"

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao impint2bin (int b, int bits)
 * Imprime em binario o valor de b na quantidade de bits.
 */
void int2bin(int numero, int qtdeBits, int bits)
{
  // int qtdeBits = ((int)(b / 256) + 1) * 8;
  int tam = qtdeBits + (int)((qtdeBits / bits));
  char *retorno = (char *)malloc(sizeof(char) * tam);
  int pos = 0;

  do
  {
    qtdeBits--;
    if ((numero >> qtdeBits) & 1)
      *(retorno + pos) = '1';
    else
      *(retorno + pos) = '0';
    pos++;

    if (((qtdeBits % bits) == 0) && (qtdeBits != 0))
    {
      *(retorno + pos) = ' ';
      pos++;
    }
  } while (qtdeBits > 0);
  *(retorno + pos) = '\0';
  printf("%s (%d)\n", retorno, numero);
  free(retorno);
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao impAscii (char *str1)
 * Imprime cada caracter e o seu valor ASCII da String str1
 */
void impAscii(char *str1)
{
  for (size_t i = 0; i < strlen(str1); i++)
  {
    printf("%c : %d\n", *(str1 + i), (int)*(str1 + i));
  }
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao stralltrim (char *str1)
 * Retorna da String str1 somente os caracteres que estivem na String alfabeto.
 */
char *stralltrim(char *str1)
{
  // const char *alfabeto =
  //     "abcçdefghijklnmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.;:?[]!@"
  //     "#$%&*()-_=+{}\\|/<>";

  // conta quantos espacos tem a str1.
  int ctEspaco = 0;
  for (size_t i = 0; i < strlen(str1); i++)
  {
    if (*(str1 + i) == ' ')
      ctEspaco++;
  }

  int tam = strlen(str1);
  int j = 0;

  // Define tamanho do retorno a str1 sem os espacos.
  char *retorno = (char *)malloc(tam - ctEspaco + 1);

  for (size_t i = 0; i < strlen(str1); i++)
  {
    if (*(str1 + i) != ' ')
    {
      *(retorno + j) = *(str1 + i);
      j++;
    }
  }
  *(retorno + j) = '\0';

  return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao strlrtrim (*char *str1)
 * Retorna a String str1 sem os espacos em branco aa esquerda e tambem aa
 * direita.
 */
char *strlrtrim(char *str1) { return (strltrim(strrtrim(str1))); }

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao strltrim (*char *str1)
 * Retorna a String str1 sem os espacos em branco aa esquerda.
 */
char *strltrim(char *str1)
{
  char *retorno = (char *)malloc(strlen(str1));
  int j = 0;

  bool achou = false;
  for (size_t i = 0; i < strlen(str1); i++)
  {
    if (*(str1 + i) != ' ')
    {
      achou = true;
    }

    if (achou)
    {
      *(retorno + j) = *(str1 + i);
      j++;
    }
  }
  *(retorno + j) = '\0';

  return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao strrtrim (char *str1)
 * Retorna a String str1 sem os espacos em branco aa direita.
 */
char *strrtrim(char *str1)
{
  size_t tam = strlen(str1);
  char *retorno = (char *)malloc(tam * sizeof(char));
  if (retorno == NULL)
    return NULL;

  bool achou = false;
  int i = tam - 1;

  while (i >= 0)
  {
    if ((*(str1 + i) != ' ') && (!achou))
    {
      *(retorno + i + 1) = '\0';
      achou = true;
    }
    if (achou)
      *(retorno + i) = *(str1 + i);

    i--;
  }

  return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao strpart (char *str1, char *str2, char *str3)
 * Retorna parte da String str1 que esta entre str2 e str3.
 */
char *strpart(char *str1, const char *str2, const char *str3)
{
  // Pega a posicao final da String 2
  int posStr2_F = strposf(str1, str2);

  // Pega a posicao inicial da String 3
  int posStr3_I = strpos(str1, str3);

  if ((posStr2_F == -1) || (posStr2_F > posStr3_I))
    return NULL;

  char *retorno = (char *)malloc((posStr3_I - posStr2_F) * sizeof(char));
  if (!retorno)
    return NULL;

  int ct = 0;
  while (posStr2_F < posStr3_I)
  {
    *(retorno + ct) = *(str1 + posStr2_F);
    ct++;
    posStr2_F++;
  }

  return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao strpos (char *str1, char *str2)
 * Retorna a posicao do inicio de str2 em str1; O primeiro caractere eh 0
 * str1 - string a ser varrida
 * str2 - string a ser encontrada em str1
 * Senao encontrar, retorna -1.
 */
int strpos(char *str1, const char *str2)
{
  char *pos = strstr(str1, str2);
  if (pos == NULL)
    return -1;

  return pos - str1;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao strposf (char *str1, char *str2)
 * Retorna a posicao apos o final da String str2 dentro da String str1
 * Se nao encontrar, retorna -1.
 */
int strposf(char *str1, const char *str2)
{
  int retorno = strpos(str1, str2);

  if (retorno == -1)
    retorno = -1;
  else
    retorno += strlen(str2);

  return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao strSoNumero (char *str1)
 * Retorna da String str1 somente o que for numerico.
 */
char *strSoNumero(char *str1)
{
  const char *alfabeto = "0123456789";
  char *retorno = (char *)malloc(strlen(str1));
  if (!retorno)
    return NULL;

  size_t j = 0;

  for (size_t i = 0; i < strlen(str1); i++)
  {
    for (size_t alf = 0; alf < strlen(alfabeto); alf++)
    {
      if (*(str1 + i) == *(alfabeto + alf))
      {
        *(retorno + j) = *(str1 + i);
        j++;
      }
    }
  }

  return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao substrend (char *str1, int pos)
 * Retorna um pedaco da str1 que inicia na posicao (pos) e vai ate o final da
 * string. Primeira posicao = 0
 */
char *substrend(char *str1, size_t pos)
{
  if (pos == 0)
    return str1;

  size_t tamStr1 = strlen(str1);

  if (pos > tamStr1)
    return NULL;

  size_t tamRetorno = (tamStr1 - pos) + 1;

  char *retorno = (char *)malloc(tamRetorno * sizeof(char));
  if (!retorno)
    return NULL;

  for (size_t i = 0; i < tamRetorno; i++)
    *(retorno + i) = *(str1 + pos + i);

  *(retorno + tamRetorno) = '\0';
  return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao substr (char *string, int pos, int tam)
 * Retorna um pedaco da String que inicia na posicao (pos) de tamanho (tam)
 * Primeira posicao = 0
 */
char *substr(char *str1, size_t pos, size_t tam)
{
  size_t tamStr1 = strlen(str1);

  // se tamanho ou a posicao forem maiores que a str1 retorna NULL
  if ((tam > tamStr1) || (pos > tamStr1) || ((pos + tam) > tamStr1))
    return NULL;

  // aloca o tamanho da memoria de acordo com o tamanho do retorno.
  char *retorno = (char *)malloc((tam) * sizeof(char));
  if (!retorno)
    return NULL;

  for (size_t i = 0; i < tam; i++)
    *(retorno + i) = *(str1 + pos + i);

  *(retorno + tam) = '\0';
  return retorno;
}
