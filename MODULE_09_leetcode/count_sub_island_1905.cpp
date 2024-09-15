#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    bool flag;
    bool vis[505][505];
    int n,m;
    vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    bool valid(int ci,int cj){
        if(ci>=0 && ci<n && cj>=0 && cj<m){
            return true;
        }
        else return false;
    }

    void dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2 ){
        vis[i][j] = true;
        if(grid1[i][j] == 0){
            flag = false;
        }
        for(pair<int,int> x: d){
            int ci = i+x.first;
            int cj = j+x.second;
            if(valid(ci,cj) && !vis[ci][cj] &&grid2[ci][cj] == 1){
                dfs(ci,cj,grid1,grid2);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        memset(vis,false,sizeof(vis));
        n = grid2.size();
        m = grid2[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid2[i][j] == 1){
                    flag = true;
                    dfs(i,j,grid1,grid2);
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};