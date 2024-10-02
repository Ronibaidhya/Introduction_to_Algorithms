#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int x = fib(n-1);
    int y = fib(n-2);
    return x+y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}