#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j]=='#')
    {
        return false;
    }
    else
    {
        return true;
    }
}
int cnt = 0;
void dfs(int si, int sj)
{
    cnt++;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj])
        {
            dfs(ci, cj);
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
    memset(vis, false, sizeof(vis));
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='.' && !vis[i][j]){
                cnt = 0;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.size()==0){
        cout<<0;
    }
    else{
        for(int x:ans){
            cout<<x<<" ";
        }
    }
    return 0;
}