#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 105;
int dis[N];
class Edge{
    public:
        int u,v,c;
        Edge(int u,int v,int c){
            this->u = u;
            this->v = v;
            this->c = c;
        }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    vector<Edge> EdgeList;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        EdgeList.push_back(Edge(a,b,c));
    }

    dis[1] = 0;
    for(int i=2;i<=n;i++){
        dis[i] = 30000;
    }

    for(int i=1;i<=n-1;i++){
        for(Edge ed : EdgeList){
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if(dis[u]<30000 && dis[u]+c<dis[v]){
                dis[v] = dis[u]+c;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
    return 0;
}