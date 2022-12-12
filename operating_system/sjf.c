#include<stdio.h>
#include<string.h>
int main()
{
    int size,i,j,temp;

    printf("Enter the number of process:");
    scanf("%d",&size);
    int burst[size],arrival[size],process[size],wait[size],tat[size],start[size],finish[size];
    int totwt=0,totta=0;
    float avg_wt,avg_tat;
    
    for(i = 0;i<size;i++){
        printf("enter the arrival time for process %d\n",i+1);
        scanf("%d",&arrival[i]);
        printf("enter the burst time for process %d\n",i+1);
        scanf("%d",&burst[i]);
        process[i] = i+1;
    }
    for(i=0; i<size; i++)
        for(j=0; j<size; j++)
        {
            if(burst[i]<burst[j])
            {
                temp=arrival[i];
                arrival[i]=arrival[j];
                arrival[j]=temp;

                temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;

                temp=process[i];
                process[i]=process[j];
                process[j]=temp;
            }
        }

    for(i=0; i<size; i++)
    {
        if(i==0)
            start[i]=arrival[i];
        else
            start[i]=finish[i-1];
        wait[i]=start[i]-arrival[i];
        finish[i]=start[i]+burst[i];
        tat[i]=finish[i]-arrival[i];
        totwt+=wait[i];
        totta+=tat[i];
    }
    avg_wt=(float)totwt/size;
    avg_tat=(float)totta/size;
    printf("\nPname\tarrivaltime\texecutiontime\twaitingtime\ttatime");
    for(i=0; i<size; i++)
        printf("\n%d\t%5d\t\t%5d\t\t%5d\t\t%5d",process[i],arrival[i],burst[i],wait[i],tat[i]);
    printf("\nAverage waiting time is:%f",avg_wt);
    printf("\nAverage turnaroundtime is:%f",avg_tat);
}