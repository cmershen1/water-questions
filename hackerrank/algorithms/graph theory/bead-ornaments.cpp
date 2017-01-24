#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
#define INF 0x3f3f3f3f
const int M = 1e9+7;
const double PI = acos(-1.0);
ll t,n,b;
ll p1[33],p2[33];

ll qmod(ll a,ll b,ll c) {
	ll ans=1;
	a=a%c;
	while(b>0) {
		if(b&1)
			ans=(ans*a)%c;
		b=b/2;
		a=(a*a)%c;
	}
	return ans;
}
void pre() {
	p1[1]=p2[1]=1;
	for(int i=2;i<=30;i++) {
		p1[i]=qmod(i,i-2,M);
		p2[i]=qmod(i,i-1,M);
	}
}
int main() {
	//RE("in.txt");WR("out.txt");
	pre();
	cin>>t;
	while(t--) {
		ll ans=1;
		ll sum=0;
		cin>>n;
		if(n==1) {
			cin>>b;
			cout<<p1[b]<<endl;
			continue;
		}
		for(int i=0;i<n;i++) {
			cin>>b;
			sum+=b;
			ans=(ans*p2[b])%M;
		}
		ans=ans*qmod(sum,n-2,M)%M;
		cout<<ans<<endl;
	}
}
