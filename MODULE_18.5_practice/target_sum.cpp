//https://leetcode.com/problems/target-sum/description/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    int dp[25][1005];
    int subset_sum(vector<int> arr, int n, int sum) {
        if (n == 0) {
            if (sum == 0)
                return 1;
            else
                return 0;
        }
        if (dp[n][sum] != -1) {
            return dp[n][sum];
        }
        if (arr[n - 1] <= sum) {
            return dp[n][sum] = subset_sum(arr, n - 1, sum - arr[n - 1]) + subset_sum(arr, n - 1, sum);
        } else {
            return dp[n][sum] = subset_sum(arr, n - 1, sum);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        int sum =0 ;
        for(int x:nums){
            sum+=x;
        }
        if((target+sum)%2!=0){
            return 0;
        }
        else{
            int s = (target+sum)/2;
            return subset_sum(nums,n,s);
        }
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    return 0;
}