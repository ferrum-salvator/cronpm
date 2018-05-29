#include "parse.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
  printf("%s\n", getProcesses("aosh")[0].user);
//  printf("%s\n", parse("/*25 ls /").p.name);
  return 0;
}
