#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a%b);  }//最大公约数
ll lcm(ll a, ll b){ return a * b / gcd(a, b);  }//最小公倍数
int main() {
  int n,j,c;ll k,ans=1;
  scanf("%d %I64d",&n,&k);
  for(int i=0;i<n;i++) {
    scanf("%d",&c);
    ans=lcm(c,ans)%k;
  }

  if(ans)
    printf("No\n");
   else
    printf("Yes\n");
}
