#include<iostream>
#include<vector>
using namespace std;

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
            parent[u] = ulp_v;
            rank[ulp_v]++;
        }
        else if (rank[ulp_v] < rank[ulp_u]){
            parent[v] = ulp_u;
            rank[ulp_u]++;
        }
        else{
            parent[u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUparent(3) == ds.findUparent(7))
        std::cout<<"\nYes connected";
    else    
        std::cout<<"\nNot connected";

    ds.unionByRank(3,7);
    if(ds.findUparent(3) == ds.findUparent(7))
        std::cout<<"\nYes connected";
    else    
        std::cout<<"\nNot connected";


    return 0;
}