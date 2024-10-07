    #include<bits/stdc++.h>
    #define ll long long int
    using namespace std;
    int weight[30];
    int value[30];
    int dp[200][200];
    int knapsack(int n,int W){
        if(n<0 || W==0) return 0;
        if(dp[n][W]!=-1) return dp[n][W];
        if(weight[n]<=W){
            int op1 = knapsack(n-1,W-weight[n]) + value[n];
            int op2 = knapsack(n-1,W);
            return dp[n][W] = max(op1,op2);
        }
        else{
            return dp[n][W] = knapsack(n-1,W);
        }
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        int n,W;
        cin>>n>>W;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            cin>>weight[i]>>value[i];
        }
        cout<<knapsack(n-1,W);
        return 0;
    }