#include "parse.h"

cron_task parse(char* cmd)
{
  cron_task c;
  // Period
  int period_start, period_end, j = 0, k = 0;
  char* e;
  e = strchr(cmd, '/');
  e += 1; // Two symbols
  period_start = (int)(e - cmd);
  e = strchr(cmd, ' ');
  period_end = (int)(e - cmd);
  e = (char*)malloc(256);
  for (int i = period_start; i < period_end; i++) {
    e[j] = cmd[i];
    j++;
  }
  printf("%s", e);
  c.period = atoi(e);
  // Script name
  j = period_end;
  while ((cmd[j] == ' ') || (cmd[j] == '*')) {
    j++;
  }
  for (int i = j; i < (int)(sizeof(cmd) / sizeof(char)); i++) {
    c.script_name[k] = cmd[i];
    k++;
  }
  return c;
}
