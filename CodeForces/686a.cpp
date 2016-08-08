#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,d;ll x;char c;
    scanf("%d %I64d", &n,&x);
    ll a=x;int b=0;
    while(n--) {
      cin>>c>>d;

      if(c=='+')
        a+=d;
      if(c=='-') {
        if(a>=d)
          a-=d;
        else
          b++;
      }
    }
    printf("%I64d %d\n", a,b);
}
