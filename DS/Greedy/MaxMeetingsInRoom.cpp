//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    static bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<2>(a) < get<2>(b);
    }

    vector<int> maxMeetings(int n,vector<int> start, vector<int> end) {
        vector<tuple<int, int, int>> meeting;
        vector<int> values;
        for(int i=0;i<n;i++)
        {
            values.push_back(i+1);
        }
        
        for (int i = 0; i < n; ++i) {
            tuple<int, int, int> activity = make_tuple(values[i],start[i],end[i]);
            meeting.push_back(activity);
        }

        sort(meeting.begin(), meeting.end(), cmp);
        
        vector<int> MeetingNo;
        if (n > 0) {
            MeetingNo.push_back(get<0>(meeting[0]));
            int lastEndTime = get<2>(meeting[0]);
            for (int i = 1; i < n; ++i) {
                if (get<1>(meeting[i]) > lastEndTime) {
                    MeetingNo.push_back(get<0>(meeting[i]));
                    lastEndTime = get<2>(meeting[i]);
                }
            }
        }
        std::sort(MeetingNo.begin(), MeetingNo.end());
        return MeetingNo;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends