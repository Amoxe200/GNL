#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "get_next_line.h"

int main()
{
    int p;
    char *line;
    p = open("normal.txt",O_RDONLY);
    while ( get_next_line(p,&line) > 0)
    {
        printf("%s\n",line);
        free(line);
    }
    printf("%s\n",line);
    free(line);
    return (0);
}