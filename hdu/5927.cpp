//source:2016CCPC东北地区大学生程序设计竞赛 - 重现赛
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n,q,u,v,mi;
vector<int> g[100005];
int fa[100005];
int dp[100005];
int dp2[100005];
int m[100005];
int deep[100005];
int ans;
void dfs(int u,int par,int d) {
    deep[u]=d;
    if(!fa[u])
        fa[u]=par;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if(!fa[v]) {
            dfs(v,u,d+1);
            dp[u]++;
        }
    }
}
bool cmp(int x,int y) {
    return deep[y]<deep[x];
}
void solve() {
    sort(m,m+mi,cmp);
    for(int i=0;i<mi;i++) {
        int u=m[i];
        if(dp2[u]==0)//u点非重要 且u点的孩子没有重要点
            dp2[fa[u]]--;
    }
    for(int i=0;i<mi;i++) {
        int u=m[i];
        if(dp2[u]>=2)
            ans++;
    }
}
int main() {
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        scanf("%d %d",&n,&q);
        memset(fa,0,sizeof(fa));
        memset(dp,0,sizeof(dp));
        memset(deep,0,sizeof(deep));
        memset(g,0,sizeof(g));
        for(int i=0;i<n-1;i++) {
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,-1,0);//确定父子关系和深度
        printf("Case #%d:\n",t);
        while(q--) {
        //    memset(m,0,sizeof(m));这句不注释掉会T！！！T了13发！！！！！！
            scanf("%d",&mi);
            for(int i=0;i<mi;i++)
                scanf("%d",&m[i]);

            for(int i=0;i<mi;i++)
                dp2[m[i]]=dp[m[i]];
            ans=n-mi;
            solve();
            printf("%d\n", ans);
        }
    }
}
