#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                mat[i][j] = 1;
            }
            else{
                mat[i][j] = -1;
            }
        }
    }
    while(e--){
        int a,b;
        cin>>a>>b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}