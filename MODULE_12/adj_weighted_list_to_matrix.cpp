#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void convert(int n,vector<pair<int,int>> adj[]){
    int mat[n][n];
    memset(mat,-1,sizeof(mat));
    for(int i=0;i<n;i++){
        for(pair<int,int> child : adj[i]){
            int j = child.first;
            int w = child.second;
            mat[i][j] = w;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> v[n];
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        // v[b].push_back({a,c});
    }
    convert(n,v);
    return 0;
}