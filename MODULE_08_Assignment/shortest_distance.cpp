#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const long long int INF = 1e18+5;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, e;
    cin >> n >> e;
    ll adj[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adj[i][j] = 0;
            }
            else
            {
                adj[i][j] = INF;
            }
        }
    }
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        adj[a][b] = min(adj[a][b],c);
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(adj[i][k]+adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k]+adj[k][j];
                }
            }
        }
    }

    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        --x;
        --y;
        if(adj[x][y]==INF){
            cout<<-1<<"\n";
        }
        else{
            cout<<adj[x][y]<<"\n";
        }
    }
    return 0;
}