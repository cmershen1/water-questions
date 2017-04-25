#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int w[1000],v[1000];
int dp[1000];
int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++) {
        cin>>w[i];
    }
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    for(int i=0;i<n;i++) {
        for(int j=m;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }
    cout<<dp[m]<<endl;
}
