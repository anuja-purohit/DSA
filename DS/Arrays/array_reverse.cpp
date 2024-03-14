
// Iterative C++ program to reverse an array
#include <bits/stdc++.h>
using namespace std;
void printarray(int arr[], int n)
{
    for(int i=0; i<n ; i++ )
    {
        cout<< arr[i] << " " ;
    }

    cout << endl;
}
void reversearray(int arr[], int n)
{
    for(int i=0; i< n/2 ; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}
int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    printarray(arr,n);
    cout<<"Reverse the array"<<endl;
    reversearray(arr,n);
    printarray(arr,n);

    return 0;
}