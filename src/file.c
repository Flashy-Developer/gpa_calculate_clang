#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

unsigned int    count_line(FILE *file)
{
    unsigned int    line;
    char            c;

    line = 0;
    while (1)
    {
        c = fgetc(file);
        if (c == -1)
            break;
        else if (c == '\n')
            line += 1;
    }
    return (line);
}