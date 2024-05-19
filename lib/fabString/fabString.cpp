// gcc -c fabString.c -o fabString.o

/*
 * Autor: Fabricio Luis
 * Versao: 221002.1259
 * fabString.c
 */

#include "fabString.h"

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao impint2bin (int b, int bits)
 * Imprime em binario o valor de b na quantidade de bits.
 */
void impint2bin(int b, int bits)
{
  do
  {
    bits--;
    if ((b >> bits) & 1)
      printf("1");
    else
      printf("0");

    if ((bits % 8) == 0)
      printf(" ");

  } while (bits > 0);
  printf("- %d", b);
  printf("\n");
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao impAscii (char *str1)
 * Imprime cada caracter e o seu valor ASCII da String str1
 */
void impAscii(char *str1)
{
  for (int i = 0; i < strlen(str1); i++)
  {
    printf("%c : %d\n", *(str1 + i), (int)*(str1 + i));
  }
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao int2bin (int numero, int bits)
 * Converte um valor inteiro em binario e mostra em bloco de 8 bits
 */
char *int2bin(int numero, int bits)
{
  int posicao = 0;
  int tamanho = 0;

  char *resultado = (char *)malloc(64);
  char *inverte_resultado = (char *)malloc(64);
  char *saida = (char *)malloc(64);

  do
  {
    *(resultado + posicao++) = (numero % 2) + '0';
    numero = numero >> 1;
  } while (numero >= 2);

  *(resultado + posicao++) = numero + '0';

  for (; posicao < bits; posicao++)
    *(resultado + posicao) = '0';

  posicao--;

  for (int index = 0; index <= posicao; index++)
    *(inverte_resultado + index) = *(resultado + posicao - index);

  tamanho = strlen(inverte_resultado);

  if (tamanho % 8 != 0)
    tamanho = (round(tamanho / 8) + 1) * 8;

  strcpy(resultado, "");

  for (int i = 1; i <= (tamanho - strlen(inverte_resultado)); i++)
    strcat(resultado, "0");

  strcat(resultado, inverte_resultado);

  strcpy(saida, "");
  for (int i = 1; i <= tamanho; i += 8)
  {
    strcat(saida, substr(resultado, i, 8));
    strcat(saida, " ");
  }

  return saida;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao stralltrim (char *str1)
 * Retorna da String str1 somente os caracteres que estivem na String alfabeto.
 */
char *stralltrim(char *str1)
{
  const char *alfabeto =
      "abcçdefghijklnmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.;:?[]!@"
      "#$%&*()-_=+{}\\|/<>";
  char *resultado = (char *)malloc(strlen(str1));
  int j = 0;

  for (int i = 0; i < strlen(str1); i++)
  {
    for (int alf = 0; alf < strlen(alfabeto); alf++)
    {
      if (*(str1 + i) == *(alfabeto + alf))
      {
        *(resultado + j) = *(str1 + i);
        j++;
        break;
      }
    }
  }

  return resultado;
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
  const char *alfabeto =
      "abcçdefghijklnmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.;:?[]!@"
      "#$%&*()-_=+{}\\|/<>";
  char *resultado = (char *)malloc(strlen(str1));
  int i = 0;
  int j = 0;

  for (i = 0; i < strlen(str1); i++)
  {
    for (int alf = 0; alf < strlen(alfabeto); alf++)
    {
      if (*(str1 + i) == *(alfabeto + alf))
      {
        j = i;
        break;
      }
    }
    if (j > 0)
      break;
  }
  resultado = substr(str1, j + 1, strlen(str1) - j);

  return resultado;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao strrtrim (char *str1)
 * Retorna a String str1 sem os espacos em branco aa direita.
 */
char *strrtrim(char *str1)
{
  const char *alfabeto =
      "abcçdefghijklnmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.;:?[]!@"
      "#$%&*()-_=+{}\\|/<>";
  char *resultado = (char *)malloc(strlen(str1));
  int i = 0;
  int j = 0;

  for (i = strlen(str1) - 1; i > 0; i--)
  {
    for (int alf = 0; alf < strlen(alfabeto); alf++)
    {
      if (*(str1 + i) == *(alfabeto + alf))
      {
        j = i + 1;
        break;
      }
    }
    if (j > 0)
      break;
  }
  resultado = substr(str1, 1, j);
  return resultado;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao strpart (char *str1, char *str2, char *str3)
 * Retorna parte da String str1 que esta entre str2 e str3.
 */
char *strpart(char *str1, const char *str2, const char *str3)
{
  char *resultado = NULL;

  int posFinalStr2 = strposf(str1, str2);

  // extrai o final da str1 a partir do final de str2
  char *strTemp = substrend(str1, posFinalStr2);

  int posInicialStr3 = strpos(strTemp, str3);
  if (posInicialStr3 == 0)
    resultado = strTemp;
  else
  {
    posInicialStr3 = posInicialStr3 + posFinalStr2 - 1;
    resultado = substr(str1, posFinalStr2, posInicialStr3 - posFinalStr2);
  }

  return resultado;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao strpos (char *str1, char *str2)
 * Retorna a posicao do inicio de str2 em str1; O primeiro caractere eh 1
 * str1 - string a ser varrida
 * str2 - string a ser encontrada em str1
 * Senao encontrar retorna 0.
 */
int strpos(char *str1, const char *str2)
{
  int posicao = 0;
  int i = 0;
  int j = 0;

  if (strstr(str1, str2) != NULL)
  {
    for (i = 0; i < strlen(str1); i++)
    {
      if (*(str1 + i) == *(str2 + j))
      {
        j++;

        if (posicao == 0) // marca a primeira aparicao
          posicao = i + 1;

        if (j == strlen(str2)) // varreu ate o tamanho de found, entao para.
          break;
      }
      else
      {
        posicao = 0;
        j = 0;
      }
    }
  }

  return posicao;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao strposf (char *str1, char *str2)
 * Retorna a posicao final da String str2 dentro da String str1
 */
int strposf(char *str1, const char *str2)
{
  int resultado = strpos(str1, str2);

  if (resultado == 0)
    resultado = 0;
  else
    resultado = resultado + strlen(str2);

  return resultado;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao int str2int(char *str1);
 * Converter em inteiro a String str1.
 */
int str2int(char *str1)
{
  char a[strlen(str1)];
  sprintf(a, "%d", atoi(str1));
  return atoi(a);
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
 * Retorna um pedaco da str1 que inicia na posicao (pos) e vai ate o final da string.
 * Primeira posicao = 1
 */
char *substrend(char *str1, int pos)
{
  size_t tamStr1 = strlen(str1);

  if (pos > tamStr1)
    return NULL;

  size_t tamRetorno = (tamStr1 - pos) + 1;

  char *retorno = (char *)malloc(tamRetorno * sizeof(char));
  if (!retorno)
    return NULL;

  pos--;

  for (size_t i = 0; i < tamRetorno; i++)
    *(retorno + i) = *(str1 + pos + i);

  *(retorno + tamRetorno) = '\0';
  return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------//
/*
 * Funcao substr (char *string, int pos, int tam)
 * Retorna um pedaco da String que inicia na posicao (pos) de tamanho (tam)
 * Primeira posicao = 1
 */
char *substr(char *str1, int pos, int tam)
{
  size_t tamStr1 = strlen(str1);

  // se tamanho ou a posicao forem maiores que a str1 retorna NULL
  if ((tam > tamStr1) || (pos > tamStr1))
    return NULL;

  // aloca o tamanho da memoria de acordo com o tamanho do retorno.
  char *retorno = (char *)malloc((tam) * sizeof(char));
  if (!retorno)
    return NULL;

  pos--;

  for (size_t i = 0; i < tam; i++)
    *(retorno + i) = *(str1 + pos + i);

  *(retorno + tam) = '\0';
  return retorno;
}
