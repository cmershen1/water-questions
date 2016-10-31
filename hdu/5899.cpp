#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
int t,n,m,k,a,b,l;
int cnt;//记录其中一种颜色点的数目
int p[510];//记录每个点的颜色,0没染，1黑色，2白色
int dis[510][510];//因为要算距离，所以用邻接矩阵存图
vector<int> g[510];

void floyd() {
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
void initGraph() {
  //构造图g，当i-j边距离小于等于k的时候，给i-j加一条边
  for(int i=1;i<=n;i++) {
    for(int j=i+1;j<=n;j++) {
      if(dis[i][j]<=k) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  // for(int i=1;i<=n;i++) {
  //   cout<<i<<":"<<endl;
  //   for(int j=0;j<g[i].size();j++) {
  //     int v=g[i][j];
  //     cout<<v<<","<<"dis="<<dis[i][v]<<endl;
  //   }
  // }
}
bool dfs(int u,int col) { //给i点染col色
  for(int i=0;i<g[u].size();i++) {
    int v=g[u][i];
    if(p[v]==col)//如果相邻的两个点颜色一样，那就是非法的
      return false;
    else if(p[v]==0) {
      if(col==1) {
        p[v]=2;cnt++;
        dfs(v,2);
      }
      else {
        p[v]=1;
        dfs(v,1);
      }
    }
  }
  return true;
}
bool paint() {
  for(int i=1;i<=n;i++) {
    if(p[i]==0) {
      p[i]=1;
      if(!dfs(i,1))
        return false;
    }
  }
  return true;
}

void solve() {
  cnt=0;
  if(!paint() || cnt!=n/2)
    printf("Impossible\n");
  else {
    int color = p[1];//要输出字典序小的，就看1是什么颜色，输出跟他同色的
    vector<int> ans;
    for(int i=1;i<=n;i++)
      if(p[i]==color)
        ans.push_back(i);
    printf("%d\n", ans.size());
    for(int i=0;i<ans.size()-1;i++)
      printf("%d ", ans[i]);
    printf("%d\n", ans.back());
  }
}
int main() {
  scanf("%d",&t);
  while(t--) {
    scanf("%d %d %d",&n,&m,&k);

    memset(dis,0x3f,sizeof(dis));
    memset(p,0,sizeof(p));
    memset(g,0,sizeof(g));
    while(m--) {
      scanf("%d %d %d",&a,&b,&l);
      dis[a][b]=l;dis[b][a]=l;
    }
    if(n==0) { //特判0个点或者1个点
      printf("0\n");
      continue;
    }

    floyd();
    initGraph();
    solve();
  }
}
/*
5
0 0 0
0 0 0
0 0 0
0 0 0
1 1 1
1 1 1
*/
