#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
ll qpow(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res * a %M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
int main() {
  int n;
  scanf("%d", &n);
  ll num,t=2,flag=-1;
  while(n--) {
    scanf("%I64d", &num);
    t=qpow(t,num);
    if(num%2==0) //有一个是偶数，则最后乘起来的n就是偶数
      flag=1;
  }
  ll y=t*500000004%M;
  ll x=(333333336*(y+flag))%M;

  printf("%I64d/%I64d\n",x,y);
}
