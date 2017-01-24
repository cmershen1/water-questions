#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int T,n,m;
struct node{
    int to,next,w;
}edge[80005];
int head[40005],cnt,op;
int dep[40005],e[40005],father[40005];//dep表示第i个点的深度，father表示第i个点的父节点,e[i]表示终点为i的边的序号
void addedge(int u,int v,int w) {
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int u,int f,int d) { //u点，父节点是f，深度是d
    dep[u]=d;
    father[u]=f;
    for(int i=head[u];i!=-1;i=edge[i].next) {
        int v=edge[i].to;
        if(v!=f) {
            e[v]=i;
            dfs(v,u,d+1);
        }
    }
}

int main(){
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        memset(head,-1,sizeof(head));
        cnt=0;
        for(int i=1;i<n;i++) {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);

        }
        dfs(1,0,1);
        for(int i=0;i<m;i++) {
            scanf("%d",&op);
            if(op) {
                int x,y,z;
                scanf("%d %d %d",&x,&y,&z);
                while(x!=y) {
                    if(dep[x]<dep[y])
                        swap(x,y);
                    int id=e[x];
                    edge[id].w=edge[id^1].w=z;
                    x=father[x];
                }

            }
            else {
                int x;
                scanf("%d",&x);
                int ans=0;
                for(int i=head[x];i!=-1;i=edge[i].next) {
                    ans+=edge[i].w;
                }
                if(ans&1)
                    printf("Girls win!\n");
                else
                    printf("Boys win!\n");
            }
        }
    }

    return 0;
}
