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
    int u,v,cap;
    int next;
}edge[20005];
int head[1005],p;
int gap[1005],dep[1005],cur[1005],stk[1005];
void addedge(int u,int v) {
    int c=cost[u][v];
    edge[p].u=u;edge[p].v=v;edge[p].cap=c;
    edge[p].next=head[u]; head[u]=p++;

    edge[p].u=v;edge[p].v=u;edge[p].cap=0;
    edge[p].next=head[v]; head[v]=p++;
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
void bfs(int t) {
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    queue<int> q;
    dep[t]=0;
    gap[0]=1;
    q.push(t);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next) {
            int v=edge[i].v;
            if(edge[i^1].cap>0 && dep[v]==-1) {
                q.push(v);
                dep[v]=dep[u]+1;
                gap[dep[v]]++;
            }
        }
    }
}
int sap(int s,int t) {
    bfs(t);
    memcpy(cur,head,sizeof(cur));
    int ans=0;
    int u=s,top=0,i;
    while(dep[s]<n) {
        if(u==t) {
            int delta=INF;
            int flag=n;
            for(i=0;i!=top;i++) {
                if(delta>edge[stk[i]].cap) {
                    delta=edge[stk[i]].cap;
                    flag=i;
                }
            }
            for(i=0;i!=top;i++) {
                edge[stk[i]].cap-=delta;
                edge[stk[i]^1].cap+=delta;
            }
            ans+=delta;
            top=flag;
            u=edge[stk[top]].u;
        }
        for(i=cur[u];i!=-1;i=edge[i].next) {
            int v=edge[i].v;
            if(edge[i].cap>0 && dep[u]==dep[v]+1)
                break;
        }
        if(i!=-1) {
            cur[u]=i;
            stk[top++]=i;
            u=edge[i].v;
        }
        else {
            if(--gap[dep[u]]==0)
                break;
            int mind=n+1;
            for(i=head[u];i!=-1;i=edge[i].next) {
                if(edge[i].cap>0 && mind>dep[edge[i].v]) {
                    mind=dep[edge[i].v];
                    cur[u]=i;
                }
            }
            dep[u]=mind+1;
            gap[dep[u]]++;
            u=(u==s)?u:edge[stk[--top]].u;
        }

    }
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
        printf("%d\n", sap(1,n));        //源点1，汇点n，求最大流
    }

}
