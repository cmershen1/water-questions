#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
int T,n,s;
vector<int> g[1600];
int f[1600],vis[1600];
bool dfs(int i) {
    vis[i]=1;
    for(int j=0;j<g[i].size();j++) {
        int u=g[i][j];
        if(f[u] == -1 || (!vis[f[u]] && dfs(f[u]))) {
            f[u]=i;
            f[i]=u;
            return 1;
        }
    }
    return 0;
}
int hungary(int num) {
    int cnt=0;
    memset(f,-1,sizeof(f));
    for(int i=1;i<=num*2;i++) {//总点数为2n或者2s
        if(f[i]==-1) {
            memset(vis,0,sizeof(vis));
            cnt+=dfs(i);
        }
    }
    return cnt;
}
int main() {
    RE("in.txt");
    WR("out.txt");
    scanf("%d",&T);
    for(int t=1;t<=T;t++) {
        scanf("%d %d",&n,&s);
        if(min(n,s)>777) {
            printf("Case #%d: No\n",t);
        }
        else {
            memset(g,0,sizeof(g));
            int num;
            if(n<s+1) {
                num=n;//2n个点
                for(int i=1;i<=n;i++) { //枚举位置
                    for(int j=1;j<=n;j++) { //枚举id，s+1~s+n
                        if((s+j)%i==0) {//加边
                            g[i].push_back(n+j);
                            g[n+j].push_back(i);
                        }
                    }
                }
            }
            else {
                num=s;//2s个点
                for(int i=1;i<=s;i++) { //枚举位置
                    for(int j=1;j<=s;j++) { //枚举id，n+1~s+n
                        if((n+j)%i==0) {
                            g[i].push_back(s+j);
                            g[s+j].push_back(i);
                        }
                    }
                }
            }
            int ans=hungary(num);
            if(ans==num) {
                printf("Case #%d: Yes\n",t);
            }
            else {
                printf("Case #%d: No\n",t);
            }
        }
    }
}
