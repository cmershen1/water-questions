/**
*@author:cmershen
*@description:dinic算法，求最大流，网络用前向星表示
*/

#define INF 0x3f3f3f3f
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
