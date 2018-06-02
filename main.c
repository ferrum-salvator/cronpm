#include "parse.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
  char *username = (char*)malloc(5);
  strcpy(username, "aosh");
  if (argc > 1)
  {
    username = argv[1];
  }
  cron_tasks crontbl = read_crontab(username);
  printf("Cron has %i tasks:\n", crontbl.Ntask);
  for(int i = 0; i < crontbl.Ntask; i++) {
    printf("Peiod: %i, task:%s, user:%s\n",
        crontbl.tasklist[i].period,
        crontbl.tasklist[i].p.name,
        crontbl.tasklist[i].p.user
        );
  }
  process* plist = getProcesses(username);
  printf("%s\n", plist[0].user);
//  printf("%s\n", parse("/*25 ls /").p.name);
  return 0;
}
