#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){

    vector<int> adj[8] = {      {},
                                {2},
                                {1,3,7},
                                {2,5},
                                {6},
                                {3,7},
                                {4},
                                {2,5}
                        };
    vector<int> bfs;
    vector<int> vis(8,0);
    for(int i = 1 ; i < 8 ; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);
                    
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
        }

    }

    for(auto j : bfs){
        
        cout<<j<<" ";
    }






    return 0;
}