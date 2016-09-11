#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000005];
int main() {
  int n,x,y;
  memset(dp,0,sizeof(dp));

  scanf("%d %d %d", &n,&x,&y);
  dp[0]=0;
  for(int i=1;i<=n;i++) {
    if(i&1)
      dp[i]=min(dp[i-1]+x,min(dp[i>>1]+y+x,dp[(i>>1)+1]+y+x));
    else
      dp[i]=min(dp[i-1]+x,dp[i>>1]+y);
  }
  printf("%I64d\n", dp[n]);

}
