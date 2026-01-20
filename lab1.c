#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "valid.h"
#include "compute.h"

struct Student
{
    char StudentID[20];
    char Name[50];
    int Minor[5];
    int Major[5];
    int TotalMarks[5];
    int Total;
    int Percentage;
    char Grade[3];
    int GradePoint;
    float CGPA;
};


int main()
{
    struct Student s[50];
    char ids[50][20];
    FILE *fp;
    int n,i,j,v;

    fp=fopen("student.txt","r");
    if(fp==NULL)
        return 0;

    fscanf(fp,"%d",&n);

    for(i=0;i<n;i++)
    {
        fscanf(fp,"%s",s[i].StudentID);
        v=ValidStudentID(s[i].StudentID,ids,i);
        if(v!=1)
            continue;
        strcpy(ids[i],s[i].StudentID);

        fscanf(fp," %[^\n]",s[i].Name);
        if(!ValidName(s[i].Name))
            continue;

        for(j=0;j<5;j++)
        {
            fscanf(fp,"%d",&s[i].Minor[j]);
            s[i].Minor[j]=ValidMinor(s[i].Minor[j]);
        }

        for(j=0;j<5;j++)
        {
            fscanf(fp,"%d",&s[i].Major[j]);
            s[i].Major[j]=ValidMajor(s[i].Major[j]);
        }

        ComputeTotalMarks(s[i].Minor,s[i].Major,s[i].TotalMarks);
        s[i].Total=ComputeTotal(s[i].TotalMarks);
        s[i].Percentage=ComputePercentage(s[i].Total);
    }

    fclose(fp);

    printf("\n%-10s %-12s | %-17s | %-19s | %-19s | %-19s | %-19s | %-5s %-5s %-5s\n",
           "ID","NAME","SUB1","SUB2","SUB3","SUB4","SUB5","TOT","PERC","CGPA");

    printf("%-10s %-12s | Min Maj Tot Gr GP      Min Maj Tot Gr GP    Min Maj Tot Gr GP    Min Maj Tot Gr GP    Min Maj Tot Gr GP\n",
           "","");

    printf("---------------------------------------------------------------------------------------------------------------\n");

    for(i=0;i<n;i++)
    {
        float cgpaSum = 0.0;

        printf("%-10s %-12s",s[i].StudentID,s[i].Name);

        for(j=0;j<5;j++)
        {
            char g[3];
            float gp;

            gp = SubjectGradePoint(s[i].TotalMarks[j], g);
            cgpaSum += gp;

            printf(" | %3d %3d %3d %-2s %4.1f",
                   s[i].Minor[j],
                   s[i].Major[j],
                   s[i].TotalMarks[j],
                   g,
                   gp);
        }

        s[i].CGPA = cgpaSum / 5.0;

        printf(" | %4d %4d %4.2f\n",
               s[i].Total,
               s[i].Percentage,
               s[i].CGPA);
    }

    return 0;
}

