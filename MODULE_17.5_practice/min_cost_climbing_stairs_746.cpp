// https://leetcode.com/problems/min-cost-climbing-stairs/description/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n;
int a[1010];
int dp[1010];
int mincost(int x)
{
    cout << x << " ";
    if (x >= n)
        return 0;
    if (dp[x] != -1)
        return dp[x];
    int op1 = mincost(x + 1) + a[x];
    int op2 = mincost(x + 2) + a[x];
    return dp[x] = min(op1, op2);
}

class Solution
{
public:
    int n;
    int dp[1010];
    int mincost(int x,vector<int> &cost)
    {
        if (x >= n)
            return 0;
        if (dp[x] != -1)
            return dp[x];
        int op1 = mincost(x + 1,cost) + cost[x];
        int op2 = mincost(x + 2,cost) + cost[x];
        return dp[x] = min(op1, op2);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        n = cost.size();
        memset(dp, -1, sizeof(dp));
        return min(mincost(0,cost),mincost(1,cost));
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << mincost(0) << endl;
    memset(dp, -1, sizeof(dp));
    cout << mincost(1);
    return 0;
}
