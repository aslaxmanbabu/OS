#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class process {
	public:
		string id;
		int bt, p;
};

bool compare(process a, process b) {
	return (a.p > b.p);
}

void waitingtime(process pro[], int n, int wt[]) {
   wt[0] = 0;
   for (int i = 1; i < n ; i++ )
      wt[i] = pro[i-1].bt + wt[i-1] ;
}


void turnarround( process pro[], int n, int wt[], int tat[]) {
   for (int i = 0; i < n ; i++)
      tat[i] = pro[i].bt + wt[i];
}
void avgtime(process pro[], int n) {
   int wt[n], tat[n], total_wt = 0, total_tat = 0;
   waitingtime(pro, n, wt);
   turnarround(pro, n, wt, tat);
   cout << "\nProcesses "<< " Burst time " << " Waiting time " << " Turn around time\n";
   for (int i=0; i<n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      cout << " " << pro[i].id << "\t\t" << pro[i].bt << "\t " << wt[i] << "\t\t " << tat[i] <<endl;
   }
   cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
   cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}
void scheduling(process pro[], int n) {
   sort(pro, pro + n, compare);
   avgtime(pro, n);
   cout<<endl<< "Giant Chart\n";
   for (int i = 0 ; i < n; i++)
      cout << pro[i].id <<" " ;
}
int main() {

	int n;
	cout<<"Enter number of process: ";
	cin>>n;
	process pro[n];
	for(int i=0; i<n; i++) {
		cout<<endl<<"------Process "<<i+1<<" ------"<<endl;
		cout<<"Enter process id: ";
		cin>>pro[i].id;
		cout<<"Enter burst time: ";
		cin>>pro[i].bt;
		cout<<"Enter priority: ";
		cin>>pro[i].p;
	}
	
	scheduling(pro, n);
	return 0;

}
