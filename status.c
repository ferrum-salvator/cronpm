#include "status.h"

process* getProcesses(char n[256])
{
  FILE* f;
  process* p;
  char exec[256], t[256], s[1024];
  int i = 0, j = 0;
  snprintf(exec, sizeof(exec),
      "/bin/sh -c \"ps -eo uname,time,pid,cmd | egrep \"%s\"", n);
  f = popen("exec", "r");
  if (f == NULL) {
    printf("Failed\n");
    exit(1);
  }
  while (fgets(s, sizeof(s), f) != NULL) {
    while (s[j] != ' ') {
      t[j] = s[j];
      j++;
    }
    strcpy(p[i].user, t);
    i++;
  }

  return p;
}
