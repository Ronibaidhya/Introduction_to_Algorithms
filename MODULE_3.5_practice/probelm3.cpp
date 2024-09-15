#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
bool vis[N];
int c = 0;
void dfs(int src){
    // cout<<src<<endl;
    c++;
    vis[src] = true;
    for(int child:v[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
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
    memset(vis,false,sizeof(vis));
    vector<int> v;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            c = 0;
            dfs(i);
            v.push_back(c);
        }
    }
    sort(v.begin(),v.end());
    for(int x:v){
        cout<<x<<" ";
    }

    return 0;
}