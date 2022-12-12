#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int main(int arg,char *args[]){
    struct stat buffer;
    char *p[10];
    if(args==1){
        printf("no file name passed,enter file name \n");
        return 0;
    }
    int fileo = open(args[1], O_RDONLY);
    int status = fstat(fileo,&buffer);
    //ctime function to convert seconds to valid readable form
    printf("Last time of file access %s",ctime(&buffer.st_atime)); 
    //to convert the file permission to valid string where p is passed as character array to store
    strmode(buffer.st_mode,p); 
    printf("permissions of file %s \n",p);  
}