#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> g[32];
pair<ll,ll> ans[32];
int vis[32];
int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};

void dfs(ll x,ll y,int u,int last,int layer) {
    ans[u]=make_pair(x,y);
    int p=0;
    int next_dir[4]={0,1,2,3};
    int disable=(last==-1)?-1:(last+2)%4;
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if(!vis[v]) {
            vis[v]=true;
            if(p==disable)
                p++;
            dfs(x+dir[p][0]*(1ll<<layer), y+dir[p][1]*(1ll<<layer), v, p, layer-1);
            p++;
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int u,v;
    while(cin>>n) {
        for(int i=1;i<=n;i++) {
            g[i].clear();
        }
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<n-1;i++) {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool flag = true;
        for(int i=1;i<=n;i++) {
            if(g[i].size()>4) {
                flag=false;
                break;
            }
        }
        if(!flag)
            cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            vis[1]=1;
            dfs(0,0,1,-1,32);
            for(int i=1;i<=n;i++) {
                cout<<ans[i].first<<' '<<ans[i].second<<endl;
            }
        }
    }
}
