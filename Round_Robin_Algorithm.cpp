#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    int i, NOP, sum=0, count=0, y, quantum, wt=0, tat=0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    cout<<"Total no of processes in the system: ";
    cin>>NOP;
    
    y=NOP;
    
    for(i=0;i<NOP;i++)
    {
        cout<<endl<<"Process["<<i+1<<"]"<<endl;
        cout<<"Arrival time is: ";
        cin>>at[i];
        cout<<"Burst time is: ";
        cin>>bt[i];
        temp[i]=bt[i];
    }
    
    cout<<"Enter the Time Quantum: \t";
    cin>>quantum;
    cout<<"\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time";
    for(sum=0,i=0;y!=0;)
    {
        if(temp[i]<=quantum && temp[i]>0)
        {
            sum=sum+temp[i];
            temp[i]=0;
            count=1;
        }
        else if(temp[i]>0)
        {
            temp[i]=temp[i]-quantum;
            sum=sum+quantum;
        }
        if(temp[i]==0 && count==1)
        {
            y--;
            cout<<"\n Process No["<<i+1<<"] \t\t "<<bt[i]<<" \t\t\t "<<sum-at[i]<<" \t\t\t "<<sum-at[i]-bt[i];
            wt=wt+sum-at[i]-bt[i];
            tat=tat+sum-at[i];
            count=0;
        }
        if(i==NOP-1)
        {
            i=0;
        }
        else if(at[i+1]<=sum)
        {
            i++;
        }
        else
        {
            i=0;
        }
    }
    avg_wt=wt * 1.0/NOP;
    avg_tat=tat * 1.0/NOP;
    cout<<endl<<"\nAverage Waiting Time: \t"<<avg_wt;
    cout<<endl<<"\nAverage Turn Around Time: \t"<<avg_tat;
    getch();
    
    return 0;
    
}
