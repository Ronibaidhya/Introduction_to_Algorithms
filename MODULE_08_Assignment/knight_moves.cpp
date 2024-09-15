#include <bits/stdc++.h>
using namespace std;
bool vis[105][105];
int dis[105][105];
vector<pair<int, int>> d = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {-1, 2}, {1, 2}, {-1, -2}, {1, -2}};
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

        for (int i = 0; i < 8; i++)
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
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int si,sj,di,dj;
        cin>>si>>sj>>di>>dj;
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si,sj);
        cout<<dis[di][dj]<<"\n";
    }
    return 0;
}

