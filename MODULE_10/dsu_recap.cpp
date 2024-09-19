#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+5;
int par[N];

void dsu_initialize(int n){
    for(int i=0;i<n;i++){
        par[i] = -1;
    }
    par[1] = 3;
    par[2] = 1;
}

//O(n)
// int find(int node){
//     if(par[node]==-1){
//         return node;
//     }
//     return find(par[node]);
// }
int find(int node){
    if(par[node]==-1){
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    dsu_initialize(4);
    cout<<find(0)<<endl;
    cout<<find(1)<<endl;
    cout<<find(2)<<endl;
    cout<<find(3)<<endl;
    return 0;
}