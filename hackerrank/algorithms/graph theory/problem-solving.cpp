#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
#define INF 0x3f3f3f3f
const int M = 1e9+7;
const double PI = acos(-1.0);
int t,n,k;
int v[1005];
int f[2005];
bool vis[2005];
vector<int> g[2010];
void addedge(int i,int j) {
	g[2*i-1].push_back(2*j);
	g[2*j].push_back(2*i-1);
}
bool dfs(int i) {
	vis[i]=1;
	for(int j=0;j<g[i].size();j++) {
		int u=g[i][j];
		if(f[u]==-1 || (!vis[f[u]] && dfs(f[u]))) {
			f[u]=i;
			f[i]=u;
			return true;
		}
	}
	return false;
}
int main() {
	//RE("in.txt");WR("out.txt");
	cin>>t;
	while (t--) {
		cin>>n>>k;
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++) {
			cin>>v[i];
		}
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(abs(v[i]-v[j])>=k)
					addedge(i,j);
			}
		}
		memset(f,-1,sizeof(f));
		int cnt=0;
		for(int i=1;i<=n*2;i++) {
			if(f[i]==-1) {
				memset(vis,0,sizeof(vis));
				cnt+=dfs(i);
			}
		}
		cout<<n-cnt<<endl;
	}
}
