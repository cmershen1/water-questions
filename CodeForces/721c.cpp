#include <bits/stdc++.h>
using namespace std;
vector<int> g[5005];
vector<int> dist[5005];
short to[5005][5005];
int dp[5005][5005];
bool vis[5005];
int n,m,t;
void dfs(int c) { // depth-first search from node c
    vis[c]=true;
    if(c==n)
        return;
    for(int i=0;i<g[c].size();i++) {
        int k=g[c][i],d=dist[c][i];
        if(!vis[k])
            dfs(k);
        for(int j=2;j<=n;j++) {
            if(dp[k][j-1]+d<dp[c][j]) {
                dp[c][j]=dp[k][j-1]+d;
                to[c][j]=k;
            }
        }
    }
}
int main() {
    memset(vis,0,sizeof(vis));
    memset(dist,0,sizeof(dist));
    memset(to,0,sizeof(to));
    memset(dp,0x3f,sizeof(dp));

    scanf("%d %d %d",&n,&m,&t);
    int u,v,d;
    for(int i=0;i<m;i++) {
        scanf("%d %d %d",&u,&v,&d);
        g[u].push_back(v);
        dist[u].push_back(d);
    }
    dp[n][1]=0;
    dfs(1);

    int a=0;
    for(int i=n;i>=1;i--) {
        if(dp[1][i] <= t) {
            printf("%d\n", i);
            printf("1 ");
            a=i;
            break;
        }
    }
    int j=1;
    while(a>1) {
        if(a!=1)
            printf("%d ", to[j][a]);
        else
            printf("%d", to[j][a]);
        j=to[j][a--];
    }
}
