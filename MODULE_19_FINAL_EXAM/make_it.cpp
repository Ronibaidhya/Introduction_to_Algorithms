#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5;


int dp[N];
int n;

bool make(int x){
    if(x>n) return false;
    if(x==n) return true;
    if(dp[x]!=-1) return dp[x];
    bool op1 = make(x+3);
    bool op2 = make(x*2);
    return dp[x] = op1 || op2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        bool flag = make(1);
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}