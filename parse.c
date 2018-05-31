#include "parse.h"

cron_task parse(char* cmd)
{
  cron_task c;
  // Period
  int period_start, period_end, j = 0;
  char* period_pointer = strchr(cmd, '/') + 1; // next symbol after slash
  c.period = 0;                                // atoi :)))
  while ((*period_pointer != '\0') && (*period_pointer != ' ')) {
    c.period = c.period * 10 + *period_pointer - '0';
    period_pointer++;
  }
  while ((*period_pointer == ' ') || (*period_pointer == '*')) {
    period_pointer++; // skip stars /* TODO: skip other periods! */
  }
  strcpy(c.p.name, period_pointer);
  return c;
}

void read_crontab(char* user)
{
  int i;
  FILE* f;
  char s[1024];
  char exec[256];
  cron_task cmds[4096]; // the situation when there are lots of processes is
  // our main goal; So let's consider, we can have 4 thousand processes!
  // I'd prefer list,  not an array to not having to reallocate memory
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
      printf("%i = %s", i, s);
      i++;
    }
  }
};
