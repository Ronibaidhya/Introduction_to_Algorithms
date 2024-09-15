//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool vis[100005];
    vector<int> adj[100005];
    int parent[100005];
    bool ans;
    void dfs(int src){
        vis[src] = true;
        for(int child:adj[src]){
            if(vis[child] && parent[src]!=child){
                ans = true;
            }
            if(!vis[child]){
                parent[child] = src;
                dfs(child);
            }
        }
    }
    bool isCycle(int V, vector<int> ad[]) {
        for(int i = 0; i < V; i++) {
            adj[i] = ad[i];
        }
        memset(vis,false,sizeof(vis));
        memset(parent,-1,sizeof(parent));
        ans = false;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        return ans;
    }
};
