#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int dp[1005][1005];
bool subset_sum(int arr[], int n, int sum)
{
    if (n == 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }
    if (dp[n][sum] != -1)
    {
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        int n,m;
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int s = 1000-m;

        if(s==0) cout<<"YES\n";
        else{
            if(subset_sum(a,n,s)){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}