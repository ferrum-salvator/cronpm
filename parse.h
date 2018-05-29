#ifndef PARSE_H_
#define PARSE_H_

#include "process.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Parses crontab structure FIXME
typedef struct {
    process p;
    int period;
} cron_task;

cron_task parse(char* cmd);

#endif
