#include <iostream>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int main(){

    //declaring file descriptor of source and destination files
    int fopen,fwrite; 
    fopen = open("original.txt",O_RDONLY); 
    char ch;
    fwrite = open("final.txt",O_WRONLY);

    while(read(fopen,&ch,1)){//reading and storing the characters on the buffer of size of 1 byte
        write(fwrite,&ch,1); // writing the content of buffer ch into the file
    }

    cout<<"Copied Successfully"<<endl;
    //closing the resources
    close(fopen);
    close(fwrite);

}