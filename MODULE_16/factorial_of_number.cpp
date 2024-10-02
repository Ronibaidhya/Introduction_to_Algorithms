#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}