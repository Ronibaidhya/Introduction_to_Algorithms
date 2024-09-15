////adjacency matrix 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    int mat[n][n];
    memset(mat,0,sizeof(mat));

    while(e--){
        int a,b;
        cin>>a>>b;
        mat[a][b] = 1;
        // mat[b][a] = 1; //if commmented then one directional
    }

    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" "; 
        }
        cout<<endl;
    }
    return 0;
}


// Adjacency List one directional
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n,e;
//     cin>>n>>e;
//     vector<int> mat[n];
//     while(e--){
//         int a,b;
//         cin>>a>>b;
//         mat[a].push_back(b);
//     }
//     for(int x:mat[1]){
//         cout<<x<<" ";
//     }
//     return 0;
// }