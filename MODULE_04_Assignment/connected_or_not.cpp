#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    int mat[n][n];
    memset(mat,0,sizeof(mat)); //initialize with 0
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        mat[a][b] = 1;
    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(mat[a][b]==1 ){
            cout<<"YES\n";
        }
        else if(a==b){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}
