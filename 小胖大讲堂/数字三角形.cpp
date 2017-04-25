#include <bits/stdc++.h>
using namespace std;
int a[111][111];
int dp[111];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cin>>a[i][j];
        }
    }
    dp[1] = a[1][1];
    for(int i=2;i<=n;i++) {
        for(int j=n;j>=1;j--) {
            dp[j] = max(dp[j],dp[j-1])+a[i][j];
        }
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
}
