#include <bits/stdc++.h>
using namespace std;
#define RE(x) freopen(x,"r",stdin)
#define WR(x) freopen(x,"w",stdout)
typedef long long ll;
const int M = 1e9+7;
ll a[44800],b[44800],c[44800];
int T;
ll n;
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
    b[0]=1;
    for(int i=1;i<=44723;i++) {
        a[i]=i*(i+1)/2-1;
        b[i]=b[i-1]*i%M;
        c[i]=cal(i);
    }
}
int find(ll x) {
    int l=1,r=44721;
    while(l<r) {
		//cout<<l<<","<<r<<endl;
        int mid=(l+r)/2;
        if(a[mid]<=x && x<a[mid+1])
            return mid;
        else if(a[mid]>x)
            r=mid;
        else
            l=mid+1;
    }
    return -1;
}
int main() {
    pre();

    scanf("%d",&T);
    while (T--) {
        scanf("%I64d",&n);
		if(n<=4) {
			printf("%lld\n",n);
			continue;
		}
        int k=find(n);
        int s=n-a[k];
        ll ans=0;
		if(s==0) {
			ans=b[k];
		}
	    else if(s==k) {
            ans=b[k]*c[2]%M;
            ans=ans*(k+2)%M;
        }
        else {
            ans=b[k]*c[k+1-s]%M;
            ans=ans*(k+1)%M;
        }
        printf("%lld\n", ans);

    }
    return 0;
}
