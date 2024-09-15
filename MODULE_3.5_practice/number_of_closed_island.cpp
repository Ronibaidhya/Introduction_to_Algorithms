#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> v;
    bool vis[105][105];

    vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int n, m;

    bool valid(int ci, int cj)
    {
        if (ci < 0 || ci >= n || cj < 0 || cj >= m || v[ci][cj] == 1)
        {
            return false;
        }
        return true;
    }

    bool corner(int ci,int cj){
        if(ci <= 0 || ci >= n - 1 || cj <= 0 || cj >= m - 1){
            return false;
        }
        return true;
    }

    bool a = false;
    void bfs(int si, int sj)
    {
        queue<pair<int, int>> q;
        q.push({si, sj});
        vis[si][sj] = true;
        while (!q.empty())
        {
            pair<int, int> x = q.front();
            int f = x.first;
            int s = x.second;
            q.pop();

            cout << f << " " << s << endl;

            for (int i = 0; i < 4; i++)
            {
                int ci = f + p[i].first;
                int cj = s + p[i].second;
                if (valid(ci, cj) && !vis[ci][cj])
                {
                    if(ci <= 0 || ci >= n - 1 || cj <= 0 || cj >= m - 1){
                        a = true;
                    }
                    q.push({ci, cj});
                    vis[ci][cj] = true;
                }
            }
        }
    }


    int closedIsland(vector<vector<int>> &grid)
    {
        v = grid;
        memset(vis, false, sizeof(vis));
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0 && !vis[i][j] && corner(i, j))
                {
                    a = false;
                    bfs(i, j);
                    if(!a){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}




// 1st 

// class Solution
// {
// public:
//     vector<vector<int>> v;
//     bool vis[105][105];
//     vector<pair<int, int>> p = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
//     int n, m;
//     bool valid(int ci, int cj)
//     {
//         if (ci <= 0 || ci >= n-1 || cj <= 0 || cj >= m-1 || v[ci][cj]== 1 )
//         {
//             return false;
//         }
//         return true;
//     }
//     void dfs(int si, int sj)
//     {
//         vis[si][sj] = true;

//         for (auto it : p)
//         {
//             int ci = si + it.first;
//             int cj = sj + it.second;
//             if (valid(ci, cj) && !vis[ci][cj])
//             {
//                 dfs(ci, cj);
//             }
//         }
//     }
//     int closedIsland(vector<vector<int>> &grid)
//     {
//         v = grid;
//         memset(vis,false,sizeof(vis));
//         n = grid.size();
//         m = grid[0].size();
//         int count = 0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==0 && !vis[i][j] && valid(i,j)){
//                     dfs(i,j);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };