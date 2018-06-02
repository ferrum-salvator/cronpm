#ifndef PARSE_H_
#define PARSE_H_

#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Parses crontab structure FIXME
typedef struct {
    process p;
    char *username; // TODO: add when all the files are parsed
    int period; // minutes!
} cron_task;

typedef struct {
    int Ntask;
    cron_task** tasklist;
} cron_tasks;

cron_task* parse(char* cmd);
cron_tasks* read_crontab(char* user);
char* tasktext(cron_task t);
char* crontext(cron_tasks cts);

#endif
