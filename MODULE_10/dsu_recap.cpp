#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+5;
int par[N];

void dsu_initialize(int n){
    for(int i=0;i<n;i++){
        par[i] = -1;
    }
    par[1] = 2;
    par[2] = 3;
    par[5] = 6;
    par[6] = 7;
}

//O(n)
// int find(int node){
//     if(par[node]==-1){
//         return node;
//     }
//     return find(par[node]);
// }
int dsu_find(int node){
    if(par[node]==-1){
        return node;
    }
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader; 
}

void dsu_union(int node1, int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    par[leaderA] = leaderB;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    dsu_initialize(8);
    dsu_union(1,5);
    cout<<dsu_find(1)<<endl;
    return 0;
}
