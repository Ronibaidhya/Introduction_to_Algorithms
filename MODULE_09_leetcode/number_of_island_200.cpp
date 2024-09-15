#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    bool visit[305][305];
    int n,m;

    vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,1}, {0,-1}};

    bool valid(int i,int j){
        if(i>=0 && i<n && j>=0 && j<m) return true;
        else return false;
    }

    void dfs(int i,int j,vector<vector<char>>& grid){
        visit[i][j] = true;
        for(pair<int,int> x : d){
            int ci = i+x.first;
            int cj = j+x.second;
            if(valid(ci,cj) && !visit[ci][cj] && grid[ci][cj]=='1'){
                dfs(ci,cj,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(visit,false,sizeof(visit));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visit[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};