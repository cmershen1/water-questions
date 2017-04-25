#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ans=0;
  scanf("%d", &n);
  while(n--) {
    int a,b;
    scanf("%d %d",&a,&b);
    if(a>b)
      ans++;
    else if(a<b)
      ans--;
  }
  if(ans>0)
    printf("MishKa\n");
  else if(ans<0)
    printf("Chris\n");
  else
    printf("Friendship is magic!^^\n");
}
