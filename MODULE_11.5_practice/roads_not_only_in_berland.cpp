//https://codeforces.com/problemset/problem/25/D
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+5;
int par[N];
int group_size[N];
int level[N];
void dsu_initialize(int n){
    for(int i=1;i<=n;i++){
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}

int dsu_find(int node){
    if(par[node]==-1){
        return node;
    }
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader; 
}

void dsu_union_by_size(int node1, int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if(group_size[leaderA] > group_size[leaderB]){
        par[leaderB] = leaderA;
        group_size[leaderA]+=group_size[leaderB];
    }
    else{
        par[leaderA] = leaderB;
        group_size[leaderB]+=group_size[leaderA];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    int e = n-1;
    dsu_initialize(n);
    int day = 0;
    vector<pair<int,int>> v;
    while(e--){
        int a,b;
        cin>>a>>b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if(leaderA==leaderB){
            v.push_back({a,b});
            day++;
            continue;
        }
        dsu_union_by_size(a,b);
    }

    for(int i=1;i<=n;i++){
        // cout<<i<<"-> "<<par[i]<<endl;
        
    }
    cout<<day<<endl;
    for(auto it:v){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}
