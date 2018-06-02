#include "parse.h"

cron_task parse(char* cmd)
{
  cron_task c;
  // Period
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
  c.p.user[0] = '\0';
  return c;
}

cron_tasks read_crontab(char* user) { // returns crontab
  FILE* f;
  char s[1024];
  char exec[256];
  int croncount = 64;
  cron_tasks cmds;
  cmds.tasklist = (cron_task*)malloc(croncount * sizeof(cron_task));
  // I'd prefer list,  not an array to not having to reallocate memory
  snprintf(
    exec,
    sizeof(exec),
    "/bin/sh -c \"crontab -u %s -l 2> /dev/null\"",
    // TODO: as root: head -n 100 /var/spool/cron/crontabs/*
    user);
  f = popen(exec, "r"); // TODO: read stdin + stdout and get strno
  if (f == NULL) {
    printf("Failed\n");
    exit(1);
  }
  cmds.Ntask = 0;
  while (fgets(s, sizeof(s), f) != NULL) {
    if (strstr(s, "*/")) {
      cmds.tasklist[cmds.Ntask] = parse(s);
      printf("%i = %s", cmds.Ntask, s);
      cmds.Ntask++;
      if (cmds.Ntask >= croncount) { // relong the array of commands
        cmds.tasklist = (cron_task*)realloc(cmds.tasklist,
            (croncount + 64) * sizeof(cron_task));
        croncount += 64;
      }
    }
  }
  return cmds;
}

char *tasktext(cron_task t) {
  char *txt = (char*)malloc(256);
  // realloc....
  // write crontab
  return txt;
}
char *crontext(cron_tasks cts) {
  char *txt = (char*)malloc(256);
  // realloc....
  // write crontab
  return txt;
}

