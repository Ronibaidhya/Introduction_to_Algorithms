#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
char a[N][N];
bool vis[N][N];
int dis[N][N];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j]=='-')
    {
        return false;
    }
    else
    {
        return true;
    }
}

int area = 0;
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
        area++;
        for (int i = 0; i < 4; i++)
        {
            int ci = f + d[i].first;
            int cj = s + d[i].second;
            if (valid(ci, cj)==true && vis[ci][cj]==false)
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
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    bool flag = false;
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j] && a[i][j]=='.'){
                area = 0;
                bfs(i,j);
                flag = true;
                mn = min(mn,area);
            }
        }
    }
    if(flag){
        cout<<mn<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}

