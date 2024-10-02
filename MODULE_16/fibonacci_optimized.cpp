#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5;

ll dp[N];

ll fib(ll n){
    if(n==0 || n==1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    ll ans = fib(n-1) + fib(n-2);
    dp[n] = ans;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;
    cout<<fib(n);
    return 0;
}