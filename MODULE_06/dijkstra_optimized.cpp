
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<pair<int,int>> v[N];
int dis[N];

class cmp{
    public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            // if(a.second < b.second){
            //     return true;
            // }
            // return false;
            return a.second>b.second;
        }

};
//single source shortest path
void dijkstra(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    pq.push({src,0});
    dis[src] = 0;
    
    while(!pq.empty()){
        pair<int,int> parent = pq.top();
        int node = parent.first;
        int cost = parent.second;
        pq.pop();
        
        for(pair<int,int> child : v[node]){
            int childNode = child.first;
            int childCost = child.second;
            
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
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    // fill(dis,dis+n,INT_MAX);
    for(int i=0;i<n;i++){
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    for(int i=0;i<n;i++){
        cout<<i<<" -> "<<dis[i]<<endl;
    }
    
    return 0;
}
