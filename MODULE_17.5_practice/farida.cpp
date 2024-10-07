//https://www.spoj.com/problems/FARIDA/en/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e4+5;
int n;
int a[N];
int dp[N];
ll cost(int x){
    if(x<0) return 0;
    if(dp[x]!=-1) return -1;
    int op1 = cost(x-2) + a[x];
    int op2 = cost(x-1);
    return dp[x] = max(op1,op2);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    int x = 1;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<"Case "<<x++<<": "<<cost(n-1)<<endl;
    }
    return 0;
}