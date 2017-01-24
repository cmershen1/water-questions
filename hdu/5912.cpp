#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int a[12],b[12];
ll p,q;
ll gcd(ll a,ll b) {
  if(b==0)
      return a;
  return gcd(b,a%b);
}
void solve() {
  ll x=a[n],y=1;//初始化为an,每轮迭代都记为x/y
  ll g=1;
  for(int i=n;i>=1;i--) { //迭代n次
    ll x2=x,y2=y;//记录下来
    x=y2*b[i]+x2*a[i-1];
    y=x2;
    g=gcd(x,y);
    x/=g;
    y/=g;
  }
  g=gcd(x,y);
  p=x/g,q=y/g;
}
int main() {
  scanf("%d",&t);
  a[0]=0;
  for(int i=1;i<=t;i++) {
    scanf("%d",&n);
    for(int j=1;j<=n;j++)
      scanf("%d",&a[j]);
    for(int j=1;j<=n;j++)
      scanf("%d",&b[j]);
    solve();
    printf("Case #%d: %I64d %I64d\n",i,p,q);
  }
}
