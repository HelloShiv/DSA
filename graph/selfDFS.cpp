#include<iostream>
#include<vector>
std::vector<int> adj[8] = {      {},
                                {2},
                                {1,3,7},
                                {2,5},
                                {6},
                                {3,7},
                                {4},
                                {2,5}
                        };
std::vector<int> vis(8,0);
std::vector<int> dfsStored;

void dfs(int node){
    dfsStored.push_back(node);
    vis[node] = 1;
    for(auto it: adj[node])
        if(!vis[it])
            dfs(it);
}

int main(){
    for(int i =1 ; i < 8 ;i++)
        if(!vis[i]){
            dfs(i);
        }

    for(auto j : dfsStored)
        std::cout<<j<<"  ";
    return 0;
}