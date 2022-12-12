#include <iostream>
#include <unistd.h>
using namespace std;
int main(){
    int pid;
    cout<<"Execution before fork"<<endl;
    pid = fork();
    cout<<"Execution after fork"<<endl;
    cout<<pid<<endl;
}