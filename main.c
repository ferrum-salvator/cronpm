#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse(char* cmd)
  // Returns time interval in seconds
{
  int time = 0;
  // Minutes
  if (strstr(cmd, "*/")) {
    int period_start, period_end, j = 0;
    /* char *e, *t = NULL; */
    char *e;
    char t[256];
    e = strchr(cmd, '/');
    e+=1; // Two symbols
    period_start = (int)(e - cmd);
    /* (void)strncpy(t, cmd, period_start); */
    e = strchr(cmd, ' ');
    period_end = (int)(e - cmd);
    e = NULL;
    for (int i = period_start; i < period_end; i++) {
      t[j] = cmd[i];
      j++;
    }
    printf("%s", t);
    /* time = atoi(e); */
  }
  /* if (cmd[0] != '*') */
  /* { */
  /*     strncpy(str, cmd, 2); */
  /*     str[2] = '\0'; */
  /*     time += 60 * atoi(str); */
  /* } */
  /* // Hours */
  /* if (cmd[3] != '*') */
  /* { */
  /*     strncpy(str, cmd, 2); */
  /*     str[2] = '\0'; */
  /*     time += 3600 * atoi(str); */
  /* } */
  /* // Days */
  /* if (cmd[5] != '*') */
  /* { */
  /*     strncpy(str, cmd, 2); */
  /*     str[2] = '\0'; */
  /*     time += 86400 * atoi(str); */
  /* } */
  /* if (cmd[7] != '*') */
  /* { */
  /*     strncpy(str, cmd, 2); */
  /*     str[2] = '\0'; */
  /*     time += month_len * 86400 * atoi(str); */
  /* } */
  return time;
}

int main(int argc, char* argv[])
{
  int i;
  FILE* f;
  char s[1024];
  char cmds[1024][1024];

  f = popen("/usr/bin/env crontab -l", "r");
  if (f == NULL) {
    printf("Failed\n");
    exit(1);
  }
  i = 0;
  while (fgets(s, sizeof(s), f) != NULL) {
    if ((s[0] != '#') && (!strstr(s, "MAILTO="))) {
      strcpy(cmds[i], s);
      i++;
    }
  }
  parse("*/25 .    ");
  return 0;
}
