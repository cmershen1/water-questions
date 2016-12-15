#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
#define INF 0x3f3f3f3f
const int M = 1e9+7;
const double PI = acos(-1.0);

int main() {
	//RE("in.txt");WR("out.txt");
	int t,n,k;
	int vis[100005];
	cin>>t;
	while(t--) {
		cin>>n>>k;
		memset(vis,0,sizeof(vis));
		vector<int> ans;
		for(int i=1;i<=n;i++) {
			if(i-k>=1 && !vis[i-k]) {
				vis[i-k]=true;
				ans.push_back(i-k);
			}
			else if(i+k<=n && !vis[i+k]) {
				vis[i+k]=true;
				ans.push_back(i+k);
			}
			else {
				cout<<-1<<endl;
				break;
			}
		}
		if(ans.size()==n) {
			for(int i=0;i<n-1;i++) {
				cout<<ans[i]<<' ';
			}
			cout<<ans.back()<<endl;
		}
	}
}

