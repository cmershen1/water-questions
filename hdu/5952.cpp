#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int T;
int n,m,s;
vector<int> g[105];
bool graph[105][105];
bool vis[105];
int ans;
int path[105];
void dfs(int u,int d) { //当前搜索u点，已经找到d个点的完全图
    if(d==s) {
        ans++;
        return;
    }
    if(g[u].size()+d<s)
        return;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        bool flag=true;
        for(int j=0;j<d;j++) {
            if(!graph[v][path[j]])
                flag=false;
            if(g[v].size()+1+d<s)
                flag=false;
            if(!flag) break;
        }
        if(flag) {
            vis[v]=true;
            path[d]=v;
            dfs(v,d+1);
            vis[v]=false;
        }

    }
}
int main() {
    RE("in.txt");
    WR("out.txt");
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d %d",&n,&m,&s);
        for(int i=1;i<=n;i++)
            g[i].clear();
        memset(vis,0,sizeof(vis));
        memset(path,0,sizeof(path));
        memset(graph,0,sizeof(graph));
        while(m--) {
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u][v]=graph[v][u]=1;
            g[min(u,v)].push_back(max(u,v));
        }
        ans=0;
        for(int i=1;i<=n;i++) {
            if(!vis[i]) {
                vis[i]=true;
                path[0]=i;
                dfs(i,1);
                vis[i]=false;
            }
        }
        printf("%d\n", ans);
    }
}
