#include <bits/stdc++.h>
using namespace std;
#define INFINITY 0x3f3f3f3f
int min(int a,int b,int c) {
  int m=(a<b)?a:b;
  m=(m<c)?m:c ;
  return m ;
}
int main() {
  int a[111];
  int dp[111][3];
  int n;

  memset(a,0,sizeof(a));
  memset(dp,0x3f,sizeof(dp));
  dp[0][0]=0;
  scanf("%d", &n);
  for(int i=1;i<=n;i++)
    scanf("%d", &a[i]);
  for(int i=1;i<=n;i++) {
    dp[i][0]=min(dp[i-1][0],dp[i-1][1],dp[i-1][2])+1;
    if(a[i]==2||a[i]==3)
      dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
    if(a[i]==1||a[i]==3)
      dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
  }

  printf("%d\n", min(dp[n][0],dp[n][1],dp[n][2]));
  return 0;
}
