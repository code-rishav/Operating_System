#include<stdio.h>
 
int main()
{   int size;    
    printf("Enter Total Number of Process:");
    scanf("%d",&size);
    int burst[size],prt[size],wait[size],tat[size],pr[size],i,j,n,total=0,pos,temp;
   
    double avg_wt,avg_tat;
    for(i = 0;i<size;i++){
        printf("enter the burst time for process %d\n",i+1);
        scanf("%d",&burst[i]);
        printf("enter the priority for process %d\n",i+1);
        scanf("%d",&prt[i]);

    }

    for(i=0;i<size;i++)
    {
        pos=i;
        for(j=i+1;j<size;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;
 
        temp=prt[i];
        prt[i]=prt[pos];
        prt[pos]=temp;
    }
 
    wait[0]=0; 
 
    //calculate waiting time
    for(i=1;i<size;i++)
    {
        wait[i]=0;
        for(j=0;j<i;j++)
            wait[i]+=burst[j];
 
        total+=wait[i];
    }
 
    avg_wt=total/size;      
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<size;i++)
    {
        tat[i]=burst[i]+wait[i];     
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",prt[i],burst[i],wait[i],tat[i]);
    }
 
    avg_tat=total/size;     
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
 
return 0;
}