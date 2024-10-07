// https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/V
// #include <bits/stdc++.h>
// #define ll long long int
// using namespace std;

// // int dp[25][2000005];
// // bool subset(int a[], int n, int s)
// // {
// //     if (n == 0)
// //     {
// //         if (s == 0)
// //             return true;
// //         else
// //             return false;
// //     }
// //     if (dp[n][s] != -1)
// //         return dp[n][s];
// //     if (a[n - 1] <= s)
// //     {
// //         return dp[n][s] = subset(a, n - 1, s - a[n - 1]) || subset(a, n - 1, s);
// //     }
// //     else
// //     {
// //         return dp[n][s] = subset(a, n - 1, s);
// //     }
// // }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(NULL);
//     // memset(dp,-1,sizeof(dp));
//     int n, x;
//     cin >> n >> x;
//     int a[n];
//     ll sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         sum += a[i];
//     }
//     bool flag;
//     if (x > sum || (x + sum) % 2 != 0)
//     {
//         flag = false;
//     }
//     else
//     {
//         ll s = (x + sum) / 2;
//         if (s < 0)
//             flag = false;
//         else
//         {
//             bool dp[n + 1][s + 1];
//             dp[0][0] = true;
//             for (int i = 1; i <= s; i++)
//             {
//                 dp[0][i] = false;
//             }

//             for (int i = 1; i <= n; i++)
//             {
//                 for (int j = 0; j <= s; j++)
//                 {
//                     if (a[i - 1] <= j)
//                     {
//                         dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
//                     }
//                     else
//                     {
//                         dp[i][j] = dp[i - 1][j];
//                     }
//                 }
//             }
//             flag = dp[n][s];
//         }
//     }

//     if (flag)
//         cout << "YES";
//     else
//         cout << "NO";
//     return 0;
// }




#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll x;
bool knapsack(int a[],ll sum,int n){
    if(n==0){
        if(sum==x) return true;
        else return false;
    }
    bool op1 = knapsack(a,sum+a[n-1],n-1);
    bool op2 = knapsack(a,sum-a[n-1],n-1);
    return op1 || op2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(knapsack(a,0,n))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}