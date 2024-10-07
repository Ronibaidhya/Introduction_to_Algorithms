// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/X
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n, m;
int mat[15][15];

int mx(int i, int j)
{
    if (i == n || j == m)
        return INT_MIN;
    if (i == n - 1 && j == m - 1)
        return mat[i][j];
    int op1 = mx(i + 1, j);
    int op2 = mx(i, j + 1);
    return max(op1, op2) + mat[i][j];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << mx(0, 0);
    return 0;
}