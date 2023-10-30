//Orphan Process
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main() {
	int p = fork();
	if( p > 0) {
		cout<<"-----------In Parent Process-----------"<<endl;
		cout<<"Parent Process1: "<<getpid()<<endl;
		cout<<"Child Process1: "<<p<<endl<<endl;
		exit(0);
		
	}
	else {
		cout<<"-----------In Child Process-----------"<<endl;
		cout<<"(Before parent process dies)"<<endl;
		cout<<"Child Process2: "<<getpid()<<endl;
		cout<<"Parent Process2: "<<getppid()<<endl;
		sleep(10);
		cout<<endl<<"-----------In Child Process-----------"<<endl;
		cout<<"(After parent process dies)"<<endl;
		cout<<"Child Process2: "<<getpid()<<endl;
		cout<<"Parent Process2: "<<getppid()<<endl;
		system("ps -a1");
	}
	return 0;
}
