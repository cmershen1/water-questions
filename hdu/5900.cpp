#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int k[305],v[305];
ll dp[305][305];
ll sum[305];
bool vis[305][305];
int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}
void dfs(int i,int j) {
    if(vis[i][j])
        return;
    vis[i][j]=true;
    dfs(i+1,j-1);
    if(dp[i+1][j-1] == sum[j-1]-sum[i] && gcd(k[i],k[j])!=1)
        dp[i][j]=dp[i+1][j-1]+v[i]+v[j];
    else {
        for(int k=i;k<j;k++) {
            dfs(i,k);
            dfs(k+1,j);
            dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
}
int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        sum[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&k[i]);
        for(int i=1;i<=n;i++) {
            scanf("%d",&v[i]);
            sum[i]=sum[i-1]+v[i];
        }

        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            vis[i][i]=true;

        for(int i=1;i<n;i++) {
            vis[i][i+1]=true;
            if(gcd(k[i],k[i+1])==1)
                dp[i][i+1]=0;
            else
                dp[i][i+1]=v[i]+v[i+1];
        }
        dfs(1,n);
        //debug
        // for(int i=1;i<=n;i++)
        //     for(int j=1;j<=n;j++)
        //         printf("dp[%d][%d]=%I64d,vis=%d\n", i,j,dp[i][j],vis[i][j] );
        printf("%I64d\n", dp[1][n]);
    }
}
