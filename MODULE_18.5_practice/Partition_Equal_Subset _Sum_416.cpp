//https://leetcode.com/problems/partition-equal-subset-sum/description/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int dp[205][20005];
    bool subset_sum(vector<int> arr, int n, int sum) {
        if (n == 0) {
            if (sum == 0)
                return true;
            else
                return false;
        }
        if (dp[n][sum] != -1) {
            return dp[n][sum];
        }
        if (arr[n - 1] <= sum) {
            return dp[n][sum] = subset_sum(arr, n - 1, sum - arr[n - 1]) ||
                                subset_sum(arr, n - 1, sum);
        } else {
            return dp[n][sum] = subset_sum(arr, n - 1, sum);
        }
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        int sum = 0;
        for (int x : nums) {
            sum += x;
        }
        if (sum % 2 == 0) {
            int s = sum / 2;
            return subset_sum(nums,n,s);
        }
        else{
            return false;
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    return 0;
}