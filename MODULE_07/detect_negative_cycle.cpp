#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const int N = 1e5 + 5;
int dis[N];
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        // Edge obj(u,v,c);
        // EdgeList.push_back(obj);
        EdgeList.push_back(Edge(u, v, c));
        // EdgeList.push_back(Edge(v, u, c)); // undirected
    }
    dis[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "Cycle found";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << dis[i] << " ";
        }
    }
    return 0;
}