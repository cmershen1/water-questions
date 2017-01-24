#include <bits/stdc++.h>
using namespace std;
int main() {
  int t,s,x;
  scanf("%d %d %d",&t,&s,&x);
  if((x-t>=0)&&(x-t)%s==0)
    printf("YES\n");
  else if((x-t-s-1>=0)&&(x-t-s-1)%s==0)
    printf("YES\n");
  else
    printf("NO\n");
}
