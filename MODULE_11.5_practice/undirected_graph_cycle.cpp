// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    int par[100005];
    int group_size[100005];
    int level[100005];
    bool flag;
    void dsu_initialize(int n)
    {
        for (int i = 0; i < n; i++)
        {
            par[i] = -1;
            group_size[i] = 1;
            level[i] = 0;
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
            flag = true;
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

    bool isCycle(int V, vector<int> adj[])
    {
        flag = false;
        dsu_initialize(V);
        // bool mat[V][V];
        // memset(mat,false,sizeof(mat));
        for(int i=0;i<V;i++){
            for(int x:adj[i]){
                // if(mat[i][x]==false &&mat[x][i]==false){
                //     dsu_union_by_size(i,x);
                //     mat[i][x] = true;
                //     mat[x][i] = true;
                // }
                if(i<x){
                    dsu_union_by_size(i,x);
                }
            }
        }
        return flag;
    }
};

int main()
{
}