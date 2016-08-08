#include <bits/stdc++.h>
using namespace std;
int main() {
  char c[15];
  int before,after,n,ans=0;
  scanf("%d", &n);
  while(n--) {
    scanf("%s %d %d", c,&before,&after);
    if(before>=2400 && after>before) {
      ans=1;
      //break;
    }
  }
  if(ans)
    printf("YES\n");
  else
    printf("NO");
}
