//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    std::vector<int> parent;
    std::vector<int> rank;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int  i = 0 ; i < n+1 ; i++)
            parent[i] = i;
    }

    int findUparent(int u){
        if(parent[u] == u)
            return u;
        return parent[u] = findUparent(parent[u]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if(ulp_u == ulp_v) 
            return;
        if( rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
        else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int , pair<int,int>>> edges;
        for(int i = 0 ; i < V ; i ++){
            for(auto it: adj[i]){
                int wt = it[1];
                int adjnode = it[0];
                int node = i;
                edges.push_back({wt,{node,adjnode}});
            }
        }
        DisjointSet dis(V);
        sort(edges.begin(),edges.end());
        int mstSum = 0;
        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(dis.findUparent(u) != dis.findUparent(v)){
                mstSum+=wt;
                dis.unionByRank(u,v);
            }
        }
    return mstSum;
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