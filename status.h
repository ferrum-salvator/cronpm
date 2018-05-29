#ifndef STATUS_H_
#define STATUS_H_
#include "process.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

process* getProcesses(char n[256]);

int getStatus(process p);

void printKillable(process* p);

#endif
