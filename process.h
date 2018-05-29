#ifndef PROCESS_H_
#define PROCESS_H_
typedef struct {
    char name[256];
    char user[256];
    int pid;
    int uptime;
} process;
#endif
