#include <stdio.h>

struct Node
{
    /* data */
    int data;
    struct Node* next;
    Node(int x){

    }
};

int main(){
    int size,i;
    printf("Enter the number of processes: ");
    scanf("%d",&size);

    struct Node* arv = NULL;
    struct Node* brst = NULL;

    int burst[size],arrival[size],process[size],wait[size],tat[size],start[size],finish[size];
    double avg_wt,avg,tat;
    for(i = 0;i<size;i++){
        printf("enter the arrival time for process %d\n",i+1);
        scanf("%d",&arrival[i]);
        printf("enter the burst time for process %d\n",i+1);
        scanf("%d",&burst[i]);
        process[i] = i+1;
    }
     for(i=0;i<size;i++)
    printf("%d ",arrival[i]);
    printf("\n");

    for(i=0;i<size;i++)
    printf("%d ",burst[i]);
    printf("\n");

    //sort the arrays according to the arrival time
    int min=arrival[0],comp=0,j,temp;
    for(i=0;i<size;i++){
        min = i;
         j=i+1;
        while(j<size){
            if(burst[j]<=burst[min])
            min = j;
            j++;
            comp++;
            }
            temp = arrival[i];
            arrival[i] = arrival[min];
            arrival[min] = temp;

            temp = burst[i];
            burst[i] = burst[min];
            burst[min] = temp; 

            temp = process[i];
            process[i] = process[min];
            process[min] = temp;   
    }


}
