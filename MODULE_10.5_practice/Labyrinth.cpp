//https://cses.fi/problemset/task/1193
#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
bool vis[1005][1005];
int dis[1005][1005];
pair<int,int> par[1005][1005];
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
string s;
void find(int ci ,int cj ,int bi,int bj){

    if(ci==bi && cj+1==bj){
        s.push_back('L');
    }
    else if(ci==bi && cj-1==bj){
        s.push_back('R');
    }
    else if(ci-1==bi && cj==bj){
        s.push_back('D');
    }
    else if(ci+1==bi && cj==bj){
        s.push_back('U');
    }
}

//code of find function
//     if(vis[ci][cj+1]==true){
//         s.push_back('L');
//     }
//     else if(vis[ci][cj-1]){
//         s.push_back('R');
//     }
//     else if(vis[ci-1][cj]){
//         s.push_back('D');
//     }
//     else if(vis[ci+1][cj]){
//         s.push_back('U');
//     }

//tried to use dfs
// bool flag = true;
// void dfs(int si, int sj)
// {
//     // cout<<si<<" "<<sj<<endl;
//     vis[si][sj] = true;
//     if(flag){
//         find(si,sj);
//     }
//     if(a[si][sj]=='B'){
//         flag = false;
//     }
//     for (int i = 0; i < 4; i++)
//     {
//         int ci = si + d[i].first;
//         int cj = sj + d[i].second;
//         if (valid(ci, cj) && !vis[ci][cj] )
//         {
//             dfs(ci, cj);
//         }
//     }
// }


void bfs(int si, int sj)
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
        for (int i = 0; i < 4; i++)
        {
            int ci = f + d[i].first;
            int cj = s + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[f][s]+1;
                par[ci][cj] = {f,s};
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
    memset(vis, false, sizeof(vis));
    memset(par,-1,sizeof(par));
    int di,dj;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='A' && !vis[i][j]){
                bfs(i,j);
            }
            else if(a[i][j]=='B'){
                di = i;
                dj = j;
            }
        }
    }
    int ci,cj,bi,bj;
    ci = di;
    cj = dj;
    while(1){
        bi = par[ci][cj].first;
        bj = par[ci][cj].second;
        if(bi==-1){
            break;
        }
        find(ci,cj,bi,bj);
        ci = bi;
        cj = bj;
    }
    if(vis[di][dj]){
        cout<<"YES"<<endl;
        reverse(s.begin(),s.end());
        cout<<s.size()<<endl;
        cout<<s<<endl;
    }
    else{
        cout<<"NO";
    }
    return 0;
}