//Predict the character
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ch ; 
    cout<<"Enter the character"<<endl;
    cin>> ch;
    int num = (int) ch;
    if(num>=97 && num<=122)
    {
        cout<<"character lies within a to z"<<endl;
    }
    else if(num>=65 && num<=90)
    {
        cout<<"character lies within A to Z"<<endl;
    }
    if(num>=48 && num<=57)
    {
        cout<<"character lies within 0 to 9"<<endl;
    }

}
