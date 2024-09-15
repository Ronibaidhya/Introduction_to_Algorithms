#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    bool visit[105][105];
    int ans = 0;
    int n,m;

    vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,1}, {0,-1}};

    bool valid(int i,int j){
        if(i>=0 && i<n && j>=0 && j<m) return true;
        else return false;
    }

    void dfs(int i,int j,vector<vector<int>>& grid){
        visit[i][j] = true;
        ans++;
        for(pair<int,int> x : d){
            int ci = i+x.first;
            int cj = j+x.second;
            if(valid(ci,cj) && !visit[ci][cj] && grid[ci][cj]==1){
                dfs(ci,cj,grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(visit,false,sizeof(visit));
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visit[i][j] && grid[i][j]==1){
                    ans = 0;
                    dfs(i,j,grid);
                    mx = max(ans,mx);
                }
            }
        }
        return mx;
    }
};