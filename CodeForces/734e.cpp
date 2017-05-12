#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200005;

int col[MAXN];
vector<int> g[MAXN],g2[MAXN];

bool vis[MAXN];
int belong[MAXN];
int cnt=1;
void dfs(int u, int cur) {
    if(vis[u]) return;
    vis[u]=true;

    if(col[u] != col[cur]) {
        g2[u].push_back(cur);
        g2[cur].push_back(u);
        cur=u;
    }

    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        dfs(v, cur);
    }
}
int max_node=-1,max_dis=-1;
void dfs2(int u, int dis) {
    if(vis[u]) return;
    vis[u]=true;
    if(dis>max_dis) {
        max_dis=dis;
        max_node=u;
    }
    for(int i=0;i<g2[u].size();i++) {
        int v=g2[u][i];
        dfs2(v,dis+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    int n,a,b;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>col[i];
    }
    for(int i=1;i<n;i++) {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(vis,0,sizeof(vis));
    memset(belong,0,sizeof(belong));
    dfs(1,1);//缩点
    //找最大路径
    memset(vis,0,sizeof(vis));
    dfs2(1,0);
    memset(vis,0,sizeof(vis));
    dfs2(max_node,0);

    cout<<(max_dis+1)/2<<endl;
}
