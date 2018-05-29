#include "parse.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
  int i;
  FILE* f;
  char s[1024];
  char exec[256];
  cron_task cmds[64];

  snprintf(exec, sizeof(exec),
      "/usr/bin/env sh -c \"crontab %s -l\"", argv[1]);
  printf("%s", exec);
  f = popen(exec, "r");
  if (f == NULL) {
    printf("Failed\n");
    exit(1);
  }
  i = 0;
  while (fgets(s, sizeof(s), f) != NULL) {
    if (strstr(s, "*/")) {
      cmds[i] = parse(s);
      i++;
    }
  }
  cron_task t = parse("*/25 .  bepis  ");
  printf("%s\n%d\n", t.script_name, t.period);
  return 0;
}
