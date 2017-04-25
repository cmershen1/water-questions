#include <bits/stdc++.h>
using namespace std;
int n,m;
int w[1000],v[1000];
int dp[1000];
int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>w[i];
    }
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++) {
        for(int j=w[i];j<=m;j++) {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[m]<<endl;
}
