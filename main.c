#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
