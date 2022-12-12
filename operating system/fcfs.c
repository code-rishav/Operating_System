#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int size,current,itime=0,ftime=0,next=0,waittime=0;
    double totaltat=0.0,totalwt=0.0;
    printf("Enter the number of prcesses: \n");
    scanf("%d",&size);

    int *burst = calloc(size, sizeof(int)); //to store the burst time of each process

    for(int i=0;i<size;i++){
        printf("Enter the burst time for process: %d\n",i+1);
        scanf("%d", burst + i);
    }
    printf("Process \t\t\t Burst Time \t\t\t\t Turn Around time \t\t\t\t Waiting Time \n");
    for(int i=0;i<size;i++){
        current = *(burst+i);
        ftime +=current;
        itime  = ftime - current;
        totaltat+= ftime;
        waittime = totaltat - ftime;
        totalwt+=waittime; 
        printf("%d\t\t\t\t %d\t\t\t\t\t %d\t\t\t\t\t\t %d",i+1,current,ftime,waittime);
        printf("\n");
    }
    printf("\n Average wait time: %f\n Average Turn Around Time: %f\n",(totalwt/size),(totaltat/size));
}