#include <bits/stdc++.h>
#define INFINITE 0x7fffffff
typedef long long ll;
int main() {
  int n,m,min=INFINITE;
  ll sum=0;
  scanf("%d", &n);
  while(n--) {
    scanf("%d", &m);
    if(m%2 && m<min)
      min=m;
    sum+=m;
  }
  if(sum%2)
    sum-=min;
  printf("%I64d\n", sum);
  return 0;
}
