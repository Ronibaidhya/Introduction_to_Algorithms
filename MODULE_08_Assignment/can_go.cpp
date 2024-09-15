#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1005;
const ll INF = 1e18+5;
vector<pair<int,ll >> v[N];
ll dis[N];

class cmp{
    public:
        bool operator()(pair<int,ll> a, pair<int,ll> b){
            return a.second>b.second;
        }

};

void dijkstra(int src){
    priority_queue<pair<int,ll>,vector<pair<int,ll>>,cmp> pq;
    pq.push({src,0});
    dis[src] = 0;
    
    while(!pq.empty()){
        pair<int,ll> parent = pq.top();
        int node = parent.first;
        ll cost = parent.second;
        pq.pop();
        
        for(pair<int,ll> child : v[node]){
            int childNode = child.first;
            ll childCost = child.second;
            
            if(cost+childCost < dis[childNode]){
                //path relax
                dis[childNode] = cost+childCost;
                pq.push({childNode,dis[childNode]});
            }
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    for(int i=1;i<=n;i++){
        dis[i] = INF;
    }
    int src;
    cin>>src;
    dijkstra(src);
    int t;
    cin>>t;
    while(t--){
        ll d,dw;
        cin>>d>>dw;
        if(dis[d]<=dw){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
