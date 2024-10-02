// https://school.outsbook.com/problems/problemdetails/10106
#include <bits/stdc++.h>
using namespace std;

char a[20][20];
bool vis[20][20];
int dis[20][20];
vector<pair<int, int> > d;
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == 'T')
    {
        return false;
    }
    else
    {
        return true;
    }
}

void bfs(int si, int sj)
{
    queue<pair<int, int> > q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int f = p.first;
        int s = p.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = f + d[i].first;
            int cj = s + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[f][s] + 1;
            }
        }
    }
}

int main()
{
    d.push_back({0,1});
    d.push_back({0,-1});
    d.push_back({1,0});
    d.push_back({-1,0});
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
    }
    m = n;
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    int di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 'S')
            {
                bfs(i, j);
            }
            if (a[i][j] == 'E')
            {
                di = i;
                dj = j;
            }
        }
    }
    cout << dis[di][dj] << endl;
    return 0;
}