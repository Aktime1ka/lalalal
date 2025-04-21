#include <iostream>
#include <csignal>
#include <unistd.h>

enum Signal{
    SIGHUP_SIGNAL,
    SIGINT_SIGNAL
};
using namespace std;


void signalHandler(int signum){
    cout << "HAHAHA I will ignor " << Signal(signum) << "signal! :-O" << endl; 

}

int main(){
    if(signal(SIGHUP,signalHandler) == SIG_ERR){
        cerr <<"ERROE Setting up SIGHUP handler" << endl;
        return 1;
    }
    if(signal(SIGINT,signalHandler) == SIG_ERR){
        cerr <<"ERROE Setting up SIGINT handler" << endl;
        return 2;
    }
    cout << "Program is running" << endl ;
    while(true)
    {
        sleep(1);
    }
  
    return 0;
}