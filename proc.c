#include<stdio.h>
int main()
{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    printf("Enter total number of processes to be processed : ");
    scanf("%d", &n);
    printf("\nEnter Process Burst Time in ms (dont type ms)\n");
    for(i=0;i<n;i++)
    {
        printf("Process %d - ", i+1);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;  
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
    printf("\nProcess ID\tB Time\t\tW Time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nProcess %d\t%d ms\t\t%d ms\t\t%d ms",i+1,bt[i],wt[i],tat[i]);
    }
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time - %d ms",avwt);
    printf("\nAverage Turnaround Time - %d ms\n",avtat);
    return 0;
}
