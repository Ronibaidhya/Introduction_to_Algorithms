#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool vis[N];
vector<int> adj[N];
bool pathVisit[N];
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
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    memset(vis,false,sizeof(vis));
    memset(pathVisit,false,sizeof(pathVisit));
    ans = false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(ans){
        cout<<"Cycle found";
    }
    else{
        cout<<"Cycle not found";
    }
    return 0;
}