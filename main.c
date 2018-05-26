#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *f;
    char s[1035];

    f = popen("/usr/bin/env crontab -l", "fp");
    if (f == NULL) 
    {
        printf("Failed\n");
        exit(1);
    }
    while (fgets(s, sizeof(s), f) != NULL)
    {
        if (s[0] != '#')
        {
            printf("%s\n", s);
        }
    }
    return 0;
}
