#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int period;
  char script_name[];
} cron_task;

cron_task parse(char* cmd)
{
  cron_task c;
  // Period
  int period_start, period_end, j = 0, k = 0;
  char* t = (char*)malloc(256*sizeof(char));
  /* char t[256]; */
  t = strchr(cmd, '/');
  t += 1; // Two symbols
  period_start = (int)(t - cmd);
  t = strchr(cmd, ' ');
  period_end = (int)(t - cmd);
  t -= 1;
  for (int i = period_start; i < period_end; i++) {
    t[j] = cmd[i];
    j++;
  }
  c.period = atoi(t);
  // Script name
  j = period_end;
  while ((cmd[j] == ' ') || (cmd[j] == '*')) {
    j++;
  }
  for (int i = j; i < (int)(sizeof(cmd)/sizeof(char)); i++){
    c.script_name[k] = cmd[i];
    k++;
  }
  return c;
  free(t);
}

int main(int argc, char* argv[])
{
  int i;
  FILE* f;
  char s[1024];
  cron_task cmds[1024];

  f = popen("/usr/bin/env crontab -l", "r");
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
  printf("%s %d\n", t.script_name, t.period);
  return 0;
}
