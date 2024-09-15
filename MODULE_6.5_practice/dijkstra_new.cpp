#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<pair<int,int>> v[N];
int dis[N];
class cmp{
    public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second>b.second;
        }
};

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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,s,f;
    cin>>n>>s>>f;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }        
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!= -1 && mat[i][j]!= 0){
                v[i+1].push_back({j+1,mat[i][j]});
            }
        }
    }

    fill(dis,dis+105,INT_MAX);
    // for(int i=1;i<=n;i++){
    //     dis[i] = INT_MAX;
    // }
    dijkstra(s);
    // for(int i =0 ;i<11;i++){
    //     cout<<dis[i]<<endl;
    // }
    if(dis[f]==INT_MAX){
        cout<<-1<<endl;
    }
    else{
        cout<<dis[f]<<endl;
    }
}
