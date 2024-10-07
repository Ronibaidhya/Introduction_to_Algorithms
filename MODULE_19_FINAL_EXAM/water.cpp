#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }

        vector<int> a(v);
        sort(a.begin(),a.end(),greater<int>());
        int mx = a[0];
        int smx = a[1];

        for(int i=0;i<n;i++){
            if(v[i]==mx || v[i]==smx){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}