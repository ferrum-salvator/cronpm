#ifndef PROCESS_H_
#define PROCESS_H_
typedef struct {
    char name[256];
    int uptime;
    int user;
} process;
#endif
