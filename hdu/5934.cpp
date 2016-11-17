#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int T,n;
ll x[1005],y[1005],r[1005],c[1005];
ll ans;
vector<int> g[1005];
int indegree[1005];
int low[1005],dfn[1005],stk[1005],belong[1005];
int num[1005];//每个强连通分量包含点个数
int index,top;
int scc;//强连通分量个数
bool instack[1005];
ll w[1005];//缩点后的最小值
void tarjan(int u) {
    low[u]=dfn[u]=++index;
    stk[top++]=u;
    instack[u]=true;
    int v;
    for(int i=0;i<g[u].size();i++) {
        v=g[u][i];
        if(!dfn[v]) {
            tarjan(v);
            if(low[u]>low[v])
                low[u]=low[v];
        }
        else if(instack[v] && low[u]>dfn[v])
            low[u]=dfn[v];
    }
    if(low[u]==dfn[u]) {
        scc++;
        v=stk[--top];
        instack[v]=false;
        belong[v]=scc;
        num[scc]++;
        while(v!=u) {
            v=stk[--top];
            instack[v]=false;
            belong[v]=scc;
            num[scc]++;
        }
    }
}
void solve() {
    memset(dfn,0,sizeof(dfn));
    memset(instack,0,sizeof(instack));
    memset(num,0,sizeof(num));
    memset(indegree,0,sizeof(indegree));
    index=top=scc=0;

    for(int i=1;i<=n;i++) {
        g[i].clear();
        for(int j=1;j<=n;j++) {
            if(j!=i) {
                ll dis = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                if(dis<=r[i]*r[i])
                    g[i].push_back(j);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        if(!dfn[i])
            tarjan(i);
    }

    memset(w,0x3f,sizeof(w));
    for(int i=1;i<=n;i++) {
        int x=belong[i];
        w[x]=min(w[x],c[i]);
        for(int j=0;j<g[i].size();j++) {
            int u=g[i][j],y=belong[u];
            if(x!=y)
                indegree[y]++;
        }
    }
    ans=0;
    for(int i=1;i<=scc;i++) {
        if(indegree[i]==0)
            ans+=w[i];
    }
}
int main() {

    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%I64d %I64d %I64d %I64d",&x[i],&y[i],&r[i],&c[i]);
        }
        solve();
        printf("Case #%d: %I64d\n", t,ans);
    }
}
