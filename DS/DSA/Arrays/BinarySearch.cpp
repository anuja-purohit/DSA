#include<iostream>
using namespace std;

int binarySearch(int arr[], int size,int key)
{
    int start=0;
    int end=size-1;
    int mid= start +(end-start)/2;

    while(start<=end)
    {
        if(arr[mid]==key)
        {
            return mid;
        }

        if(key>arr[mid])//go right
        {
            start=mid+1;
        }
        else //go left
        {
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
int main()
{
    int even[5]={1,2,3,4,5};
    int odd[6]={6,7,8,9,10};
    
    int evenIndex= binarySearch(even,5,1);
    int oddIndex= binarySearch(odd,5,10);
    cout<<"The index of key is "<<evenIndex<< " in even Array"<<endl;
    cout<<"The index of key is "<<oddIndex<< " in odd Array"<<endl;
}