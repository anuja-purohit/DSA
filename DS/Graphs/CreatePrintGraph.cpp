//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<int> ans[V];
        int M=edges.size();
        for(int i=0;i<M;i++)
        {
            int u = edges[i].first;
            int v = edges[i].second;
            
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        
        vector<vector<int>> adj(V);
        for(int i=0;i<V;i++)
        {
            
            for(int j=0;j<ans[i].size();j++)
            {
                adj[i].push_back(ans[i][j]);
            }
        }return adj;
    } 
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends