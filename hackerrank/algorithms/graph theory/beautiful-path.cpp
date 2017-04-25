#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
struct Edge {
    int next,to,cost;
}edge[20005];
int head[20005],p;
bool dp[1005][1030];
void addedge(int u,int v,int c) {
    edge[p].next=head[u];
    edge[p].to=v;
    edge[p].cost=c;
    head[u]=p++;
}
void dfs(int u,int state) {
    dp[u][state]=1;
    for(int i=head[u];i!=-1;i=edge[i].next) {
        int s=edge[i].cost;
        int v=edge[i].to;
        if(!dp[v][state|s])
            dfs(v,state|s);
    }
}
int main(){
    memset(head,-1,sizeof(head));
    memset(dp,0,sizeof(dp));
    cin>>n>>m;
    int u,v,c,a,b;
    while(m--) {
        cin>>u>>v>>c;
        addedge(u,v,c);
        addedge(v,u,c);
    }
    cin>>a>>b;
    dfs(a,0);
    int ans=-1;
    for(int i=0;i<1024;i++) {
        if(dp[b][i]) {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
}
