#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
  ll a;
  scanf("%I64d", &a);
  if(a<3)
    printf("-1\n");
  else {
    if(a&1)
      printf("%I64d %I64d\n",(a*a-1)/2, (a*a+1)/2);
    else
      printf("%I64d %I64d\n", a*a/4-1, a*a/4+1);
  }
}
