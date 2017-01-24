#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f
ll dp[105][105][105];
int c[105];
int p[105][105];
int main() {

    memset(dp,0x3f,sizeof(dp));
    int n,m,b;
    scanf("%d %d %d",&n,&m,&b);
    for(int i=1;i<=n;i++) {
        scanf("%d",&c[i]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            scanf("%d",&p[i][j]);
        }
    }
    if(c[1]==0)  {//第1棵树没涂颜色，则美观度为1，代价为p[1][i]
        for(int i=1;i<=m;i++)
            dp[1][1][i]=p[1][i];
    }
    else //涂了颜色i，那就只需初始化第i棵树的颜色
        dp[1][1][c[1]]=0;

    for(int i=2;i<=n;i++) {
        for(int j=1;j<=b;j++) {
            for(int k=1;k<=m;k++) {
                if(c[i]!=0) {
                    if(c[i]==k) {
                        dp[i][j][k]=dp[i-1][j][k];
                        for(int s=1;s<=m;s++)
                            if(s!=k)
                                dp[i][j][k]=min(dp[i][j][k],dp[i-1][j-1][s]);
                    }
                    else
                        dp[i][j][k]=INF64;
                }
                else {
                    ll temp=dp[i-1][j][k];
                    for(int s=1;s<=m;s++)
                        if(s!=k)
                            temp=min(temp,dp[i-1][j-1][s]);
                    dp[i][j][k]=temp+p[i][k];
                }
            }
        }
    }

    ll ans=INF64;
    for(int i=1;i<=m;i++)
        ans=min(ans,dp[n][b][i]);
    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=b;j++)
    //         for(int k=1;k<=m;k++)
    //             cout<<"dp["<<i<<"]["<<j<<"]["<<k<<"] = "<<dp[i][j][k]<<endl;
    if(ans>=INF64)
        printf("-1\n");
    else
        printf("%I64d\n", ans);
}
