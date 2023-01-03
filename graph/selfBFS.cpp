#include<iostream>
#include<queue>
#include<vector>
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
    vector<int> vis(8, 0);
    vector<int> bfs;

    for(int i = 1 ; i < 8 ; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it: adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    for(auto element: bfs)
        cout<<" "<<element;

    return 0;
}