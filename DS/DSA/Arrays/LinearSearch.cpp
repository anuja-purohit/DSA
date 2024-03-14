#include<iostream>
using namespace std;

bool LinearSeach(int arr[], int size, int key)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i]==key)
        {
            return 1;
        }
    }

    return 0;

}

int main()
{
    int arr[10]={1,2,3,4,5,8,4,9,11,12};
    cout<<"Enter the element to be searched for: "<<endl;
    int key;
    cin>>key;

    bool found = LinearSeach(arr,10,key);
    
    if(found) {
        cout<<"Key is present "<<endl;
    }
    else{
        cout<<"Key is absent"<<endl;
    }

    return 0;
}