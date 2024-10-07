// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// BOTTOM UP
//  #include<bits/stdc++.h>
//  #define ll long long int
//  using namespace std;

// class Solution{
// public:
//     bool isSubsetSum(vector<int>arr, int sum){
//         int n = arr.size();
//         bool dp[n+1][sum+1];
//         dp[0][0] = true;
//         for(int i = 1;i<=sum;i++){
//             dp[0][i] = false;
//         }

//         for(int i=1;i<=n;i++){
//             for(int j=0;j<=sum;j++){
//                 if(arr[i-1]<=j){
//                     dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
//                 }
//                 else{
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
//         }
//         return dp[n][sum];
//     }
// };

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(NULL);

//     return 0;
// }

// TOP DOWN
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution
{
public:

    int dp[105][10005];
    bool subset_sum(vector<int> arr, int n, int sum)
    {
        if (n == 0)
        {
            if (sum == 0)
                return true;
            else
                return false;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if (arr[n - 1] <= sum)
        {
            return dp[n][sum] = subset_sum(arr, n - 1, sum - arr[n - 1]) || subset_sum(arr, n - 1, sum);
        }
        else
        {
            return dp[n][sum] = subset_sum(arr, n - 1, sum);
        }
    }
    bool isSubsetSum(vector<int> arr, int sum)
    {
        memset(dp,-1,sizeof(dp));
        int n = arr.size();
        return subset_sum(arr, n, sum);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    return 0;
}