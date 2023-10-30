//Page_Replacement using First In First Serve
#include <iostream>

using namespace std;

void display(int arr[], int n, int no) {
    cout<<endl<<"Page "<<no<<endl;
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<endl;
    }
    cout<<endl;
}

int bs(int arr[], int n) {
    
    for(int i=0; i<n; i++) {
        if(arr[i] == -1) {
            return i;
        }
    }
    return -1;
}

bool search(int arr[], int n, int key) {
    
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, ref, r=0, fault=0;
    cout<<"Enter number of page frames: ";
    cin>>n;
    if (n < 3) {
        cout<<"Minimum 3 page frames are required.";
        return 0;
    }
    cout<<"Enter number of reference: ";
    cin>>ref;
    
    int page_num[n], reference[ref];
    
    for(int i=0; i<n; i++) {
        page_num[i] = -1;
    }
    
    for(int i=0; i<ref; i++) {
        cout<<"Input "<<i+1<<": ";
        cin>>reference[i];
    }
    
    for(int i=0; i<ref; i++) {
        if(!search(page_num, n, reference[i])) {
            int key = bs(page_num, n);
            if(key != -1) {
                page_num[key] = reference[i];
                display(page_num, n, i);
                continue;
            }
            r = r % n;
            page_num[r] = reference[i];
            r++;
            fault++;
        }
        display(page_num, n, i);
    }
    
    cout<<"Number of Faults: "<<fault<<endl;
    cout<<"Fault Ratio: "<<fault<<"/"<<ref<<endl;
    cout<<"Hit Ratio: "<<ref-fault<<"/"<<ref<<endl;

    return 0;
}
