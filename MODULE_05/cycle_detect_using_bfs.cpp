#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool vis[N];
vector<int> adj[N];
int parent[N];
bool ans;
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int child:adj[p]){
            if(vis[child] && parent[p]!=child){
                ans = true;
            }

            if(!vis[child]){
                vis[child] = true;
                parent[child] = p;
                q.push(child);
            }
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parent,-1,sizeof(parent));
    ans = false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(i);
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