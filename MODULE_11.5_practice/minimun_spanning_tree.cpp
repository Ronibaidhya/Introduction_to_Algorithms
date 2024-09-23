// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
class Solution
{
public:
    int par[1005];
    int group_size[1005];

    void dsu_initialize(int n)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = -1;
            group_size[i] = 1;
        }
    }

    int dsu_find(int node)
    {
        if (par[node] == -1)
        {
            return node;
        }
        int leader = dsu_find(par[node]);
        par[node] = leader;
        return leader;
    }

    void dsu_union_by_size(int node1, int node2)
    {
        int leaderA = dsu_find(node1);
        int leaderB = dsu_find(node2);
        if (leaderA == leaderB)
        {
            return;
        }
        if (group_size[leaderA] > group_size[leaderB])
        {
            par[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        }
        else
        {
            par[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
    }
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        dsu_initialize(V);
        vector<Edge> edgeList;
        for (int i = 0; i < V; i++)
        {
            for (vector<int> x : adj[i])
            {
                int u = i;
                int v = x[0];
                int w = x[1];
                edgeList.push_back(Edge(u, v, w));
            }
        }
        sort(edgeList.begin(), edgeList.end(), cmp);
        int totalCost = 0;
        for (Edge ed : edgeList)
        {
            int leaderU = dsu_find(ed.u);
            int leaderV = dsu_find(ed.v);
            if (leaderU == leaderV)
                continue;
            else
            {
                dsu_union_by_size(ed.u, ed.v);
                totalCost += ed.w;
            }
        }
        return totalCost;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    return 0;
}