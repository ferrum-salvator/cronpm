#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *parse(char *cmd)
// Returns time interval in seconds
{
    int time = 0;
    char str[3];
    // Minutes
    if (cmd[0] != '*')
    {
        strncpy(str, cmd, 2);
        str[2] = '\0';
        time += 60 * atoi(str);
    }
    // Hours
    if (cmd[3] != '*')
    {
        strncpy(str, cmd, 2);
        str[2] = '\0';
        time += 3600 * atoi(str);
    }
    // Days
    if (cmd[5] != '*')
    {
        strncpy(str, cmd, 2);
        str[2] = '\0';
        time += 86400 * atoi(str);
    }
    if (cmd[7] != '*')
    {
        strncpy(str, cmd, 2);
        str[2] = '\0';
        time += month_len * 86400 * atoi(str);
    }
    return time;
}

int main(int argc, char *argv[])
{
    int i;
    FILE *f;
    char s[1024];
    char commands[1024][1024];

    f = popen("/usr/bin/env crontab -l", "r");
    if (f == NULL) 
    {
        printf("Failed\n");
        exit(1);
    }
    i = 0;
    while (fgets(s, sizeof(s), f) != NULL)
    {
        if ((s[0] != '#') && (!strstr(s, "MAILTO=")))
        {
            strcpy(commands[i], s);
            i++;
        }
    }
    return 0;
}
    }
    return time;
}

int main(int argc, char *argv[])
{
    int i;
    FILE *f;
    char s[1024];
    char commands[1024][1024];

    f = popen("/usr/bin/env crontab -l", "r");
    if (f == NULL) 
    {
        printf("Failed\n");
        exit(1);
    }
    i = 0;
    while (fgets(s, sizeof(s), f) != NULL)
    {
        if ((s[0] != '#') && (!strstr(s, "MAILTO=")))
        {
            strcpy(commands[i], s);
            i++;
        }
    }
    return 0;
}
