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
    bfs(1);
    if(vis[n]==false){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    int x =n;
    while(1){
        if(x==-1){
            break;
        }
        ans.push_back(x);
        x = par[x]; 
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}