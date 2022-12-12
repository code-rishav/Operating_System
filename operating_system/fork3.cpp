#include <iostream>
#include <unistd.h>
using namespace std;
int main(){
    int pid;
    cout<<"Execution before fork"<<endl;
    pid = fork();
    if(pid>0){
         cout<<"Parent execution"<<endl;
         wait(NULL);//waiting for the child to finish
    }
    else{
        cout<<"Child execution"<<endl;
        for(long long i=0;i<1000000;i++);
    }
    
    cout<<"Execution after fork"<<endl;
    cout<<pid<<endl;
}