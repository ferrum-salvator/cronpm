#include <stdio.h>
#include <string.h>

int main()
{
  char source[256] = "123456";
  char dest[256] = "";
  strncpy(dest, source, 4);
  printf("%s", dest);
}
