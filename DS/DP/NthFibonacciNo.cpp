#include<iostream>
#include<vector>
using namespace std;
//Top-Down Approach 
int fib(int n, vector<int> &dp)
{
    //base case
    if(n<=1)
    { return n;}

    if(dp[n]!=-1)
    {
        return dp[n];
    }
    else
    {
        dp[n]=fib(n-1,dp)+fib(n-2,dp);
        return dp[n];
    }
}
// int main()
// {
//     int n;
//     cout<<"Nth Fibonacci Number: "<<endl;
//     cin>>n;

//     vector<int> dp(n+1);
//     for(int i=0;i<=n;i++)
//     {
//         dp[i]=-1;
//     }//array intialised to -1
//     cout<< fib(n,dp)<<endl;
//     return 0;
// }


//Bottom Up Approach
// int main()
// {
//     int n;
//     cout<<"Nth Fibonacci Number: "<<endl;
//     cin>>n;
//     //step1
//     vector<int> dp(n+1);
//     //step2
//     dp[1]=1;
//     dp[0]=0;
//     //step3
//     for(int i=2; i<=n;i++)
//     {
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     cout<<dp[n];

// }

//Optimised Bottom Up
int main()
{
    int n;
    cout<<"Nth Fibonacci Number: ";
    cin>>n;
    //step1
    int prev1=1;
    int prev2=0;
    int curr;

    if(n==0)
    { return prev2;}

    for(int i=2;i<=n; i++)
    {
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<< curr;
}