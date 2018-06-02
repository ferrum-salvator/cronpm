#include "parse.h"

char* skipspaces(char* s) {
  while ((s != NULL) && ((*s == ' ') || (*s == '\t'))) { // || ())) {
    s++;
  }
  return s; // there is no side effect: we COPY the address when passing!
}

int parseint(char* pattern, char** nextpos) { // iterator! What did you expect?
  int result = 0;
  for(; (*pattern >= '0') && (*pattern <= '9'); pattern += 1) {
    result = result * 10 + *pattern - '0';
  }
  *nextpos = pattern;
  return result;
}

// pattern should be a valid string with null terminator
// or should we use smth try+except?
void tlist(char* pattern, char* result, int size) {
  for(int i=0; i<size; i++) {
    result[i] = 0;
  }
  //currval = parseint()
}

cron_task* parse(char* cmd) {
  cmd = skipspaces(cmd); // no side effect: cmd address is copied!
  if ((cmd == NULL) || (cmd[0] == '#')) {
    return NULL;
  }
  // Period
  char* period_pointer = strchr(cmd, '/') + 1; // next symbol after slash
  cron_task* c = (cron_task*)malloc(sizeof(cron_task));
  c->period = parseint(period_pointer, &period_pointer); // atoi :)))
  while ((*period_pointer == ' ') || (*period_pointer == '*')) {
    period_pointer++; // skip stars /* TODO: skip other periods! */
  }
  strcpy(c->p.name, period_pointer);
  c->p.user[0] = '\0';
  return c;
}

cron_tasks* read_crontab(char* user) { // returns crontab
  FILE* f;
  char exec[256];
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
  // success in getting crontab list
  char s[1024];
  int croncount = 2;
  cron_tasks* cmds = (cron_tasks*)malloc(sizeof(cron_tasks));
  cmds->tasklist = (cron_task**)malloc(croncount * sizeof(cron_task*));
  // I'd prefer list,  not an array to not having to reallocate memory
  cmds->Ntask = 0;
  cron_task* ct;
  while (fgets(s, sizeof(s), f) != NULL) {
    ct = parse(s);
    if (ct != NULL) {
      cmds->tasklist[cmds->Ntask] = ct;
      printf("%i = %s", cmds->Ntask, s);
      cmds->Ntask++;
      if (cmds->Ntask >= croncount) { // relong the array of commands
        cmds->tasklist = (cron_task**)realloc(cmds->tasklist,
            (croncount + 64) * sizeof(cron_task*));
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

