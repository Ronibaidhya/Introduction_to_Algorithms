#include<bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];
int level[1005];
int parent[1005];
void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int child: v[p]){
            if(vis[child]==false){
                q.push(child);
                vis[child] = true;
                level[child] = level[p]+1;
                parent[child] = p;
            }
        }
    }
}

int shortest_path(int des){
    if(des==-1) return 0;
    int x = shortest_path(parent[des]);
    return x+1;
}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin>>q;
    while(q--){
        int src,des;
        cin>>src>>des;
        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));
        memset(parent,-1,sizeof(parent));
        bfs(src);
        if(src==des){
            cout<<0<<endl;
        }
        else if(parent[des]==-1){
            cout<<-1<<endl;
        }
        else{
            cout<<shortest_path(des)-1<<endl;
        }
    }
    return 0;
}