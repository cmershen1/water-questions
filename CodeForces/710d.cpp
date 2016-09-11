#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Mod;
ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

ll Extend_Euclid(ll a, ll b, ll&x, ll& y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll d = Extend_Euclid(b,a%b,x,y);
    ll t = x;
    x = y;
    y = t - a/b*y;
    return d;
}

//a在模n乘法下的逆元，没有则返回-1
ll inv(ll a, ll n)
{
    ll x,y;
    ll t = Extend_Euclid(a,n,x,y);
    if(t != 1)
        return -1;
    return (x%n+n)%n;
}
bool merge(ll a1, ll n1, ll a2, ll n2, ll& a3, ll& n3)
{
    ll d = gcd(n1,n2);
    ll c = a2-a1;
    if(c%d)
        return false;
    c = (c%n2+n2)%n2;
    c /= d;
    n1 /= d;
    n2 /= d;
    c *= inv(n1,n2);
    c %= n2;
    c *= n1*d;
    c += a1;
    n3 = n1*n2*d;
    a3 = (c%n3+n3)%n3;
    return true;
}

ll Chinese_Remainder(int len, ll* a, ll* n)
{
    ll a1=a[0],n1=n[0];
    ll a2,n2;
    for(int i = 1; i < len; i++)
    {
        ll aa,nn;
        a2 = a[i],n2=n[i];
        if(!merge(a1,n1,a2,n2,aa,nn))
            return -1;
        a1 = aa;
        n1 = nn;
    }
    Mod = n1;
    return (a1%n1+n1)%n1;
}
ll lcm(ll a,ll b) {
  return a*b/gcd(a,b);
}
ll helper(ll k,ll a,ll b) {
  if(a>b)
    return 0;
  ll lft=a/k;if(a>0&&a%k)++lft;
  ll rgt=b/k;if(b<0&&b%k)--rgt;
  return rgt-lft+1;
}
int main() {
  ll a[2],n[2],L,R;
  scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &n[0],&a[0],&n[1],&a[1],&L,&R);
  ll x=Chinese_Remainder(2,a,n);
  if(x==-1)
    cout<<0<<endl;
  else {
    ll M=lcm(n[0],n[1]);
  //  cout<<"y="<<x<<'+'<<M<<"*m"<<endl;
    ll L2=max(max(L,a[0]),a[1]);
    //cout<<L2<<endl;
    ll start=L2-x;
    ll end=R-x;
  //  cout<<"["<<start<<","<<end<<"]"<<endl;
    ll ans=helper(M,start,end);
    cout<<ans<<endl;
  }
}
