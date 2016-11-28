#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int n,m,x,y;
int u,v;
vector<int> g[1005];
int c[1005];
int father[1005],num[1005],id[1005];
bool vis[1005];
bool dfs(int u,int col) { //给u点染col
    c[u]=col;
    vis[u]=true;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if(c[v]==col)
            return false;
        else if(!vis[v]) {
            if(col==1) {
                if(!dfs(v,2)) return false;
            }
            else {
                if(!dfs(v,1)) return false;
            }
        }
    }
    return true;
}
int find(int x) {
    return father[x]==x?x:find(father[x]);
}
void Union(int i,int j) {
    i=find(i);
    j=find(j);
    if(i!=j) {
        father[i]=j;
        num[j]+=num[i];
    }
}
int main() {
    while(~scanf("%d %d %d %d",&n,&m,&x,&y)) {
        for(int i=1;i<=n;i++) {
            g[i].clear();
        }
        memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            father[i]=i;
            num[i]=1;/*开始时数量都为1，根节点为自己*/
            id[i]=0;
        }
        for(int i=0;i<m;i++) {
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
            Union(u,v);
        }
        for(int i=0;i<x;i++) {
            scanf("%d",&u);
            c[u]=1;
            id[find(u)]=u;
        }
        for(int i=0;i<y;i++) {
            scanf("%d",&u);
            c[u]=2;
            id[find(u)]=u;
        }
        bool ans=true;
        if(n==1 && c[1]==0)
            ans=false;
        for(int i=1;i<=n;i++) {
            if(num[find(i)]==1 && c[i]==0) {
                ans=false;
                break;
            }
        }
        if(ans) {
            for(int i=1;i<=n;i++) {
                int p=find(i);//得到i点的祖先
                if(id[p]==0) { //这一坨都没有染过色
                    ans=dfs(p,1);
                }
                else { //id[p]表示有染色的点
                    ans=dfs(id[p],c[id[p]]);
                }
                if(!ans)
                    break;
            }
        }
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
