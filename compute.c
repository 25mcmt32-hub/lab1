#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "compute.h"


void ComputeTotalMarks(int minor[], int major[], int totalmarks[])
{
    int i;
    for(i=0;i<5;i++)
    {
        if(minor[i]==-1 || major[i]==-1)
            totalmarks[i]=-1;
        else
            totalmarks[i]=minor[i]+major[i];
    }
}

int ComputeTotal(int totalmarks[])
{
    int i,sum=0;
    for(i=0;i<5;i++)
        if(totalmarks[i]!=-1)
            sum+=totalmarks[i];
    return sum;
}

int ComputePercentage(int total)
{
    return (total*100)/500;
}

float SubjectGradePoint(int marks, char grade[])
{
    if(marks > 89){ strcpy(grade,"O"); return 10.0; }
    if(marks >= 85){ strcpy(grade,"A+"); return 9.0; }
    if(marks >= 75){ strcpy(grade,"A"); return 8.0; }
    if(marks >= 65){ strcpy(grade,"B+"); return 7.0; }
    if(marks >= 60){ strcpy(grade,"B"); return 6.0; }
    if(marks >= 55){ strcpy(grade,"C"); return 5.0; }
    if(marks >= 50){ strcpy(grade,"D"); return 4.0; }
    strcpy(grade,"F");
    return 0.0;
}

