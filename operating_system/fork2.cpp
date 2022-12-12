#include <iostream>
#include <unistd.h>
using namespace std;
int main(){
    int pid;
    cout<<"Execution before fork"<<endl;
    pid = fork();
    if(pid>0)
    cout<<"Parent execution"<<endl;
    else
    cout<<"Child execution"<<endl;
    cout<<"Execution after fork"<<endl;
    cout<<pid<<endl;
}