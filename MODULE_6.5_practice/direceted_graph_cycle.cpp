//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool vis[100005];
    vector<int> adj[100005];
    bool pathVisit[100005];
    bool ans;
    void dfs(int src){
        vis[src] = true;
        pathVisit[src] = true;
        for(int child:adj[src]){
            if(pathVisit[child]){
                ans = true;
            }
            if(!vis[child]){
                dfs(child);
            }
        }
        pathVisit[src] = false;
    }
    bool isCyclic(int V, vector<int> ad[]) {
        // code here
        for(int i = 0; i < V; i++) {
            adj[i] = ad[i];
        }
        memset(vis,false,sizeof(vis));
        memset(pathVisit,false,sizeof(pathVisit));
        ans = false;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        return ans;
    }
};