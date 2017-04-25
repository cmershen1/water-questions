#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000],b[1000];
int dp[1000][1000];
int main(){
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    for(int i=1;i<=m;i++) {
        cin >> b[i];
    }

    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;
}
