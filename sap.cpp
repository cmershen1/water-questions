/**
*@author:cmershen
*@description:sap算法，求最大流，网络用前向星表示
*/
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
