#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+5;
int par[N];
int group_size[N];
bool cycle;
void dsu_initialize(int n){
    for(int i=0;i<n;i++){
        par[i] = -1;
        group_size[i] = 1;
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


void dsu_union_by_size(int node1 , int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(leaderA==leaderB){
        cycle = true;
        return;
    }
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
    int n,e;
    cin>>n>>e;
    dsu_initialize(n);
    cycle = false;
    while(e--){
        int a,b;
        cin>>a>>b;
        dsu_union_by_size(a,b);
    }
    if(cycle){
        cout<<"cycle found";
    }
    else{
        cout<<"Cycle not found";
    }
    return 0;
}