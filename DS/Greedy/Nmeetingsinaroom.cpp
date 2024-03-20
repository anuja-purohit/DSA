#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    bool cmp(pair<int,int> a, pair<int,int> b)
    {
        return a.second<b.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
       vector<pair<int,int>> meeting;
       for(int i=0;i<n;i++)
       {
           pair<int,int> activity= make_pair(start[i],end[i]);
           meeting.push_back(activity); 
       }
       
       sort(meeting.begin(),meeting.end(),cmp);
       int count=1;
       int ansend=meeting[0].second;
       for(int i=0;i<n;i++)
       {
           if(meeting[i].first>ansend)
           {
               count++;
               ansend=meeting[i].second;
           }
       } return count;
    }
};

int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
