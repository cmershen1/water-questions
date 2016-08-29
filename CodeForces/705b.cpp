#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,a,ans=0;
  scanf("%d",&n);
  scanf("%d",&a);
  if(a&1)
    ans=2;
  else
    ans=1;
  printf("%d\n", ans);
  n--;
  while(n--) {
    scanf("%d",&a);
    if(!(a&1))
      ans=(ans==1)?2:1;

    printf("%d\n", ans);
  }
}
