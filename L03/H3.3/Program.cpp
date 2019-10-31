#include <stdio.h>

int main(int argc, char const *argv[])
{
  /*
  * TYPE:   char
  * DEF:    char
  * FORMAT: %c
  */
  printf_s("--- char, char, %%c ---\n");
  for (char c = 'A'; c <= 'F'; c++)
    printf_s("%c ", c);
  puts("\n");

  /*
  * TYPE:   int
  * DEF:    char
  * FORMAT: %c
  */
  printf_s("--- int, char, %%c ---\n");
  for (int c = 'A'; c <= 'F'; c++)
    printf_s("%c ", c);
  puts("\n");

  /*
  * TYPE:   char
  * DEF:    int
  * FORMAT: %c
  */
  printf_s("--- char, int, %%c ---\n");
  for (char c = 65; c <= 70; c++)
    printf_s("%c ", c);
  puts("\n");

  /*
  * TYPE:   int
  * DEF:    int
  * FORMAT: %c
  */
  printf_s("--- int, int, %%c ---\n");
  for (int c = 65; c <= 70; c++)
    printf_s("%c ", c);
  puts("\n");

  /*
  * TYPE:   char
  * DEF:    char
  * FORMAT: %d
  */
  printf_s("--- char, char, %%d ---\n");
  for (char c = 'A'; c <= 'F'; c++)
    printf_s("%d ", c);
  puts("\n");

  /*
  * TYPE:   int
  * DEF:    char
  * FORMAT: %d
  */
  printf_s("--- int, char, %%d ---\n");
  for (int c = 'A'; c <= 'F'; c++)
    printf_s("%d ", c);
  puts("\n");

  return 0;
}
