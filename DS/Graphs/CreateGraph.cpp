#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
//we can use template to make a generic graph capable of storing a;; kinds of data
class graph{
    public:
    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v, bool direction)
    {
        //directed=0->undirected
        //direction=1->directed

        //create an edge from u to v
        adj[u].push_back(v);

        if(direction==0) // if it is an undirected graph edges get added to both the lists
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cout<<"Enter the number of nodes" <<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges" <<endl;
    cin>>m;

    graph g;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>> u >> v;
        //creating an undirected graph
        g.addEdge(u,v,0);
    }

    //printing th graph
    g.printAdjList();
}
