// https://lightoj.com/problem/guilty-prince
#include <bits/stdc++.h>
using namespace std;

char a[25][25];
bool vis[25][25];
int dis[25][25];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m ||a[i][j] =='#')
    {
        return false;
    }
    else
    {
        return true;
    }
}
int cnt;
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
        cnt++;
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
    int t;
    cin >> t;
    int cs = 1 ;
    while (t--)
    {
        int si,sj;
        cin >> m >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if(a[i][j]=='@'){
                    si=i;
                    sj = j;
                }
            }
        }
        cnt = 0;
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si,sj);
        cout<<"Case "<<cs++<<": "<<cnt<<endl;
    }
    return 0;
}