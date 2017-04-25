#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
//vector<int> g[100005];
struct edge {
  int u,v,l;
};
edge e[100005];
bool storage[100005];
int main() {
  memset(storage,0,sizeof(storage));
  int n,m,k,u,v,l,a;
  scanf("%d %d %d", &n,&m,&k);
  for(int i=0;i<m;i++) {
    scanf("%d %d %d", &u,&v,&l);
    //g[u].push_back(v);
    //g[v].push_back(u);
    e[i].u=u;e[i].v=v;e[i].l=l;
  }
  for(int i=0;i<k;i++) {
    scanf("%d", &a);
    storage[a]=true;
  }
  int ans=INF;
  for(int i=0;i<m;i++) {
    if((storage[e[i].u] && !storage[e[i].v]) || (!storage[e[i].u] && storage[e[i].v]))
      ans=min(ans,e[i].l);
  }
  if(ans==INF)
    printf("-1\n");
  else
    printf("%d\n", ans);
}
