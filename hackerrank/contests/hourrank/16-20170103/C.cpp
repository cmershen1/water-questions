#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
const int M = 1e9+9;
int n;
vector<pair<int,int> > g[5005];
ll dis[5005][5005];
int dep[5005][5005];

ll fac[5005];
ll f[5005];
int egcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int ans = egcd(b, a % b, x, y);
  int temp = x;
  x = y;
  y = temp - a / b * y;
  return ans;
}
int cal(int a, int m = M) {
  int x, y;
  int gcd = egcd(a, m, x, y);
  if (1 % gcd != 0)
    return -1;
  x *= 1 / gcd;
  m = abs(m);
  int ans = x % m;
  if (ans <= 0)
    ans += m;
  return ans;
}
void pre() {
    fac[1]=1;
    for(int i=2;i<=5000;i++)
        fac[i]=(fac[i-1]*i)%M;
    for(int i=1;i<=5000;i++)
        f[i]=cal(i);
}
void dfs(int u,int rt,int fa) {
    if(fa==0) {
        dis[rt][rt]=0;
        dep[rt][rt]=1;
    }
    for(int i=0;i<g[u].size();i++) {
        int v=g[u][i].first,w=g[u][i].second;
        if(v!=fa) {
            dis[rt][v]=(dis[rt][u]+w)%M;
            dep[rt][v]=dep[rt][u]+1;
            dfs(v,rt,u);
        }
    }

}
int main(){
    RE("in.txt");
    WR("out.txt");
    pre();
    cin>>n;
    int u,v,w;
    for(int i=1;i<n;i++) {
        cin>>u>>v>>w;
        g[u].pb(mp(v,w));
        g[v].pb(mp(u,w));
    }
    memset(dis,0,sizeof(dis));
    memset(dep,0,sizeof(dep));
    for(int i=1;i<=n;i++) {
        dfs(i,i,0);
    }
    ll ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            ans=(ans+dis[i][j]*2*f[dep[i][j]])%M;
        }
    }
    ans=(ans*fac[n])%M;
    cout<<ans<<endl;
}
