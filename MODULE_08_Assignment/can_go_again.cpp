#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1005;
const ll INF = 1e18+5;
ll dis[N];

class Edge{
    public:
    ll u,v,c;
    Edge(ll u,ll v, ll c){
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    vector<Edge> EdgeList;
    while(e--){
        ll u,v,c;
        cin>>u>>v>>c;
        EdgeList.push_back(Edge(u,v,c));
    }
    for(int i=1;i<=n;i++){
        dis[i] = INF;
    }
    int src;
    cin>>src;
    dis[src] = 0;
    for(int i=1;i<=n-1;i++){
        for(Edge ed : EdgeList){
            int u,v,c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if(dis[u]<INF && dis[u]+c<dis[v]){
                dis[v] = dis[u]+c;
            }
        }
    }
    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }
    int t;
    cin>>t;
    while(t--){
        int d;
        cin>>d;
        if(cycle){
            cout<<"Negative Cycle Detected";
            break;
        }
        else if(dis[d]==INF){
            cout<<"Not Possible\n";
        }
        else{
            cout<<dis[d]<<"\n";
        }
    }
    return 0;
}
