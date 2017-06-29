#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+5;
int n;
vector<int> g[MAXN];
int dp[MAXN][32][2];
int a[MAXN];
ll ans[32];

void dfs(int u, int fa) {
    for(int i=0;i<30;i++) {
        if(a[u] & (1<<i)) {
            dp[u][i][1]=1;
            dp[u][i][0]=0;
            ans[i]++;
        } else {
            dp[u][i][1]=0;
            dp[u][i][0]=1;
        }
    }
    
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if(v==fa) continue;
        dfs(v,u);
        for(int i=0;i<30;i++) {
            ans[i]+=dp[u][i][1]*dp[v][i][0] + dp[u][i][0]*dp[v][i][1];
            if(a[u] & (1<<i)) {
                dp[u][i][0]+=dp[v][i][1];
                dp[u][i][1]+=dp[v][i][0];
            } else {
                dp[u][i][0]+=dp[v][i][0];
                dp[u][i][1]+=dp[v][i][1];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    int u,v;
    for(int i=1;i<n;i++) {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    ll ret=0;
    for(int i=31;i>=0;i--) {
        ret+=(ll)ans[i]*(1LL<<i);
    }
    cout<<ret<<endl;
}
