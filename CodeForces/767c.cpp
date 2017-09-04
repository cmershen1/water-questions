#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
int n;
int dp[maxn];
int t[maxn];
int fa[maxn];
int vis[maxn];
int root;
vector<int> g[maxn];
set<int> s,s2;

void dfs(int u) {
    dp[u] = t[u];
    for(int i = 0; i < g[u].size();i++) {
        int v = g[u][i];
        dfs(v);
        dp[u]+=dp[v];
    }
}

int find(int u) {
    if (u==0||vis[u])
        return -1;
    int target = dp[root] / 3;
    while(u != root) {
        if(vis[u])
            break;
        vis[u]=true;
        if(dp[u] == target * 2) {
            return u;
        }
        if (dp[u] == target) {
            s2.erase(u);
        }
        u = fa[u];
    }
    if(dp[u] == target) {
        s2.erase(u);
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i <= n; i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(i);
        fa[i]=u;
        t[i]=v;
        if (u == 0) {
            root = i;
        }
    }
    dfs(root);
    if (dp[root] % 3) {
        cout<<-1<<endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i] * 3 == dp[root]) {
            s.insert(i);
            s2.insert(i);
        }
    }

    for(int i : s) {
        int ret = find(fa[i]);
        if(ret != -1) {
            cout<<ret<<' '<<i<<endl;
            return 0;
        }
    }
    if (s2.size() >= 2) {
        auto it = s2.begin();
        cout<<*it<<' ';
        it++;
        cout<<*it<<endl;
        return 0;
    } else  {
        cout<<-1<<endl;
        return 0;
    }
}
