#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
bool vis[N];
int level[N];
int parent[N];
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

// void shortest_path(int des){
//     if(des==-1) return;
//     shortest_path(parent[des]);
//     cout<<des<<" ";
// }
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src,des,k;
    cin>>src>>des>>k;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    bfs(src);
    // if(parent[des]==-1){
    //     cout<<"NO";
    //     return 0;
    // }
    // int x = des;
    // vector<int> path;
    // while(x!=-1){
    //     path.push_back(x);
    //     x =parent[x];
    // }
    // if(path.size()-1 <= k*2){
    //     cout<<"YES";
    // }
    // else{
    //     cout<<"NO";
    // }

    if(level[des]!=-1 && level[des] <= k*2){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}