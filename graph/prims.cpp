// used for calculation MST 
// Minimum spanning tree
//  uses priority queue min-hep ( weight , node , parent)
// and visited array i.e vector

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        int sum = 0 ;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            
            if(vis[node] == 1) continue;
            sum+=wt;
            vis[node] = 1;
            for(auto i: adj[node]){
                int nwt = i[1];
                int nNode = i[0];
                if(!vis[nNode])
                pq.push({nwt,nNode});
            }
        }
    
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends