#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] < arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 5, 1, 4, 2, 8};
	int N = sizeof(arr) / sizeof(arr[0]);
	int p = fork();
	
	if ( p > 0 ) {
		cout<<"-----------In Parent Process-----------\nParent Process: "<<getpid()<<endl;
		cout<<"Child Process: "<<p<<endl;
		cout << "Insertion Sort(Ascending Order): "<<endl;
		insertionSort(arr, N);
		printArray(arr, N);
	}
	else if ( p == 0 ) {
		cout<<endl<<"-----------In Child Process-----------\nChild Process: "<<getpid()<<endl;
		cout<<"Parent Process: "<<getppid()<<endl;
		cout<<"Selection Sort(Descending Order): "<<endl;
		bubbleSort(arr, N);
		printArray(arr, N);
	}
	return 0;
}
