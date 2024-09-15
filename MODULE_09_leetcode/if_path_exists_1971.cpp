#include<bits/stdc++.h>
#define ll long long int
using namespace std;

//bfs;
// class Solution {
// public:
//     bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
//         bool vis[200005];
//         memset(vis,false,sizeof(vis));
//         vector<int> v[n];
//         for(auto it: edges){
//             v[it[0]].push_back(it[1]);
//             v[it[1]].push_back(it[0]);
//         }
//         queue<int> q;
//         q.push(src);
//         vis[src] = true;

//         while (!q.empty()) {
//             int p = q.front();
//             q.pop();
//             for (int child : v[p]) {
//                 if (vis[child] == false) {
//                     q.push(child);
//                     vis[child] = true;
//                 }
//             }
//         }
//         return vis[des];
//     }
// };


//dfs
class Solution {
public:
    bool vis[200005];
    vector<int> v[200005];
    void dfs(int src){
        vis[src] = true;
        for(int child : v[src]){
            if(!vis[child]){
                dfs(child);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
        memset(vis,false,sizeof(vis));
        for(auto it: edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        return vis[des];
    }
};
