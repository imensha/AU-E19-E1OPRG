#include <stdio.h>

int main(int argc, char const *argv[])
{
  for (int i = 100; i >= 50; i -= 10)
  {
    printf_s("%d ", i);
  }

  return 0;
}
