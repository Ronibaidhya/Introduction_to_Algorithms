// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e3+5;
// vector<int> v[N];
// bool vis[N];

// vector<int> ans;
// void dfs(int src){
//     ans.push_back(src);
//     vis[src] = true;
//     for(int child:v[src]){
//         if(!vis[child]){
//             dfs(child);
//         }
//     }
// }
// int main(){
//     int n,e;
//     cin>>n>>e;
//     while(e--){
//         int a,b;
//         cin>>a>>b;
//         v[a].push_back(b);
//         v[b].push_back(a);
//     }
//     int q;
//     cin>>q;
//     while(q--){
//         ans.clear();
//         int x;
//         cin>>x;
//         memset(vis,false,sizeof(vis));
//         dfs(x);
//         if(ans.size()==1){
//             cout<<-1<<endl;
//         }
//         else{
//             sort(ans.begin(),ans.end(),greater<int>());
//             for(int y:ans){
//                 cout<<y<<" ";
//             }
//             cout<<endl;
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> v[N];
bool vis[N];
int level[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int child : v[p])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[p] + 1;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(x);
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            if (level[i] == 1)
            {
                pq.push(i);
            }
        }
        if (pq.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            while (!pq.empty())
            {
                cout << pq.top() << " ";
                pq.pop();
            }
            cout<<endl;
        }
    }
    return 0;
}