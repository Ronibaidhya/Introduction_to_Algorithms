#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 100005;
vector<int> v[N];
bool vis[N];
int par[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int child : v[p]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                par[child] = p;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(par,-1,sizeof(par));
    int cnt = 0;
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bfs(i);
            cnt++;
            v.push_back(i);
        }
    }
    cnt--;
    cout<<cnt<<endl;
    // for(int i=0;i<v.size();i++){
    //     if(i==v.size()-1){
    //         break;
    //     }
    //     cout<<v[i]<<" "<<v[i+1]<<endl;
    // }
    // for(int x:v){
    //     cout<<x<<" ";
    // }
    for(int i=0;i<v.size()-1;i++){
        cout<<v[i]<<" "<<v[i+1]<<endl;
    }
    return 0;
}