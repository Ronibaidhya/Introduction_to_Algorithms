#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    bool vis[55][55];
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void bfs(int si, int sj, vector<vector<int>> &image, int color)
    {
        queue<pair<int, int>> q;
        q.push({si, sj});
        vis[si][sj] = true;
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            int f = p.first;
            int s = p.second;
            q.pop();

            int x = image[f][s];
            image[f][s] = color;
            for (int i = 0; i < 4; i++)
            {
                int ci = f + d[i].first;
                int cj = s + d[i].second;
                if (valid(ci, cj) && !vis[ci][cj] && image[ci][cj] == x)
                {
                    q.push({ci, cj});
                    vis[ci][cj] = true;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        n = image.size();
        m = image[0].size();
        bfs(sr, sc, image, color);
        return image;
    }
};
int main()
{

    return 0;
}