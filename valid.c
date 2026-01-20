#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "valid.h"
int ValidStudentID(char id[], char ids[][20], int count)
{
    int i;
    if(strlen(id)!=8)
        return 0;

    for(i=0;id[i];i++)
        id[i]=toupper(id[i]);

    if(!(strncmp(id,"25MCMT",6)==0 || strncmp(id,"25MCMI",6)==0))
        return 0;

    if(!isdigit(id[6]) || !isdigit(id[7]))
        return 0;

    for(i=0;i<count;i++)
        if(strcmp(id,ids[i])==0)
            return -1;

    return 1;
}

int ValidName(char name[])
{
    int i;
    for(i=0;name[i];i++)
    {
        if(name[i]==' ')
            continue;
        if(!isalpha(name[i]))
            return 0;
        name[i]=toupper(name[i]);
    }
    return 1;
}

int ValidMinor(int m)
{
    if(m<0 || m>40)
        return -1;
    return m;
}

int ValidMajor(int m)
{
    if(m<0 || m>60)
        return -1;
    return m;
}
