#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
int dp[100005];
int n,m;
int main() {
    scanf("%d %d",&n,&m);
    memset(dp,0x3f,sizeof(dp));
    dp[n]=0;
    for(int i=n;i<=m;i++) {
        for(int j=2;j*j<=i;j++) {
            if(i%j==0) {
                dp[i+j]=min(dp[i+j],dp[i]+1);
                dp[i+i/j]=min(dp[i+i/j],dp[i]+1);
            }
        }
    }
    printf("%d\n", dp[m]);
}
