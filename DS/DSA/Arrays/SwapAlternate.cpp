#include<iostream>
using namespace std;

void swapalternate(int arr[], int size)
{
    for(int i=0; i<size; i+=2)
    {
        if(i+1<size)
        {
            swap(arr[i],arr[i+1]);
        }
    }

}

void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
}

int main()
{
    int evenarr[6]={1,2,3,4,5,6};
    int oddarr[5]={1,2,3,4,5};
    cout<<"Original Arrays: "<<endl;
    printArray(evenarr,6);
    printArray(oddarr,5);
    swapalternate(evenarr,6);
    swapalternate(oddarr,5);
    cout<<"Alternate Swapped Arrays: "<<endl;
    printArray(evenarr,6);
    printArray(oddarr,5);
}