//Zombie_Process
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main() {
	int p = fork();
	if( p > 0) {
		cout<<"-----------Parent Process-----------"<<endl;
		cout<<"Before Child Process dies"<<endl;
		cout<<"Parent Process: "<<getpid()<<endl;
		cout<<"Child Process: "<<p<<endl;
		sleep(10);
		cout<<endl<<"-----------Parent Process-----------"<<endl;
		cout<<"After Child Process dies"<<endl;
		cout<<"Parent Process: "<<getpid()<<endl;
		cout<<"ChildProcess: "<<p<<endl<<endl;
		system("ps -a1");
	}
	else {
		cout<<endl<<"-----------Child Process-----------"<<endl;
		cout<<"Child Process: "<<getpid()<<endl;
		cout<<"Parent Process: "<<getppid()<<endl;
		exit(0);
	}
	return 0;
}
