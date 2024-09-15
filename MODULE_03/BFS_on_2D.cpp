#include <bits/stdc++.h>
using namespace std;

char a[20][20];
bool vis[20][20];
int dis[20][20];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

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

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int f = p.first;
        int s = p.second;
        q.pop();

        cout << f << " " << s << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = f + d[i].first;
            int cj = s + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[f][s]+1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bfs(si, sj);
    cout<<dis[0][3];
    return 0;
}