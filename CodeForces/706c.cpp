#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int c[100005];
ll dp[100005][2];
string s[100005],rev[100005];
int main() {
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;i++)
    scanf("%d", &c[i]);
  for(int i=0;i<n;i++) {
    cin>>s[i];
    rev[i]=s[i];
    reverse(rev[i].begin(),rev[i].end());
  }

  memset(dp,-1,sizeof(dp));
  dp[0][0]=0;dp[0][1]=c[0];
  for(int i=1;i<n;i++) {
    if(s[i]>=s[i-1] && dp[i-1][0]!=-1)
      dp[i][0]=dp[i-1][0];
    if(s[i]>=rev[i-1] && dp[i-1][1]!=-1) {
      if(dp[i][0]!=-1)
        dp[i][0]=min(dp[i][0],dp[i-1][1]);
      else
        dp[i][0]=dp[i-1][1];
    }

    if(rev[i]>=s[i-1] && dp[i-1][0]!=-1)
      dp[i][1]=dp[i-1][0]+c[i];
    if(rev[i]>=rev[i-1] && dp[i-1][1]!=-1) {
      if(dp[i][1]!=-1)
        dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
      else
        dp[i][1]=dp[i-1][1]+c[i];
    }
  }

  for(int i=0;i<n;i++) {
    cout<<dp[i][0]<<','<<dp[i][1]<<endl;
  }
  if(dp[n-1][0]==-1 && dp[n-1][1]==-1)
    printf("-1\n");
  else if(dp[n-1][0]!=-1 && dp[n-1][1]!=-1)
    printf("%I64d\n", min(dp[n-1][0],dp[n-1][1]));
  else if(dp[n-1][0]==-1)
    printf("%I64d\n", dp[n-1][1]);
  else
    printf("%I64d\n", dp[n-1][0]);

}
