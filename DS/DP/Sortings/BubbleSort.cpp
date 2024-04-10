#include<iostream>
using namespace std;
int bubblesort(int arr[], int n)
{
    int swaps=0;
    for(int i=1; i<n;i++)
    {
        //flags incase of no swaps
        bool swapped=false;
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
                swaps++;
            }
        }
        if(swapped==false)
        {
            break;
        }
    }
    return swaps;
};
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << " " << arr[i];
};

// Driver program to test above functions
int main()
{
	int arr[] = { 8,22,7,9,31,5,13 };
	int N = sizeof(arr) / sizeof(arr[0]);
    cout<<"No of swaps:";
    cout<<bubblesort(arr, N);
	cout <<"\nSorted array: \n";
	printArray(arr, N);
    
	return 0;
}