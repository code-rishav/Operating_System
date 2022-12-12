#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


void *sum(void* nums);
int total=0; // to store the total sum of numbers
int size=0; // to keep an account of size of array

int main(int arg,char* args[]){
    pthread_t tid;
    pthread_attr_t attr;
  
    pthread_attr_init(&attr);
    if(arg==1){
        printf("Program terminiated! Enter a number to be added");
        return 0;
    }
    
    else{

        int i;
        arg = arg-1; // to use only the numbers passed, and not the file name

        int slots = arg/5; // to assign each thread 5 elements to compute the sum
        int left = arg%5; // to create a last thread containing the remaining elements

        int count=1;
        int arr1[5]; // to store the elements slots wise
        int arr2[left]; // to store the left elements

        //assigning elements slot wise to the array
        // and passing the array to a newly created thread
        for(int i=0;i<slots;i++){
            for(int j=0;j<5;j++){
             arr1[j] = atoi(args[count]);
             count++;
            }
            size = 5;
            pthread_create(&tid,&attr,sum,(void*)arr1);
            pthread_join(tid,NULL);
        }

        //creating a last thread 
        //and passing the left out elements
        for(int j=0;j<left;j++)
        arr2[j] = atoi(args[count++]);
        size = left;
        
        pthread_create(&tid,&attr,sum,(void*)arr2);
        pthread_join(tid,NULL);
        
    }
    printf("Sum of numbers : %d\n",total);
}
void *sum(void* nums){
    int* numbers = (int*) nums;
    for(int i=0;i<size;i++){
        total +=numbers[i];
    }
    pthread_exit(0);

}
