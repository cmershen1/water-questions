#include <bits/stdc++.h>
using namespace std;
vector<int> v[6005];
int r[6005];//convivality rating
int dp[6005][2]; //adjacent list of tree
void dfs(int i) { // depth-first search of node i
  if(v[i].size()==0) {
    dp[i][0]=0;
    dp[i][1]=r[i];
    return;
  }

  for(int j=0;j<v[i].size();j++) {
    int c=v[i][j];
	  dfs(c);
    dp[i][0]+=max(dp[c][0],dp[c][1]);
    dp[i][1]+=dp[c][0];
  }
  dp[i][1]+=r[i];//如果i节点去了，那它的权值肯定要加上啊。这一行忘了，一直wa卡了好久…………蠢哭
//  cout<<"dp["<<i<<"]="<<dp[i][0]<<","<<dp[i][1]<<endl;
}
int main() {
  int parent[6005];
  int n,l,k,ans=0;

  memset(dp,0,sizeof(dp));
  memset(parent,0,sizeof(parent));
  scanf("%d", &n);
  for(int i=1;i<=n;i++)
    scanf("%d", &r[i]);
  while(scanf("%d %d",&l,&k)) {
    if(l==0&&k==0)
      break;
    parent[l]=k;
    v[k].push_back(l);
  }
  for(int i=1;i<=n;i++) {
    if(!parent[i]) {
      dfs(i);
      ans+=max(dp[i][0],dp[i][1]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
