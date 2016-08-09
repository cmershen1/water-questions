#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cal(ll n) {
  ll sum=0;
  for(ll i=2;i*i*i<=n;i++) {
    sum+=n/(i*i*i);
  }
  return sum;
}
int main() {
  ll m;
  scanf("%I64d", &m);

  ll l=0,r=1e16,ans=-1;
  while(l<r) {
    ll mid=(l+r)/2;
    ll temp=cal(mid);
  //  cout<<mid<<' '<<temp<<endl;
    if(temp>m)
      r=mid-1;
    else if(temp==m)
      r=mid;
    else
      l=mid+1;
  }
  if(cal(l)==m)
    ans=l;
  printf("%I64d\n", ans);
}
