#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,d;
  char s[100];
  int ans=0,beat=0;
  scanf("%d %d", &n,&d);
  while(d--) {
    scanf("%s", s);
    int all1=1;
    for(int i=0;i<n;i++) {
      if(s[i]=='0')
        all1=0;
    }
    if(!all1) {
      beat++;
      if(beat>ans)
        ans=beat;
    }
    else {
      if(beat>ans)
        ans=beat;
      beat=0;
    }
  }
  printf("%d\n", ans);
}
