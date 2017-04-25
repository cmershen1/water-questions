//有问题，一个测试点过不去！！
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
#define INF 0x3f3f3f3f
const int M = 1e9;
const double PI = acos(-1.0);
int n,m;
vector<int> g[10005];
vector<int> g2[10005];
deque<int> tp;
ll dp[10005];
int vis[10005];
int deg[10005];
bool cy=false;
void dfs(int u) {
	vis[u]=1;
	for(int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if(vis[v]==1 && vis[n]==1)
			cy=true;
		else if(vis[v]==0)
			dfs(v);
	}
	vis[u]=2;
}
void dfs2(int u) {
	vis[u]=1;
	for(int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if(!vis[v])
			dfs2(v);
	}
	tp.push_front(u);
}
int main() {
	//RE("in.txt");WR("out.txt");
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	memset(deg,0,sizeof(deg));
	cin>>n>>m;
	for(int i=m;i>0;i--) {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g2[v].push_back(u);
	}
	dfs(1);
	if(cy) {
		cout<<"INFINITE PATHS"<<endl;
	}
	else {
		dp[1]=1;
		memset(vis,0,sizeof(vis));
		dfs2(1);
		for(int i=0;i<tp.size();i++) {
			int u=tp[i];
			for(int j=0;j<g2[u].size();j++) {
				int v=g2[u][j];
				dp[u]=(dp[u]+dp[v])%M;
			}
		}
		cout<<dp[n]<<endl;
	}
}
