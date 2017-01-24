#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
#define INF 0x3f3f3f3f
typedef long long ll;
int c,n,t,m;
struct Edge {
    int next,to,flow;
}edge[40005];
int head[1230],p,level[1230];
int deg[123];
void addedge(int u,int v,int w) {
    edge[p].to=v;
    edge[p].flow=w;
    edge[p].next=head[u];
    head[u]=p;p++;

    edge[p].to=u;
    edge[p].flow=0;
    edge[p].next=head[v];
    head[v]=p;p++;
}
void init() {
    memset(head,-1,sizeof(head));
    memset(deg,0,sizeof(deg));
    memset(edge,0,sizeof(edge));
    p=0;
}
bool bfs(int s,int t) {
    memset(level,0,sizeof(level));
    queue<int> q;
    q.push(s);
    level[s]=1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        if(t==u)
            return true;
        for(int i=head[u];i!=-1;i=edge[i].next) {
            int v=edge[i].to,f=edge[i].flow;
            if(level[v] == 0 && f!=0) {
                q.push(v);
                level[v]=level[u]+1;
            }
        }
    }
    return false;
}
int dfs(int u,int maxf,int t) {
    if(u==t)
        return maxf;
    int temp=0;
    for(int i=head[u];i!=-1&&temp<maxf;i=edge[i].next) {
        int v=edge[i].to,f=edge[i].flow;
        if(level[v] == level[u]+1 && f!=0) {
            f=dfs(v,min(maxf-temp,f),t);
            edge[i].flow-=f;edge[i^1].flow+=f;temp+=f;
        }
    }
    if(!temp)
        level[u]=INF;
    return temp;
}
int dinic(int s,int t) { //源点s，汇点t，求最大流
    ll ans=0;
    while(bfs(s,t))
        ans+=dfs(s,INF,t);
    return ans;
}
int main() {
    RE("in.txt");
    WR("out.txt");
    cin>>c;
    while(c--) {
        init();
        cin>>n>>t>>m;
        int u,v;
        for(int i=0;i<m;i++) {
            cin>>u>>v;
            deg[u]++;deg[v]++;
            addedge(2*u,2*v+1,1);
            addedge(2*v,2*u+1,1);
        }
        for(int i=1;i<=n;i++) {
            addedge(1,2*i,min(t,deg[i]));
            addedge(2*i+1,2*n+2,1);
        }
        cout<<dinic(1,2*n+2)<<endl;
    }

}
