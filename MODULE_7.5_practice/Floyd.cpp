#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll adj[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
            if(adj[i][j]==-1){
                adj[i][j] = INT_MAX;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(adj[i][k]+adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k]+adj[k][j];
                }
            }
        }
    }
    ll mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(adj[i][j]==INT_MAX){
                continue;
            }
            mx = max(adj[i][j],mx);
        }
    }
    cout<<mx<<endl;
    return 0;
}