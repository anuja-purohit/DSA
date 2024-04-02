#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    
    public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies+N);
        int mini=0;
        int buy=0;
        int free=N-1;
        
        while(buy<=free)
        {
            mini=mini+candies[buy];
            buy++;
            free=free-K;
        }
        
        int maxi=0;
        buy=N-1;
        free=0;
        
        while(free<=buy)
        {
            maxi=maxi+candies[buy];
            buy--;
            free=free+K;
        }
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};
int main() {
    int N,K;
    cin>>N;
    cin>>K;
    int candies[N];
    for(int i=0;i<N;i++)
    {
        cin>>candies[i];
    }
    
    Solution ob;
    vector<int> result = ob.candyStore(candies,N,K);
    
    for(int candy : result) {
        cout << candy << " ";
    }
    return 0;
}