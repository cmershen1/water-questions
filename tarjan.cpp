/*
author:cmershen
description:Tarjan算法模板：求无向图的割点和桥
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> g[20005];
int counter=0;
int visited[20005],dfn[20005],low[20005],parent[20005];
void tarjan(int u) {
  int children=0;
  visited[u]=1;
  dfn[u]=low[u]=++counter;
  for(int i=0;i<g[u].size();i++) {
    int v=g[u][i];
    if(!visited[v]) {
      children++;
      parent[v]=u;
      tarjan(v);
      if(low[v]<low[u])
        low[u]=low[v];

      if(parent[u]==0 && children>1)
        printf("articulation point: %d\n", u);
      if(parent[u]!=0 && low[v]>=dfn[u])
        printf("articulation point: %d\n", u);
      if(low[v]>dfn[u])
        printf("bridge: %d %d\n", u,v);
    }
    else if(v!=parent[u]) {
      if(dfn[v]<low[u])
        low[u]=dfn[v];
    }
  }
}
int main() {
  int n,m;
  scanf("%d %d",&n,&m);
  memset(visited,0,sizeof(visited));
  memset(dfn,0,sizeof(dfn));
  memset(low,0,sizeof(low));
  memset(parent,0,sizeof(parent));
  while(m--) {
    int u,v;
    scanf("%d %d", &u,&v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  tarjan(1);
}
