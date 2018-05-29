#include "parse.h"

cron_task parse(char* cmd)
{
  cron_task c;
  // Period
  int period_start, period_end, j = 0, k = 0;
  char* period_pointer = strchr(cmd, '/') + 1; // next symbol after slash
  c.period = 0;                                // atoi :)))
  while ((*period_pointer != '\0') && (*period_pointer != ' ')) {
    c.period = c.period * 10 + *period_pointer - '0';
    period_pointer++;
  }
  /* period_pointer += 1; */ // Two symbols
  /* period_start = (int)(period_pointer - cmd); */
  /* period_pointer = strchr(cmd, ' '); */
  /* period_end = (int)(period_pointer - cmd); */
  /* period_pointer = (char*)malloc(256); */
  /* for (int i = period_start; i < period_end; i++) { */
  /*   period_pointer[j] = cmd[i]; */
  /*   j++; */
  /* } */
  /* c.period = atoi(period_pointer); */
  /* free(period_pointer); */
  // Script name
  /* j = period_end; */
  /* while ((cmd[j] == ' ') || (cmd[j] == '*')) { */
  /*  j++; */
  /* } */
  while ((*period_pointer == ' ') || (*period_pointer == '*')) {
    period_pointer++; // skip stars /* TODO: skip other periods! */
  }
  /* for (int i = j; i < (int)(sizeof(cmd) / sizeof(char)); i++) {
    c.p.name[k] = cmd[i];
    k++;
  } */
  strcpy(c.p.name, period_pointer);
  /* while (*period_pointer != '\0') {
    c.p.name[k] = *period_pointer;
    *period_pointer++;
  }
  c.p.name[k] = '\0'; */
  return c;
}

void read_crontab(char* user)
{
  int i;
  FILE* f;
  char s[1024];
  char exec[256];
  cron_task cmds[64];
  snprintf(exec, sizeof(exec),
      "/bin/sh -c \"crontab -u %s -l\"", user);
  f = popen(exec, "r");
  if (f == NULL) {
    printf("Failed\n");
    exit(1);
  }
  i = 0;
  while (fgets(s, sizeof(s), f) != NULL)
  {
    if (strstr(s, "*/")) {
      cmds[i] = parse(s);
      i++;
    }
  }
};
