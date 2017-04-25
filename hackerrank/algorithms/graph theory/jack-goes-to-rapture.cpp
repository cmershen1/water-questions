#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)

int n,m;
vector<pair<int,int> > g[50005];

struct Edge {
    int from,to,w;
}edge[20005];
int p=0;

void addedge(int u,int v,int w) {
    edge[p].from=u;
    edge[p].to=v;
    edge[p].w=w;
    p++;
}
bool cmp(Edge a,Edge b) {
    return a.w<b.w;
}
int f[50005];
bool vis[50005];
// int find(int x) {
//     return f[x]==x?x:f[x]=find(f[x]);
// }
int find(int x) {
    if(x!=f[x])
        f[x]=find(f[x]);
    return f[x];
}
void un(int i,int j) {
    i=find(i);
    j=find(j);
    if(i!=j)
        f[i]=j;
}
int ans=-1;
void dfs(int u,int dis) {
    if(u==n)
        ans=dis;
    vis[u]=1;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i].first;
        int w=g[u][i].second;
        if(!vis[v] && ans==-1)
            dfs(v,max(dis,w));
    }
}
int main() {
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        f[i]=i;
    }
    int u,v,w;
    for(int i=0;i<m;i++) {
        cin>>u>>v>>w;
        addedge(u,v,w);
    }
    sort(edge,edge+m,cmp);
    for(int i=0;i<m;i++) {
        u=edge[i].from;v=edge[i].to,w=edge[i].w;
        if(find(u)!=find(v)) {
            un(u,v);
            g[u].push_back(pair<int,int>(v,w));
            g[v].push_back(pair<int,int>(u,w));
        }
    }
    if(find(1)!=find(n))
        cout<<-1<<endl;
    else {
        dfs(1,0);
        cout<<ans<<endl;
    }
}
