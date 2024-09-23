#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    vector<pair<int,int>> v[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]>0){
                v[i].push_back({j,mat[i][j]});
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<" -> ";
        for(pair<int,int> x : v[i]){
            cout<<x.first<<" "<<x.second<<" ";
        }

        cout<<endl;
    }
    return 0;
}