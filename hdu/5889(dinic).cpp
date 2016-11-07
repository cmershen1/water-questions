#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
#define INF 0x3f3f3f3f
int t,u,v,w,n,m;
int cost[1005][1005];
int dis[1005];

struct EDGE {
    int to,next,flow;
}edge[20005];
int head[10005],p,level[10005];
void addedge(int u,int v) {
    int w=cost[u][v];
    edge[p].to=v;
    edge[p].flow=w;
    edge[p].next=head[u];
    head[u]=p;p++;

    edge[p].to=u;
    edge[p].flow=0;
    edge[p].next=head[v];
    head[v]=p;p++;
}
void dijkstra(int u) { //u点为源，求单源最短路径
    bool vis[1005];
    for(int i=1;i<=n;i++) {
        if(cost[i][u]!=INF && i!=u)
            dis[i]=1;
        else
            dis[i]=INF;
        vis[i]=false;
    }
    dis[u]=0;
    vis[u]=true;
    for(int i=1;i<=n;i++) {
        int min=INF;
        int x;
        for(int j=1;j<=n;j++) {
            if(!vis[j] && dis[j]<min) {
                min=dis[j];
                x=j;
            }
        }
        vis[x]=true;
        for(int j=1;j<=n;j++)
            if(!vis[j] && cost[x][j]!=INF && min+1<dis[j])
                dis[j]=min+1;
    }
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
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        memset(cost,0x3f,sizeof(cost));
        memset(head,-1,sizeof(head));
        p=0;
        for(int i=1;i<=m;i++) {
            scanf("%d %d %d",&u,&v,&w);
            cost[u][v]=w;
            cost[v][u]=w;
        }
        dijkstra(1);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(dis[i]+1==dis[j] && cost[i][j]!=INF)
                    addedge(i,j);
            }
        }
        printf("%d\n", dinic(1,n));        //源点1，汇点n，求最大流
    }

}
