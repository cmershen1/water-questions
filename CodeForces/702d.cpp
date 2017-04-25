#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll d,k,a,b,t;
  scanf("%I64d %I64d %I64d %I64d %I64d", &d,&k,&a,&b,&t);
  ll ans=0;
  if(d<=k)
    ans=d*a;

  else if(k*b<k*a+t)
    ans=k*a+(d-k)*b;

  else {
    ll T=(d-k)/k,r=d-k-k*T;
    ans=k*a+(k*a+t)*T+min(r*b,r*a+t);
  }
  printf("%I64d\n", ans);
}
