//https://codeforces.com/problemset/problem/20/C
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const ll N = 1e5+5;
vector<pair<ll,ll>> adj[N];
ll dis[N];
ll p[N];
bool vis[N];
class cmp{
    public:
        bool operator()(pair<ll,ll> a , pair<ll,ll> b){
            return a.second>b.second;
        }
};
void dijkstra(ll src){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,cmp> pq;
    pq.push({src,0});
    dis[src] = 0;

    while(!pq.empty()){
        pair<ll,ll> parent = pq.top();
        ll node = parent.first;
        ll cost = parent.second;
        pq.pop();
        vis[node] = true;

        for(pair<ll,ll> child : adj[node]){
            ll childNode = child.first;
            ll childCost = child.second;

            if(cost+childCost < dis[childNode]){
                dis[childNode] = cost+childCost;
                pq.push({childNode,dis[childNode]});
                p[childNode] = node;
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n,e;
    cin>>n>>e;
    while(e--){
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(ll i=1;i<=n;i++){
        dis[i] = 1e18;
    }
    dijkstra(1);
    if(vis[n]==false){
        cout<<-1;
        return 0;
    }
    ll current = n;
    vector<ll>path;

    while(true){
        path.push_back(current);
        if(current==1){
            break;
        }
        current = p[current];

    }
    reverse(path.begin(),path.end());

    for(auto child:path){
        cout<<child<<" ";
    }

    return 0;
}